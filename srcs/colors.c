/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:58 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/02 13:15:43 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	smooth_color(size_t i, size_t i_max, unsigned int color)
{
	double		t;
	int			decomp_color[4];
	int			final_color[4];

	t = log((double)i) / log(i_max);
	decomp_color[ALP] = (color >> 24) & 0xFF;
	decomp_color[RED] = (color >> 16) & 0xFF;
	decomp_color[GRE] = (color >> 8) & 0xFF;
	decomp_color[BLU] = color & 0xFF;
	final_color[ALP] = (int)(decomp_color[ALP] + (255 - decomp_color[ALP]) * t);
	final_color[RED] = (int)(decomp_color[RED] + (255 - decomp_color[RED]) * t);
	final_color[GRE] = (int)(decomp_color[GRE] + (255 - decomp_color[GRE]) * t);
	final_color[BLU] = (int)(decomp_color[BLU] + (255 - decomp_color[BLU]) * t);
	return ((final_color[ALP] << 24) | (final_color[RED] << 16)
		| (final_color[GRE] << 8) | final_color[BLU]);
}

void	color_pixels(t_cplx *fractal, size_t i)
{
	static unsigned int	color_palette[10] = {0x0000042b, 0x00786b84,
		0x00a2dcc7, 0x004b9a76, 0x00ca1b4c, 0x004e5f65,
		0x008c595a, 0x00888da7, 0x0067597a, 0x000276A6};

	my_mlx_pixel_put(fractal->imgprt, fractal->px.x, fractal->px.y,
		smooth_color(i, fractal->imax, color_palette[fractal->selector]));
}

void	newton_colors(size_t i, t_cplx *newton)
{
	if (i == newton->imax)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00FF0000);
	else if (newton->z.x <= newton->tol * -1)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00fae6cd + (i << 8));
	else if (newton->z.x >= newton->tol * 1 && newton->z.y > 0)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00f3c0ce + (i << 8));
	else if (newton->z.x >= newton->tol * 1 && newton->z.y < 0)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00979bc7 + (i << 8));
	else
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
		0x00a2dcc7 * i / 1000000);
}
