/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:42:07 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/12 16:42:15 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_set(t_mlxsetup *set)
{
	set->lnk.mlx = mlx_init();
	set->lnk.mlx_win = mlx_new_window(set->lnk.mlx, WIDTH, HEIGHT, "fract-ol");
	set->img.img = mlx_new_image(set->lnk.mlx, WIDTH, HEIGHT);
	set->img.addr = mlx_get_data_addr(set->img.img, \
	&set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	//! if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
	//! 	return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	clear_close_exit(t_cplx *julia)
{
	mlx_clear_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win);
	mlx_destroy_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
