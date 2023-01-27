/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:15:52 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/27 11:56:48 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	nova_init(t_cplx *nova, t_mlxsetup *set)
{
	nova->name = NOVA;
	nova->sname = SNOVA;
	nova->px.x = 0;
	nova->px.y = 0;
	nova->z.x = 0;
	nova->z.y = 0;
	nova->c.x = 0;
	nova->c.y = 0;
	nova->q.x = 1;
	nova->q.y = 0;
	nova->a = 1;
	nova->d = -1;
	nova->r = 2;
	nova->tol = 0.001;
	nova->imax = 100;
	nova->zoom = 1;
	nova->move.x = 0;
	nova->move.y = 0;
	nova->set = *set;
	nova->imgprt = &nova->set.img;
	nova->imgdsp = &nova->set.img2;
}

void	nova_z_incr(t_cplx *nova)
{
	nova->z.x = ((2 * nova->r * nova->px.x / WIDTH - nova->r) * \
	nova->zoom * RATIO + nova->move.x);
	nova->z.y = ((nova->r - 2 * nova->r * nova->px.y / HEIGHT) * \
	nova->zoom + nova->move.y);
	// nova->c.x = 0/* ((2 * nova->r * nova->px.x / WIDTH - nova->r) * \
	// nova->zoom * RATIO + nova->move.x) */;
	// nova->c.y = 0/* ((nova->r - 2 * nova->r * nova->px.y / HEIGHT) * \
	// nova->zoom + nova->move.y) */;
}

void	nova_iter(t_cplx *nova)
{
	double	denom;

	nova->old.x = nova->z.x;
	nova->old.y = nova->z.y;
	denom = 3 * nova->a * ft_pow((ft_pow(nova->z.x, 2) + \
	ft_pow(nova->z.y, 2)), 2);
	nova->tmp.x = (nova->a * (ft_pow(nova->a, 2) * ft_pow(nova->z.x, 5) - \
	ft_pow(nova->a, 2) * ft_pow(nova->z.x, 3) * ft_pow(nova->z.y, 2)) + 3 * \
	nova->a * (-ft_pow(nova->z.x, 3) * ft_pow(nova->z.y, 2) + nova->z.x * \
	ft_pow(nova->z.y, 4) + 2 * nova->a * ft_pow(nova->z.x, 3) * \
	ft_pow(nova->z.y, 2)) + nova->d * ft_pow(nova->z.x, 2) - nova->d * \
	ft_pow(nova->z.y, 2) - 2 * nova->z.x * ft_pow(nova->z.y, 4)) / denom;
	nova->tmp.y = (-2 * ft_pow(nova->a, 3) * ft_pow(nova->z.x, 4) * nova->z.y \
	+ 3 * nova->a * (2 * ft_pow(nova->z.x, 2) * ft_pow(nova->z.y, 3) + nova->a \
	* ft_pow(nova->z.x, 4) * nova->z.y - nova->a * ft_pow(nova->z.x, 2) * \
	ft_pow(nova->z.y, 3)) - 2 * nova->d * nova->z.x * nova->z.y - \
	ft_pow(nova->z.x, 2) * ft_pow(nova->z.y, 3) + ft_pow(nova->z.y, 5)) / denom;
	nova->z.x = nova->z.x - nova->q.x * nova->tmp.x - nova->q.y * nova->tmp.y\
	 + nova->c.x;
	nova->z.y = nova->z.y - nova->q.x * nova->tmp.y + nova->q.y * nova->tmp.x\
	 + nova->c.y;
	nova->tmp.y = ft_pow(nova->z.x - nova->old.x, 2) + \
	ft_pow(nova->z.y - nova->old.y, 2);
}

void	nova_set(t_cplx *nova)
{
	size_t	i;

	nova->px.x = 0;
	while (nova->px.x < WIDTH)
	{
		nova->px.y = 0;
		while (nova->px.y < HEIGHT)
		{
			nova_z_incr(nova);
			i = 1;
			nova->tmp.y = 1;
			while (nova->tmp.y > nova->tol && i < nova->imax && i++)
				nova_iter(nova);
			if (i == nova->imax)
				my_mlx_pixel_put(nova->imgprt, nova->px.x, nova->px.y, \
				0x00000000);
			// else if (nova->z.x >= nova->tol * 1)
			// 	my_mlx_pixel_put(nova->imgprt, nova->px.x, nova->px.y, \
			// 	0x00ABBDFF + (i << 8)); //0x00a2dcc7 * i / 1000000
			// else if (nova->z.x <= nova->tol * -1 && nova->z.y > 0)
			// 	my_mlx_pixel_put(nova->imgprt, nova->px.x, nova->px.y, \
			// 	0x00894B77 + (i << 8)); //0x00a2dcc7 * i / 1000000
			// else if (nova->z.x <= nova->tol * -1 && nova->z.y < 0)
			// 	my_mlx_pixel_put(nova->imgprt, nova->px.x, nova->px.y, \
			// 	0x0099e1d9 + (i << 8)); //0x00a2dcc7 * i / 1000000
			else
				my_mlx_pixel_put(nova->imgprt, nova->px.x, nova->px.y, \
				0x00a2dcc7 * i / 1000000); //0x00a2dcc7 * i / 1000000
			nova->px.y++;
		}
		nova->px.x++;
	}
	switchimg(nova);
}

void	nova_display(t_mlxsetup *set, t_cplx *fractal)
{
	nova_init(fractal, set);
	nova_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
}
