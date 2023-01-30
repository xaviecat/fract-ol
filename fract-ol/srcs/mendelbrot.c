/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:47:22 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/30 16:17:22 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mendel_init(t_cplx *mendel, t_mlxsetup *set)
{
	mendel->name = MENDEL;
	mendel->sname = SMENDEL;
	mendel->px.x = 0;
	mendel->px.y = 0;
	mendel->z.x = 0;
	mendel->z.y = 0;
	mendel->r = 2;
	mendel->imax = 100;
	mendel->zoom = 1;
	mendel->move.x = 0;
	mendel->move.y = 0;
	mendel->set = *set;
	mendel->pow = 2;
	mendel->imgprt = &mendel->set.img;
	mendel->imgdsp = &mendel->set.img2;
}

void	mendel_z_incr(t_cplx *mendel)
{
	mendel->z.x = 0;
	mendel->z.y = 0;
	mendel->c.x = ((2 * mendel->r * mendel->px.x / WIDTH - mendel->r) * \
	mendel->zoom * RATIO + mendel->move.x);
	mendel->c.y = ((mendel->r - 2 * mendel->r * mendel->px.y / HEIGHT) * \
	mendel->zoom + mendel->move.y);
}

void	mendel_iter(t_cplx *mendel)
{
	mendel->tmp.x = rcplxpow(mendel->z, mendel->pow) + mendel->c.x/*  / (ft_pow(mendel->c.x, 2) + ft_pow(mendel->c.y ,2)) */;
	mendel->z.y = icplxpow(mendel->z, mendel->pow) + mendel->c.y/*  / (ft_pow(mendel->c.x, 2) + ft_pow(mendel->c.y ,2)) */;
	mendel->z.x = mendel->tmp.x;
}

void	mendel_set(t_cplx *mendel)
{
	size_t	i;

	mendel->px.x = 0;
	while (mendel->px.x < WIDTH)
	{
		mendel->px.y = 0;
		while (mendel->px.y < HEIGHT)
		{
			mendel_z_incr(mendel);
			i = 1;
			while (zmod2(&mendel->z) < 4. && i < mendel->imax && i++)
				mendel_iter(mendel);
			if (i == mendel->imax)
				my_mlx_pixel_put(mendel->imgprt, mendel->px.x, mendel->px.y, \
				0x00FFFFFF);
			else
				my_mlx_pixel_put(mendel->imgprt, mendel->px.x, mendel->px.y, \
				0x00a2dcc7 * i / 10000);
			mendel->px.y++;
		}
		mendel->px.x++;
	}
	switchimg(mendel);
}

void	mendel_display(t_mlxsetup *set, t_cplx *fractal)
{
	mendel_init(fractal, set);
	mendel_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	hooks(fractal);
}
