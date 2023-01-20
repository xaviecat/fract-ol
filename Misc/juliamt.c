/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliamt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:42:57 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/16 13:42:12 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

# include <pthread.h>
typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}			t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_mlxsetup
{
	t_vars	lnk;
	t_img	img;
}			t_mlxsetup;
typedef struct s_coor
{
	double	x;
	double	y;
}			t_coor;

typedef struct s_cplx
{
	t_coor		z;
	t_coor		c;
	t_coor		tmp;
	double		r;
	double		imax;
	t_mlxsetup	set;
}				t_cplx;

typedef struct s_thread
{
	t_cplx		*cplx;
	size_t		i;
	t_coor		px;
	t_coor		z;
	t_coor		tmp;
	pthread_t	thread;
}			t_thread;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	init_set(t_mlxsetup *set);

double	zmod2(t_coor *pixels);

void	julia_init(t_cplx *julia, t_mlxsetup *set);
void	julia_z_incr(t_thread *julia);
void	julia_iter(t_thread *julia);
void	julia_set(t_cplx *julia);
void	julia_calc(t_thread *julia);
void	julia_display(t_mlxsetup *set, t_cplx *julia);

void	hooks(t_cplx *julia);
int		process_key(int keycode, t_cplx	*julia);
int		clear_close_exit(t_cplx *julia);
/* ========================================================================= */

void	julia_init(t_cplx *julia, t_mlxsetup *set)
{
	julia->z.x = 0;
	julia->z.y = 0;
	julia->c.x = -0.4;
	julia->c.y = 0.6;
	julia->r = 2;
	julia->imax = 50;
	julia->set = *set;
}

void	julia_z_incr(t_thread *julia)
{
	julia->z.x = ((julia->px.x / (WIDTH / (julia->cplx->r * 2)) - \
	julia->cplx->r) \
	* WIDTH / HEIGHT);
	julia->z.y = (julia->cplx->r - (julia->px.y / (HEIGHT / \
	(julia->cplx->r * 2))));
}

void	julia_iter(t_thread *julia)
{
	julia->tmp.x = pow(julia->z.x, 2) - pow(julia->z.y, 2) + julia->cplx->c.x;
	julia->z.y = 2 * julia->z.x * julia->z.y + julia->cplx->c.y;
	julia->z.x = julia->tmp.x;
}

void	julia_set(t_cplx *julia)
{
	t_thread	t[8];
	size_t		i;

	i = 0;
	while (i < 8)
	{
		t[i].cplx = julia;
		t[i].i = i;
		t[i].z.x = 0;
		t[i].z.y = 0;
		pthread_create(&t[i].thread, NULL, (void *)julia_calc, &t[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(t[i].thread, NULL);
		i++;
	}
}

void	julia_seq(t_thread	*julia)
{
	size_t	i;

	julia->z.x = ((julia->px.x / (WIDTH / (julia->cplx->r * 2)) - \
	julia->cplx->r) * WIDTH / HEIGHT);
	julia->z.y = (julia->cplx->r - (julia->px.y / (HEIGHT / \
	(julia->cplx->r * 2))));
	i = 1;
	while (zmod2(&julia->z) < 4. && i < julia->cplx->imax && i++)
	{
		julia->tmp.x = pow(julia->z.x, 2) - pow(julia->z.y, 2) + \
		julia->cplx->c.x;
		julia->z.y = 2 * julia->z.x * julia->z.y + julia->cplx->c.y;
		julia->z.x = julia->tmp.x;
	}
	if (i == julia->cplx->imax)
		my_mlx_pixel_put(&julia->cplx->set.img, julia->px.x, julia->px.y, \
		0x00FFFFFF);
	else
		my_mlx_pixel_put(&julia->cplx->set.img, julia->px.x, julia->px.y, \
		0x00a2dcc7 * i / 10000);
}

void	julia_calc(t_thread *julia)
{
	julia->px.x = WIDTH / 8 * (julia->i);
	while (julia->px.x < WIDTH / 8 * (julia->i + 1))
	{
		julia->px.y = 0;
		while (julia->px.y < HEIGHT)
		{
			julia_seq(julia);
			julia->px.y++;
		}
		julia->px.x++;
	}
}

void	julia_display(t_mlxsetup *set, t_cplx *julia)
{
	julia_init(julia, set);
	julia_set(julia);
	mlx_put_image_to_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win, \
	julia->set.img.img, 0, 0);
	hooks(julia);
}
