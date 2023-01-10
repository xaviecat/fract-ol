/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:24 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/10 18:24:45 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/*
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
*/
void	axes(t_img *img)
{
	size_t	i = 0;
	size_t	j = 0;

	while (i < WIDTH)
	{
		my_mlx_pixel_put(img, i, HEIGHT / 2, 0x00FF0000);
		my_mlx_pixel_put(img, i, HEIGHT / 4, 0x00FF0000);
		my_mlx_pixel_put(img, i, HEIGHT * 3 / 4, 0x00FF0000);
		i++;
	}
	while (j < HEIGHT)
	{
		my_mlx_pixel_put(img, WIDTH / 2, j, 0x00FF0000);
		my_mlx_pixel_put(img, WIDTH / 4, j, 0x00FF0000);
		my_mlx_pixel_put(img, WIDTH * 3 / 4, j, 0x00FF0000);
		j++;
	}
}
/*
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
	range = 2;
	while (pix.x < WIDTH)
	{
		pix.y = 0;
		while (pix.y < HEIGHT)
		{
			z.x = (((pix.x / (WIDTH / (range * 2))) - range) * WIDTH / HEIGHT);
			z.y = (range - (pix.y / (HEIGHT / (range * 2))));
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
	// !axes(img);
} */

double	zmod2(t_coor *pixels)
{
	return (pow(pixels->x, 2) + pow(pixels->y, 2));
}

double	xjulia(t_coor *pixels, double cx)
{
	return (pow(pixels->x, 2) - pow(pixels->y, 2) + cx);
}

double	yjulia(t_coor *pixels, double cy)
{
	return (2 * pixels->x * pixels->y + cy);
}

t_cplx	julia_init(void)
{
	t_cplx	julia;

	julia.pixel.x = 0;
	julia.z.x = 0;
	julia.z.y = 0;
	julia.c.x = -0.4;
	julia.c.y = 0.6;
	return (julia);
}

void	julia_set(t_img *img)
{
	t_cplx	julia;
	double	range;
	size_t	i;

	julia = julia_init();
	range = 2;
	i = 0;
	while (julia.pixel.x < WIDTH)
	{
		julia.pixel.y = 0;
		while (julia.pixel.y < HEIGHT)
		{
			julia.z.x = (((julia.pixel.x / (WIDTH / (range * 2))) - range) * WIDTH / HEIGHT);
			julia.z.y = (range - (julia.pixel.y / (HEIGHT / (range * 2))));
			i = 0;
			while (zmod2(&julia.z) < 4. && i < IMAX)
			{
				julia.tmp.x = xjulia(&julia.z, julia.c.x);
				julia.z.y = yjulia(&julia.z, julia.c.x);
				julia.z.x = julia.tmp.x;
				i++;
			}
			if (i == IMAX)
				my_mlx_pixel_put(img, julia.pixel.x, julia.pixel.y, 0x0068c2d3);
			else
				my_mlx_pixel_put(img, julia.pixel.x, julia.pixel.y, 0x00a2dcc7 * i / 10000);
			julia.pixel.y++;
		}
		julia.pixel.x++;
	}
	axes(img);
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
