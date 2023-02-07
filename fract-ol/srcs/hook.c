/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:49 by xcharra           #+#    #+#             */
/*   Updated: 2023/02/07 17:33:12 by xcharra          ###   ########.fr       */
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
	else if (fractal->name == NOVA)
		nova_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	print_hud(fractal);
}

void	undo(int k, t_cplx	*fractal)
{
	if ((k == B && fractal->name == JULIA) || k == ONE)
		julia_init(fractal, &fractal->set);
	else if ((k == B && fractal->name == MENDEL) || k == TWO)
		mendel_init(fractal, &fractal->set);
	else if ((k == B && fractal->name == BURNING) || k == THREE)
		burning_init(fractal, &fractal->set);
	else if ((k == B && fractal->name == LEAF) || k == FOUR)
		leaf_init(fractal, &fractal->set);
	else if ((k == B && fractal->name == LEAFT) || k == FIVE)
		leaft_init(fractal, &fractal->set);
	else if ((k == B && fractal->name == NEWTON) || k == SIX)
		newton_init(fractal, &fractal->set);
	else if ((k == B && fractal->name == NOVA) || k == SEVEN)
		nova_init(fractal, &fractal->set);
}

void	move_n_c(int k, t_cplx *fractal)
{
	if (k == W)
		fractal->c.y += 0.01 * fractal->zoom;
	else if (k == S)
		fractal->c.y -= 0.01 * fractal->zoom;
	else if (k == D)
		fractal->c.x += 0.01 * fractal->zoom;
	else if (k == A)
		fractal->c.x -= 0.01 * fractal->zoom;
	else if (k == UP)
		fractal->move.y += 0.05 * fractal->zoom;
	else if (k == DOWN)
		fractal->move.y -= 0.05 * fractal->zoom;
	else if (k == RIGHT)
		fractal->move.x += 0.05 * fractal->zoom;
	else if (k == LEFT)
		fractal->move.x -= 0.05 * fractal->zoom;
	else if (k == I)
		fractal->q.y += 0.01 * fractal->zoom;
	else if (k == K)
		fractal->q.y -= 0.01 * fractal->zoom;
	else if (k == L)
		fractal->q.x += 0.01 * fractal->zoom;
	else if (k == J)
		fractal->q.x -= 0.01 * fractal->zoom;
}

void	iter_tol(int k, t_cplx *fractal)
{
	if (k == MINUS)
		fractal->imax -= 10;
	else if (k == PLUS)
		fractal->imax += 10;
	else if (k == MINUS)
		fractal->imax -= 10;
	else if (k == PLUS)
		fractal->imax += 10;
	else if (k == MINUS && fractal->name == NEWTON && fractal->imax >= 10.)
		fractal->imax = fractal->imax / 10;
	else if (k == PLUS && fractal->name == NEWTON && fractal->imax <= DBLMAX)
		fractal->imax = fractal->imax * 10;
}

int	process_key(int k, t_cplx	*fractal)
{
	if (k == ESC)
		clear_close_exit(fractal);
	else if (k == CBL)
		fractal->pow -= 1;
	else if (k == CBR)
		fractal->pow += 1;
	else if (k == H)
		fractal->hstate++;
	else if (k == N && fractal->name == NOVA)
		fractal->nstate++, ft_printf("nstate{%d}", (int)fractal->nstate);
	// else
	// 	return (ft_printf("Key : %d\n", k));
	iter_tol(k, fractal);
	move_n_c(k, fractal);
	undo(k, fractal);
	display_fratcal(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cplx	*fractal)
{
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
	else if (button == LEFTC)
		fractal->cstate++/*, ft_printf("cstate{%d}", (int)fractal->cstate) */;
	else
		return (ft_printf("Key : %d\n", button));
	display_fratcal(fractal);
	return (0);
}

int		movec(int x, int y, t_cplx	*fractal)
{
	if (fractal->cstate % 2 == 1)
	{
		//printf(" at (%d,%d)", x, y);
		fractal->c.x = ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) * \
		fractal->zoom;
		fractal->c.y = (fractal->r - 2 * fractal->r * y / HEIGHT) * \
		fractal->zoom;
	}
	display_fratcal(fractal);
	return (0);
}

void	hooks(t_cplx *fractal)
{
	fractal->cstate = 0;
	fractal->hstate = 0;
	fractal->nstate = 0;
	mlx_hook(fractal->set.lnk.mlx_win, ON_KEYDOWN, 1L<<0, process_key, fractal);
	mlx_hook(fractal->set.lnk.mlx_win, ON_DESTROY, 0L, clear_close_exit, \
	fractal);
	mlx_mouse_hook(fractal->set.lnk.mlx_win, mouse_hook, fractal);
	mlx_hook(fractal->set.lnk.mlx_win, ON_MOUSEMOVE, 1L<<13, movec, fractal);
}
