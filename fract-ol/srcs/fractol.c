/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:24 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/11 17:58:34 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	zmod2(t_coor *pixels);
void	julia_init(t_cplx *julia, t_mlxsetup *set);
void	julia_z_incr(t_cplx *julia);
void	julia_iter(t_cplx *julia);
int		process_key(int keycode, void *julia);
void	julia_set(t_cplx *julia);
void	init_set(t_mlxsetup *set);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > WIDTH || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	zmod2(t_coor *pixels)
{
	return (pow(pixels->x, 2) + pow(pixels->y, 2));
}

void	julia_init(t_cplx *julia, t_mlxsetup *set)
{
	julia->px.x = 0;
	julia->px.y = 0;
	julia->c.x = -0.4;
	julia->c.y = 0.6;
	julia->r = 2;
	julia->set = *set;
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

int	process_key(int keycode, void *param)
{
	t_cplx	*julia;

	julia = (t_cplx *)param;
	printf("p %f, %f\n", julia->c.x, julia->c.y);
	if (keycode == 53)
	{
		// mlx_clear_window(merg->setup->lnk.mlx, merg->setup->lnk.mlx_win);
		// mlx_destroy_window(merg->setup->lnk.mlx, merg->setup->lnk.mlx_win);
		exit(EXIT_SUCCESS);
		return (0);
	}
	else if (keycode == 126)
	{
		printf("%f\n", julia->c.y);
		julia->c.y += 0.01;
		printf("%f\n", julia->c.y);
		julia_set(julia);
	}
	else
		ft_printf("Key : %d\n", keycode);
	//julia_set(&merg->setup->img, *merg->setup);
	return (0);
}

void	julia_set(t_cplx *julia)
{
	size_t	i;

	printf("j %f, %f\n", julia->c.x, julia->c.y);
	while (julia->px.x < WIDTH)
	{
		julia->px.y = 0;
		while (julia->px.y < HEIGHT)
		{
			julia_z_incr(julia);
			i = 1;
			while (zmod2(&julia->z) < 4. && i < IMAX && i++)
				julia_iter(julia);
			if (i == IMAX)
				my_mlx_pixel_put(&julia->set.img, julia->px.x, julia->px.y, 0x0068c2d3);
			else
				my_mlx_pixel_put(&julia->set.img, julia->px.x, julia->px.y, 0x00a2dcc7 * i / 10000);
			julia->px.y++;
		}
		julia->px.x++;
	}
	printf("je %f, %f\n", julia->c.x, julia->c.y);
}

void	init_set(t_mlxsetup *set)
{
	set->lnk.mlx = mlx_init();
	set->lnk.mlx_win = mlx_new_window(set->lnk.mlx, WIDTH, HEIGHT, "fract-ol");
	// !printf("%p\n", set->lnk.mlx_win);
	set->img.img = mlx_new_image(set->lnk.mlx, WIDTH, HEIGHT);
	set->img.addr = mlx_get_data_addr(set->img.img, \
	&set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
}

void	display_julia(t_mlxsetup *set)
{
	t_cplx	julia;

	julia_init(&julia, set);
	julia_set(&julia);
	printf("%f, %f, %p\n", julia.c.x, julia.c.y, julia.set.lnk.mlx_win);
	mlx_hook(julia.set.lnk.mlx_win, ON_KEYDOWN, 0L, &process_key, &julia);
	printf("%f, %f, %p\n", julia.c.x, julia.c.y, julia.set.lnk.mlx_win);
	mlx_put_image_to_window(set->lnk.mlx, set->lnk.mlx_win, set->img.img, 0, 0);
}

int	main(void)
{
	t_mlxsetup	set;

	init_set(&set);
	display_julia(&set);
	// mlx_hook(set.lnk.mlx_win, ON_KEYDOWN, 0, process_key, &set.lnk);
	// mlx_key_hook(set.lnk.mlx_win, test, &set.lnk);
	mlx_loop(set.lnk.mlx);
}
