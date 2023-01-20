typedef struct s_complex
{
	double	x;
	double	xtemp;
	double	y;
}			t_complex;


double	xjulia(t_coor *z, double cx)
{
	return (pow(z->x, 2) - pow(z->y, 2) + cx);
}

double	yjulia(t_coor *z, double cy)
{
	return (2 * z->x * z->y + cy);
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:30 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/12 17:40:11 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_cplx *julia, t_mlxsetup *set)
{
	julia->px.x = 0;
	julia->px.y = 0;
	julia->c.x = -0.4;
	julia->c.y = 0.6;
	julia->r = 2;
	julia->imax = 100;
	julia->set = *set;
	julia->imgprt = &julia->set.img;
	julia->imgdsp = &julia->set.img2;
}

void	julia_z_incr(t_cplx *julia)
{
	julia->z.x = ((julia->px.x / (WIDTH / (julia->r * 2)) - julia->r) \
	* WIDTH / HEIGHT);
	julia->z.y = (julia->r - (julia->px.y / (HEIGHT / (julia->r * 2))));
}

void	julia_iter(t_cplx *julia)
{
	julia->tmp.x = pow(julia->z.x, 2) - pow(julia->z.y, 2) + julia->c.x;
	julia->z.y = 2 * julia->z.x * julia->z.y + julia->c.y;
	julia->z.x = julia->tmp.x;
}

void	switchimg(t_cplx *julia)
{
	julia->imgtmp = julia->imgprt;
	julia->imgprt = julia->imgdsp;
	julia->imgdsp = julia->imgtmp;
}

void	julia_set(t_cplx *julia)
{
	size_t	i;

	julia->px.x = 0;
	while (julia->px.x < WIDTH)
	{
		julia->px.y = 0;
		while (julia->px.y < HEIGHT)
		{
			julia_z_incr(julia);
			i = 1;
			while (zmod2(&julia->z) < 4. && i < julia->imax && i++)
				julia_iter(julia);
			if (i == julia->imax)
				my_mlx_pixel_put(julia->imgprt, julia->px.x, julia->px.y, \
				0x00FFFFFF);
			else
				my_mlx_pixel_put(julia->imgprt, julia->px.x, julia->px.y, \
				0x00a2dcc7 * i / 10000);
			julia->px.y++;
		}
		julia->px.x++;
	}
	switchimg(julia);
}

void	julia_display(t_mlxsetup *set, t_cplx *julia)
{
	julia_init(julia, set);
	julia_set(julia);
	mlx_put_image_to_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win, \
	julia->imgdsp->img, 0, 0);
	hooks(julia);
}

	t_img		*imgprt;
	t_img		*imgdsp;
	t_img		*imgtmp;
