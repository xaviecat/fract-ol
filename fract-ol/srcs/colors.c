/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:42:58 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/01 18:20:03 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//void	color_pixels(t_cplx *fractal, size_t i)
//{
//	static unsigned int	[10]color = {DARK_BLUE, };
//	double				n_color;
//
//	color[0] = i * 256 / fractal->imax;
//	n_color = 0;
//	n_color = fractal->color_drv + (0 << 24 | (0) << 16 | (0) << 8 | (0));
//	n_color = fractal->color_drv + (((0 << 24) & 0xFF) | (((color) << 16) & \
//	0xFF) | (((color) << 8) & 0xFF) | (((color) & 0xFF)));
//	my_mlx_pixel_put(fractal->imgprt, fractal->px.x, fractal->px.y, n_color);
//}
//
//void	newton_colors(int i, t_cplx *newton)
//{
//	if (i == newton->imax)
//		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
//		0x00FF0000);
//	else if (newton->z.x <= newton->tol * -1)
//		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
//		0x00ABBDFF + (i << 8));
//	else if (newton->z.x >= newton->tol * 1 && newton->z.y > 0)
//		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
//		0x00894B77 + (i << 8));
//	else if (newton->z.x >= newton->tol * 1 && newton->z.y < 0)
//		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
//		0x0099e1d9 + (i << 8));
//	else
//		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
//		0x00a2dcc7 * i / 1000000);
//}

unsigned int	smooth_color(size_t i, size_t i_max, unsigned int color)
{
	double t = (double)i / i_max;

	// Extraire les composantes RGBA de la couleur de la palette choisie pour le lissage
	unsigned int alpha_smoothed = (color >> 24) & 0xFF;
	unsigned int red_smoothed = (color >> 16) & 0xFF;
	unsigned int green_smoothed = (color >> 8) & 0xFF;
	unsigned int blue_smoothed = color & 0xFF;

	// Lissage des composantes RGBA avec la couleur de la palette choisie
	int alpha_final = (int)(t * alpha_smoothed);
	int red_final = (int)(t * red_smoothed);
	int green_final = (int)(t * green_smoothed);
	int blue_final = (int)(t * blue_smoothed);

	// Combinaison des composantes pour former la couleur lissée finale
	unsigned int smoothed_color = (alpha_final << 24) | (red_final << 16) | (green_final << 8) | blue_final;

	return smoothed_color;
}

void	color_pixels(t_cplx *fractal, size_t i)
{
	static unsigned int	color_palette[10] = {0x0000042b, 0x00786b84,
			0,0,0,0,0,0,0,0};
	unsigned int		color;

	color = smooth_color(i, fractal->imax, color_palette[fractal->selector]);
	my_mlx_pixel_put(fractal->imgprt, fractal->px.x, fractal->px.y, color);
}



void newton_colors(int i, t_cplx *newton)
{
	if (i == newton->imax)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, 0x00FF0000);
	else if (newton->z.x <= newton->tol * -1)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, 0x00ABBDFF + (i << 8));
	else if (newton->z.x >= newton->tol * 1 && newton->z.y > 0)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, 0x00894B77 + (i << 8));
	else if (newton->z.x >= newton->tol * 1 && newton->z.y < 0)
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, 0x0099e1d9 + (i << 8));
	else
		my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, 0x00a2dcc7 * i / 1000000);
}
//void color_pixels(t_cplx *fractal, size_t i)
//{
//	unsigned int	color;
//	double			n_color;
//
//	color = i * 256 / fractal->imax;
//	n_color = fractal->color_drv + ((color << 16) | (color << 8) | color);
//	my_mlx_pixel_put(fractal->imgprt, fractal->px.x, fractal->px.y, n_color);
//}
