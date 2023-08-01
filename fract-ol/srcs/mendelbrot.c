/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:47:22 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/01 15:50:37 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_init(t_cplx *mandel, t_mlxsetup *set)
{
	mandel->name = MANDEL;
	mandel->sname = SMANDEL;
	mandel->px.x = 0;
	mandel->px.y = 0;
	mandel->z.x = 0;
	mandel->z.y = 0;
	mandel->r = 2;
	mandel->imax = 100;
	mandel->zoom = 1;
	mandel->move.x = 0;
	mandel->move.y = 0;
	mandel->set = *set;
	mandel->pow = 2;
	mandel->imgprt = &mandel->set.img;
	mandel->imgdsp = &mandel->set.img2;
	mandel->selector = 0;
}

void	mandel_z_incr(t_cplx *mandel)
{
	mandel->z.x = 0;
	mandel->z.y = 0;
	mandel->c.x = ((2 * mandel->r * mandel->px.x / WIDTH - mandel->r) * \
	mandel->zoom * RATIO + mandel->move.x);
	mandel->c.y = ((mandel->r - 2 * mandel->r * mandel->px.y / HEIGHT) * \
	mandel->zoom + mandel->move.y);
}

void	mandel_iter(t_cplx *mandel)
{
	if (mandel->nstate % 2 == 0)
	{
		mandel->tmp.x = rcplxpow1to5(mandel->z, mandel->pow) + mandel->c.x;
		mandel->z.y = icplxpow1to5(mandel->z, mandel->pow) + mandel->c.y;
		mandel->z.x = mandel->tmp.x;
	}
	else if (mandel->nstate % 2 == 1)
	{
		mandel->tmp.x = rcplxpow1to5(mandel->z, mandel->pow) + mandel->c.x
			/ (ft_pow(mandel->c.x, 2) + ft_pow(mandel->c.y, 2));
		mandel->z.y = icplxpow1to5(mandel->z, mandel->pow) + mandel->c.y
			/ (ft_pow(mandel->c.x, 2) + ft_pow(mandel->c.y, 2));
		mandel->z.x = mandel->tmp.x;
	}
}

void	mandel_set(t_cplx *mandel)
{
	size_t	i;

	mandel->px.x = 0;
	while (mandel->px.x < WIDTH)
	{
		mandel->px.y = 0;
		while (mandel->px.y < HEIGHT)
		{
			mandel_z_incr(mandel);
			i = 1;
			while (zmod2(&mandel->z) < 4. && i < mandel->imax && i++)
				mandel_iter(mandel);
			if (i == mandel->imax)
				color_pixels(mandel, i);
//				my_mlx_pixel_put(mandel->imgprt, mandel->px.x, mandel->px.y, \
//				0x00FFFFFF);
			else
				color_pixels(mandel, i);

//				my_mlx_pixel_put(mandel->imgprt, mandel->px.x, mandel->px.y, \
//				0x00a2dcc7 * i / 10000);
			mandel->px.y++;
		}
		mandel->px.x++;
	}
	switchimg(mandel);
}

void	mandel_display(t_mlxsetup *set, t_cplx *fractal)
{
	mandel_init(fractal, set);
	mandel_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	hooks(fractal);
}
