/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:24 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/09 17:59:02 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	zmod2(t_complex *pixels)
{
	return (pow(pixels->x, 2) + pow(pixels->y, 2));
}

double	xjulia(t_complex *pixels, double cx)
{
	return (pow(pixels->x, 2) - pow(pixels->y, 2) + cx);
}

double	yjulia(t_complex *pixels, double cy)
{
	return (2 * pixels->x * pixels->y + cy);
}

void	julia_set(t_img *img)
{
	t_complex	pix;
	t_complex	z;
	t_complex	c;
	size_t		i;
	double		range;

	pix.x = 0;
	c.x = -0.4;
	c.y = 0.6;
	range = 1.5;
	while (pix.x < WIDTH)
	{
		pix.y = 0;
		while (pix.y < HEIGHT)
		{
			z.x = ((pix.x / (WIDTH / (range * 2))) - range) * WIDTH / HEIGHT;
			z.y = range - (pix.y / (HEIGHT / (range * 2)));
			i = 0;
			while (zmod2(&z) < 4. && i < IMAX)
			{
				z.xtemp = xjulia(&z, c.x);
				z.y = yjulia(&z, c.y);
				z.x = z.xtemp;
				i++;
			}
			if (i == IMAX)
				my_mlx_pixel_put(img, pix.x, pix.y, 0x0068c2d3);
			else
				my_mlx_pixel_put(img, pix.x, pix.y, 0x00a2dcc7 * i / 10000);
			pix.y++;
		}
		pix.x++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "fract-ol");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	julia_set(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
