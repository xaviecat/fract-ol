/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:49 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/17 17:47:22 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	process_key(int keycode, t_cplx	*fractal)
{
	if (keycode == ESC)
		clear_close_exit(fractal);
	else if (keycode == UP)
		fractal->c.y += 0.01;
	else if (keycode == DOWN)
		fractal->c.y -= 0.01;
	else if (keycode == RIGHT)
		fractal->c.x += 0.01;
	else if (keycode == LEFT)
		fractal->c.x -= 0.01;
	else if (keycode == B && fractal->name == JULIA)
		julia_init(fractal, &fractal->set);
	else if (keycode == B && fractal->name == MENDEL)
		mendel_init(fractal, &fractal->set);
	else if (keycode == B && fractal->name == BURNING)
		burning_init(fractal, &fractal->set);
	else if (keycode == MINUS)
		fractal->imax -= 10;
	else if (keycode == PLUS)
		fractal->imax += 10;
	else if (keycode == D)
		fractal->move.x += 0.1 * fractal->zoom;
	else if (keycode == A)
		fractal->move.x -= 0.1 * fractal->zoom;
	else if (keycode == W)
		fractal->move.y += 0.1 * fractal->zoom;
	else if (keycode == S)
		fractal->move.y -= 0.1 * fractal->zoom;
	else
		return (ft_printf("Key : %d\n", keycode));
	if (fractal->name == JULIA)
		julia_set(fractal);
	else if (fractal->name == MENDEL)
		mendel_set(fractal);
	else if (fractal->name == BURNING)
		burning_set(fractal);
	mlx_put_image_to_window(&fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cplx	*fractal)
{
	(void)x;
	(void)y;
	if (button == SCROLLUP)
		fractal->zoom *= 1.1;
	else if (button == SCROLLDOWN)
		fractal->zoom /= 1.1;
	else
		return (ft_printf("Key : %d\n", button));
	if (fractal->name == JULIA)
		julia_set(fractal);
	else if (fractal->name == MENDEL)
		mendel_set(fractal);
	else if (fractal->name == BURNING)
		burning_set(fractal);
	mlx_put_image_to_window(&fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	return (0);
}

void	hooks(t_cplx *fractal)
{
	mlx_hook(fractal->set.lnk.mlx_win, ON_KEYDOWN, 0L, &process_key, fractal);
	mlx_hook(fractal->set.lnk.mlx_win, ON_DESTROY, 0L, &clear_close_exit, fractal);
	mlx_mouse_hook(fractal->set.lnk.mlx_win, mouse_hook, fractal);
}
