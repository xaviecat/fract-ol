/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:05:13 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 17:50:05 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_cplx	*fractal)
{
	if (button == SCROLLDOWN)
	{
		fractal->zoom *= 1.1;
		fractal->move.x -= ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) \
		* 0.1 * fractal->zoom;
		fractal->move.y -= (fractal->r - 2 * fractal->r * y / HEIGHT) * 0.1 * \
		fractal->zoom;
	}
	else if (button == SCROLLUP)
	{
		fractal->zoom /= 1.1;
		fractal->move.x += ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) \
		* 0.1 * fractal->zoom;
		fractal->move.y += (fractal->r - 2 * fractal->r * y / HEIGHT) * 0.1 * \
		fractal->zoom;
	}
	else if (button == LEFTC)
		fractal->cstate++;
	else
		return (ft_printf("Key : %d\n", button));
	display_fractal(fractal);
	return (0);
}

int	movec(int x, int y, t_cplx	*fractal)
{
	if (fractal->cstate % 2 == 1)
	{
		fractal->c.x = ((2 * fractal->r * x / WIDTH - fractal->r) * RATIO) * \
		fractal->zoom;
		fractal->c.y = (fractal->r - 2 * fractal->r * y / HEIGHT) * \
		fractal->zoom;
		display_fractal(fractal);
	}
	return (0);
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
	iter_tol(k, fractal);
	move_n_c(k, fractal);
	undo(k, fractal);
	display_fractal(fractal);
	return (0);
}

void	hooks(t_cplx *fractal)
{
	fractal->cstate = 0;
	fractal->hstate = 0;
	fractal->nstate = 0;
	mlx_hook(fractal->set.lnk.mlx_win, ON_KEYDOWN, 1L << 0, process_key, \
	fractal);
	mlx_hook(fractal->set.lnk.mlx_win, ON_DESTROY, 0L, clear_close_exit, \
	fractal);
	mlx_mouse_hook(fractal->set.lnk.mlx_win, mouse_hook, fractal);
	mlx_hook(fractal->set.lnk.mlx_win, ON_MOUSEMOVE, 1L << 6, movec, fractal);
}
