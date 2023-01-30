/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:47:22 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/30 14:40:59 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_init(t_cplx *burning, t_mlxsetup *set)
{
	burning->name = BURNING;
	burning->sname = SBURNING;
	burning->px.x = 0;
	burning->px.y = 0;
	burning->z.x = 0;
	burning->z.y = 0;
	burning->r = 2;
	burning->imax = 100;
	burning->zoom = 1;
	burning->move.x = 0;
	burning->move.y = 0;
	burning->set = *set;
	burning->pow = 2;
	burning->imgprt = &burning->set.img;
	burning->imgdsp = &burning->set.img2;
}

void	burning_z_incr(t_cplx *burning)
{
	burning->z.x = ((2 * burning->r * burning->px.x / WIDTH - burning->r) \
	* burning->zoom * RATIO + burning->move.x);
	burning->z.y = ((burning->r - 2 * burning->r * burning->px.y / HEIGHT) \
	* burning->zoom + burning->move.y);
	burning->c.x = ((2 * burning->r * burning->px.x / WIDTH - burning->r) \
	* burning->zoom * RATIO + burning->move.x);
	burning->c.y = ((burning->r - 2 * burning->r * burning->px.y / HEIGHT) \
	* burning->zoom + burning->move.y);
}

void	burning_iter(t_cplx *burning)
{
	burning->tmp.x = rcplxpow(burning->z, burning->pow) + burning->c.x;
	burning->z.y = fabs(icplxpow(burning->z, burning->pow)) - burning->c.y;
	burning->z.x = burning->tmp.x;
}

void	burning_ship(t_cplx *burning)
{
	size_t	i;

	burning->px.x = 0;
	while (burning->px.x < WIDTH)
	{
		burning->px.y = 0;
		while (burning->px.y < HEIGHT)
		{
			burning_z_incr(burning);
			i = 1;
			while (zmod2(&burning->z) < 4. && i < burning->imax && i++)
				burning_iter(burning);
			if (i == burning->imax)
				my_mlx_pixel_put(burning->imgprt, burning->px.x, burning->px.y, \
				0x00FFFFFF);
			else
				my_mlx_pixel_put(burning->imgprt, burning->px.x, burning->px.y, \
				0x00a2dcc7 * i / 10000);
			burning->px.y++;
		}
		burning->px.x++;
	}
	switchimg(burning);
}

void	burning_display(t_mlxsetup *set, t_cplx *fractal)
{
	burning_init(fractal, set);
	burning_ship(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	hooks(fractal);
}
