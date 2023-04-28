/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:58 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 16:47:10 by xcharra          ###   ########.fr       */
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
