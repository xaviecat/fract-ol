/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:58 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 17:33:39 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pixels(t_cplx *fractal, size_t i)
{
	unsigned int	color;
	double			n_color;

	color = i * 256 / fractal->imax;
	n_color = 0;
	n_color = fractal->color_drv + (0 << 24 | (0) << 16 | (0) << 8 | (0));
	n_color = fractal->color_drv + (((0 << 24) & 0xFF) | (((color) << 16) & \
	0xFF) | (((color) << 8) & 0xFF) | (((color) & 0xFF)));
	my_mlx_pixel_put(fractal->imgprt, fractal->px.x, fractal->px.y, n_color);
}

void	newton_colors(int i, t_cplx *newton)
{
	if (i == newton->imax)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00FF0000);
	else if (newton->z.x <= newton->tol * -1)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00ABBDFF + (i << 8));
	else if (newton->z.x >= newton->tol * 1 && newton->z.y > 0)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00894B77 + (i << 8));
	else if (newton->z.x >= newton->tol * 1 && newton->z.y < 0)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x0099e1d9 + (i << 8));
	else
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00a2dcc7 * i / 1000000);
}
