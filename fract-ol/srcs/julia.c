/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:30 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/30 16:58:24 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_cplx *julia, t_mlxsetup *set)
{
	julia->name = JULIA;
	julia->sname = SJULIA;
	julia->color_derv = 0x00a2dcc7;
	julia->px.x = 0;
	julia->px.y = 0;
	julia->z.x = 0;
	julia->z.y = 0;
	julia->c.x = -0.4;/* 0.25; //-1; */
	julia->c.y = 0.6;/* 0; */
	julia->r = 2;
	julia->imax = 100;
	julia->zoom = 1;
	julia->move.x = 0;
	julia->move.y = 0;
	julia->set = *set;
	julia->pow = 2;
	julia->imgprt = &julia->set.img;
	julia->imgdsp = &julia->set.img2;
}

void	julia_z_incr(t_cplx *julia)
{
	julia->z.x = ((2 * julia->r * julia->px.x / WIDTH - julia->r) * \
	julia->zoom * RATIO + julia->move.x);
	julia->z.y = ((julia->r - 2 * julia->r * julia->px.y / HEIGHT) * \
	julia->zoom + julia->move.y);
}

void	julia_iter(t_cplx *julia)
{
	julia->tmp.x = rcplxpow(julia->z, julia->pow) + julia->c.x;
	julia->z.y = icplxpow(julia->z, julia->pow) + julia->c.y;
	julia->z.x = julia->tmp.x;
}

void	julia_set(t_cplx *julia)
{
	size_t	i;

	julia->px.x = 0;
	while (julia->px.x < WIDTH)
	{
		julia->px.y = 0;
		while (julia->px.y < HEIGHT)
		{
			julia_z_incr(julia);
			i = 1;
			while (zmod2(&julia->z) < 4. && i < julia->imax && i++)
				julia_iter(julia);
			if (i == julia->imax)
				my_mlx_pixel_put(julia->imgprt, julia->px.x, julia->px.y, \
				0x00FFFFFF);
			else
				color_pixels(julia, i);
			julia->px.y++;
		}
		julia->px.x++;
	}
	switchimg(julia);
}

void	julia_display(t_mlxsetup *set, t_cplx *fractal)
{
	julia_init(fractal, set);
	julia_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
}
