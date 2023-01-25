/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:49 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/25 18:41:04 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_fratcal(t_cplx	*fractal)
{
	if (fractal->name == JULIA)
		julia_set(fractal);
	else if (fractal->name == MENDEL)
		mendel_set(fractal);
	else if (fractal->name == BURNING)
		burning_ship(fractal);
	else if (fractal->name == LEAF)
		leaf_set(fractal);
	else if (fractal->name == LEAFT)
		leaft_set(fractal);
	else if (fractal->name == NEWTON)
		newton_set(fractal);
	mlx_put_image_to_window(&fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
}

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
	else if ((keycode == B && fractal->name == JULIA) || keycode == ONE)
		julia_init(fractal, &fractal->set);
	else if ((keycode == B && fractal->name == MENDEL) || keycode == TWO)
		mendel_init(fractal, &fractal->set);
	else if ((keycode == B && fractal->name == BURNING) || keycode == THREE)
		burning_init(fractal, &fractal->set);
	else if ((keycode == B && fractal->name == LEAF) || keycode == FOUR)
		leaf_init(fractal, &fractal->set);
	else if ((keycode == B && fractal->name == LEAFT) || keycode == FIVE)
		leaft_init(fractal, &fractal->set);
	else if ((keycode == B && fractal->name == NEWTON) || keycode == SIX)
		newton_init(fractal, &fractal->set);
	else if ((keycode == B && fractal->name == NOVA) || keycode == SEVEN)
		nova_init(fractal, &fractal->set);
	else if (keycode == MINUS && fractal->name != NEWTON)
		fractal->imax -= 10;
	else if (keycode == PLUS && fractal->name != NEWTON)
		fractal->imax += 10;
	else if (keycode == MINUS && fractal->name == NEWTON && fractal->imax >= 10.)
		fractal->imax = fractal->imax / 10;
	else if (keycode == PLUS && fractal->name == NEWTON && fractal->imax <= DBLMAX)
		fractal->imax = fractal->imax * 10;
	else if (keycode == 33)
		fractal->pow -= 1;
	else if (keycode == 30)
		fractal->pow += 1;
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
	display_fratcal(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cplx	*fractal)
{
	if (button == LEFTC)
		fractal->state = 1;
	if (button == SCROLLUP)
	{
		fractal->zoom *= 1.1;
		fractal->move.x -= ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) \
		* 0.1 * fractal->zoom;
		fractal->move.y -= (fractal->r - 2 * fractal->r * y / HEIGHT) * 0.1 * \
		fractal->zoom;
	}
	else if (button == SCROLLDOWN)
	{
		fractal->zoom /= 1.1;
		fractal->move.x += ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) \
		* 0.1 * fractal->zoom;
		fractal->move.y += (fractal->r - 2 * fractal->r * y / HEIGHT) * 0.1 * \
		fractal->zoom;
	}
	else if (fractal->state == 1)
	{
		fractal->c.x = ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) \
		* fractal->zoom;
		fractal->c.y = (fractal->r - 2 * fractal->r * y / HEIGHT) * \
		fractal->zoom;
	}
	if (button == RIGHTC)
		fractal->state = 0;
	// else
	// 	return (ft_printf("Key : %d\n", button));
	display_fratcal(fractal);
	return (0);
}




void	hooks(t_cplx *fractal)
{
	mlx_hook(fractal->set.lnk.mlx_win, ON_KEYDOWN, 0L, process_key, fractal);
	mlx_hook(fractal->set.lnk.mlx_win, ON_DESTROY, 0L, clear_close_exit, fractal);
	mlx_mouse_hook(fractal->set.lnk.mlx_win, mouse_hook, fractal);
}
