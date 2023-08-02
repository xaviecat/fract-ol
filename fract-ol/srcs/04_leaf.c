/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:47:22 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 17:13:51 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaf_init(t_cplx *leaf, t_mlxsetup *set)
{
	leaf->name = LEAF;
	leaf->sname = SLEAF;
	leaf->px.x = 0;
	leaf->px.y = 0;
	leaf->z.x = 0;
	leaf->z.y = 0;
	leaf->r = 2;
	leaf->imax = 100;
	leaf->zoom = 1;
	leaf->move.x = 0;
	leaf->move.y = 0;
	leaf->set = *set;
	leaf->pow = 2;
	leaf->imgprt = &leaf->set.img;
	leaf->imgdsp = &leaf->set.img2;
	leaf->selector = 0;
}

void	leaf_z_incr(t_cplx *leaf)
{
	leaf->z.x = ((2 * leaf->r * leaf->px.x / WIDTH - leaf->r) * \
	leaf->zoom * RATIO + leaf->move.x);
	leaf->z.y = ((leaf->r - 2 * leaf->r * leaf->px.y / HEIGHT) * \
	leaf->zoom + leaf->move.y);
	leaf->c.x = ((2 * leaf->r * leaf->px.x / WIDTH - leaf->r) * \
	leaf->zoom * RATIO + leaf->move.x);
	leaf->c.y = ((leaf->r - 2 * leaf->r * leaf->px.y / HEIGHT) * \
	leaf->zoom + leaf->move.y);
}

void	leaf_iter(t_cplx *leaf)
{
	leaf->tmp.x = rcplxcos(leaf->z, leaf->c);
	leaf->z.y = icplxcos(leaf->z, leaf->c);
	leaf->z.x = leaf->tmp.x;
}

void	leaf_set(t_cplx *leaf)
{
	size_t	i;

	leaf->px.x = 0;
	while (leaf->px.x < WIDTH)
	{
		leaf->px.y = 0;
		while (leaf->px.y < HEIGHT)
		{
			leaf_z_incr(leaf);
			i = 1;
			while (zmod2(&leaf->z) < 4. && i < leaf->imax && i++)
				leaf_iter(leaf);
			if (i == leaf->imax)
				my_mlx_pixel_put(leaf->imgprt, leaf->px.x, leaf->px.y, \
				0x00FFFFFF);
			else
				color_pixels(leaf, i);
			leaf->px.y++;
		}
		leaf->px.x++;
	}
	switchimg(leaf);
}

void	leaf_display(t_mlxsetup *set, t_cplx *fractal)
{
	leaf_init(fractal, set);
	leaf_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	hooks(fractal);
}
