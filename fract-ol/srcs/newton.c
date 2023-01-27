/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:37:57 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/27 11:56:38 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	newton_init(t_cplx *newton, t_mlxsetup *set)
{
	newton->name = NEWTON;
	newton->sname = SNEWTON;
	newton->px.x = 0;
	newton->px.y = 0;
	newton->z.x = 0;
	newton->z.y = 0;
	newton->r = 2;
	newton->imax = 50;
	newton->zoom = 1;
	newton->move.x = 0;
	newton->move.y = 0;
	newton->set = *set;
	newton->tol = 0.001;
	newton->imgprt = &newton->set.img;
	newton->imgdsp = &newton->set.img2;
}

void	newton_z_incr(t_cplx *newton)
{
	newton->z.x = ((2 * newton->r * newton->px.x / WIDTH - newton->r) * \
	newton->zoom * RATIO + newton->move.x);
	newton->z.y = ((newton->r - 2 * newton->r * newton->px.y / HEIGHT) * \
	newton->zoom + newton->move.y);
	newton->c.x = ((2 * newton->r * newton->px.x / WIDTH - newton->r) * \
	newton->zoom * RATIO + newton->move.x);
	newton->c.y = ((newton->r - 2 * newton->r * newton->px.y / HEIGHT) * \
	newton->zoom + newton->move.y);
}

void	newton_iter(t_cplx *newton)
{
	newton->old.x = newton->z.x;
	newton->old.y = newton->z.y;
	newton->tmp.x = (2 * ft_pow(newton->z.x, 5) + 4 * ft_pow(newton->z.x, 3) * \
	ft_pow(newton->z.y, 2) - ft_pow(newton->z.x, 2) + 2 * newton->z.x * \
	ft_pow(newton->z.y, 4) + ft_pow(newton->z.y, 2)) / \
	(3 * ft_pow(ft_pow(newton->z.x, 2) + ft_pow(newton->z.y, 2), 2));
	newton->z.y = (2 * newton->z.y * (ft_pow(newton->z.x, 4) + 2 * \
	ft_pow(newton->z.x, 2) * ft_pow(newton->z.y, 2) + newton->z.x + \
	ft_pow(newton->z.y, 4))) / \
	(3 * ft_pow(ft_pow(newton->z.x, 2) + ft_pow(newton->z.y, 2), 2));
	newton->z.x = newton->tmp.x;
	newton->tmp.y = ft_pow(newton->z.x - newton->old.x, 2) + \
	ft_pow(newton->z.y - newton->old.y, 2);
}

void	newton_set(t_cplx *newton)
{
	size_t	i;

	newton->px.x = 0;
	while (newton->px.x < WIDTH)
	{
		newton->px.y = 0;
		while (newton->px.y < HEIGHT)
		{
			newton_z_incr(newton);
			i = 1;
			newton->tmp.y = 1;
			while (newton->tmp.y > newton->tol && i < newton->imax && i++)
				newton_iter(newton);
			if (i == newton->imax)
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x00FF0000);
			else if (newton->z.x <= newton->tol * -1)
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x00ABBDFF + (i << 8));
			else if (newton->z.x >= newton->tol * 1 && newton->z.y > 0)
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x00894B77 + (i << 8));
			else if (newton->z.x >= newton->tol * 1 && newton->z.y < 0)
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x0099e1d9 + (i << 8));
			else
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x00a2dcc7 * i / 1000000);
			newton->px.y++;
		}
		newton->px.x++;
	}
	switchimg(newton);
}

void	newton_display(t_mlxsetup *set, t_cplx *fractal)
{
	newton_init(fractal, set);
	newton_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
}
