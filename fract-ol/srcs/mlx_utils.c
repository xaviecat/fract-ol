/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:42:07 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 17:30:14 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_set(t_mlxsetup *set)
{
	set->lnk.mlx = mlx_init();
	if (!set->lnk.mlx)
	{
		ft_fdprintf(2, "error MLX init");
		exit(EXIT_FAILURE);
	}
	set->lnk.mlx_win = mlx_new_window(set->lnk.mlx, WIDTH, HEIGHT, "fract-ol");
	set->img.img = mlx_new_image(set->lnk.mlx, WIDTH, HEIGHT);
	set->img.addr = mlx_get_data_addr(set->img.img, \
	&set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	set->img2.img = mlx_new_image(set->lnk.mlx, WIDTH, HEIGHT);
	set->img2.addr = mlx_get_data_addr(set->img2.img, \
	&set->img2.bits_per_pixel, &set->img2.line_length, &set->img2.endian);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	clear_close_exit(t_cplx *fractal)
{
	mlx_clear_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win);
	mlx_destroy_image(fractal->set.lnk.mlx, fractal->set.img.img);
	mlx_destroy_image(fractal->set.lnk.mlx, fractal->set.img2.img);
	mlx_destroy_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win);
//	mlx_destroy_display(fractal->set.lnk.mlx);
	free(fractal->set.lnk.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	switchimg(t_cplx *fractal)
{
	fractal->imgtmp = fractal->imgprt;
	fractal->imgprt = fractal->imgdsp;
	fractal->imgdsp = fractal->imgtmp;
}
