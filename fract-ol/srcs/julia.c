/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:30 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/13 16:18:39 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_cplx *julia, t_mlxsetup *set)
{
	julia->px.x = 0;
	julia->px.y = 0;
	julia->z.x = 0;
	julia->z.y = 0;
	julia->c.x = /* 0.25; //-1;// */-0.4;
	julia->c.y = /* 0;// */0.6;
	julia->r = 2;
	julia->imax = 10;
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
				my_mlx_pixel_put(&julia->set.img, julia->px.x, julia->px.y, \
				0x00FFFFFF);
			else
				my_mlx_pixel_put(&julia->set.img, julia->px.x, julia->px.y, \
				0x00a2dcc7 * i / 10000); //0x00a2dcc7 / i / 10000
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
