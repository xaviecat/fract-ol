/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:47:22 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/23 11:33:30 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaft_init(t_cplx *leaft, t_mlxsetup *set)
{
	leaft->name = LEAFT;
	leaft->px.x = 0;
	leaft->px.y = 0;
	leaft->z.x = 0;
	leaft->z.y = 0;
	leaft->r = 2;
	leaft->imax = 100;
	leaft->zoom = 1;
	leaft->move.x = 0;
	leaft->move.y = 0;
	leaft->set = *set;
	leaft->pow = 2;
	leaft->imgprt = &leaft->set.img;
	leaft->imgdsp = &leaft->set.img2;
}

void	leaft_z_incr(t_cplx *leaft)
{
	leaft->z.x = ((2 * leaft->r * leaft->px.x / WIDTH - leaft->r) * \
	leaft->zoom * RATIO + leaft->move.x);
	leaft->z.y = ((leaft->r - 2 * leaft->r * leaft->px.y / HEIGHT) * \
	leaft->zoom + leaft->move.y);
	leaft->c.x = ((2 * leaft->r * leaft->px.x / WIDTH - leaft->r) * \
	leaft->zoom * RATIO + leaft->move.x);
	leaft->c.y = ((leaft->r - 2 * leaft->r * leaft->px.y / HEIGHT) * \
	leaft->zoom + leaft->move.y);
}

void	leaft_iter(t_cplx *leaft)
{
	leaft->tmp.x = rcplxsin(leaft->z, leaft->c);
	leaft->z.y = icplxsin(leaft->z, leaft->c);
	leaft->z.x = leaft->tmp.x;
}

void	leaft_set(t_cplx *leaft)
{
	size_t	i;

	leaft->px.x = 0;
	while (leaft->px.x < WIDTH)
	{
		leaft->px.y = 0;
		while (leaft->px.y < HEIGHT)
		{
			leaft_z_incr(leaft);
			i = 1;
			while (zmod2(&leaft->z) < 4. && i < leaft->imax && i++)
				leaft_iter(leaft);
			if (i == leaft->imax)
				my_mlx_pixel_put(leaft->imgprt, leaft->px.x, leaft->px.y, \
				0x00FFFFFF);
			else
				my_mlx_pixel_put(leaft->imgprt, leaft->px.x, leaft->px.y, \
				0x00a2dcc7 * i / 10000); //0x00a2dcc7 / i / 10000
			leaft->px.y++;
		}
		leaft->px.x++;
	}
	switchimg(leaft);
}

void	leaft_display(t_mlxsetup *set, t_cplx *fractal)
{
	leaft_init(fractal, set);
	leaft_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	hooks(fractal);
}
