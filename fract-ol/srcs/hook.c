/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:49 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/01 17:58:57 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_fractal(t_cplx	*fractal)
{
	if (fractal->name == JULIA)
		julia_set(fractal);
	else if (fractal->name == MANDEL)
		mandel_set(fractal);
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
	else if ((k == B && fractal->name == MANDEL) || k == TWO)
		mandel_init(fractal, &fractal->set);
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

void	get_numpad_selector(int k, t_cplx *fractal)
{
	if (k == NUM0)
		fractal->selector = 0;
	else if (k == NUM1)
		fractal->selector = 1;
	else if (k == NUM2)
		fractal->selector = 2;
	else if (k == NUM3)
		fractal->selector = 3;
	else if (k == NUM4)
		fractal->selector = 4;
	else if (k == NUM5)
		fractal->selector = 5;
	else if (k == NUM6)
		fractal->selector = 6;
	else if (k == NUM7)
		fractal->selector = 7;
	else if (k == NUM8)
		fractal->selector = 8;
	else if (k == NUM9)
		fractal->selector = 9;
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
	else if (k == N && (fractal->name == NOVA || fractal->name == MANDEL))
		fractal->nstate++;
	get_numpad_selector(k, fractal);
	printf("sel= %d")
	iter_tol(k, fractal);
	move_n_c(k, fractal);
	undo(k, fractal);
	display_fractal(fractal);
	return (0);
}
