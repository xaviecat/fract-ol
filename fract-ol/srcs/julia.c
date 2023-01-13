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
	julia->z.x = ((julia->px.x / (WIDTH / (julia->cplx->r * 2)) - julia->cplx->r) \
	* WIDTH / HEIGHT);
	julia->z.y = (julia->cplx->r - (julia->px.y / (HEIGHT / (julia->cplx->r * 2))));
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

	// mlx_put_image_to_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win, \
	// julia->imgprt->img, 0, 0);
}

void	julia_seq(t_thread	*julia)
{
	size_t	i;

	julia->z.x = ((julia->px.x / (WIDTH / (julia->cplx->r * 2)) - julia->cplx->r) \
	* WIDTH / HEIGHT);
	julia->z.y = (julia->cplx->r - (julia->px.y / (HEIGHT / (julia->cplx->r * 2))));
	i = 1;
	while (zmod2(&julia->z) < 4. && i < julia->cplx->imax && i++)
	{
		julia->tmp.x = pow(julia->z.x, 2) - pow(julia->z.y, 2) + julia->cplx->c.x;
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
