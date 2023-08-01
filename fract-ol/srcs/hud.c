/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:42:13 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/01 13:41:45 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_hud_zoom(t_cplx *fractal)
{
	char	*zoom;

	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 70, \
	0x00FFFFFF, "zoom = ");
	zoom = ft_dtoa(fractal->zoom, 2);
	if (!zoom)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 59, 70, \
	0x00FFFFFF, zoom);
	free(zoom);
}

void	print_hud_cx_cy(t_cplx *fractal)
{
	char	*cx;
	char	*cy;

	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 50, \
	0x00FFFFFF, "c.x = ");
	cx = ft_dtoa(fractal->c.x, 5);
	if (!cx)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 50, \
	0x00FFFFFF, cx);
	free(cx);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 60, \
	0x00FFFFFF, "c.y = ");
	cy = ft_dtoa(fractal->c.y, 5);
	if (!cy)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 60, \
	0x00FFFFFF, cy);
	free(cy);
}

void	print_hud_pow_iter(t_cplx *fractal)
{
	char	*pow;
	char	*iter;

	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 20, \
	0x00FFFFFF, fractal->sname);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 30, \
	0x00FFFFFF, "Pow : ");
	pow = ft_itoa(fractal->pow);
	if (!pow)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 30, \
	0x00FFFFFF, pow);
	free(pow);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 40, \
	0x00FFFFFF, "Iterations : ");
	iter = ft_itoa(fractal->imax);
	if (!iter)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 101, 40, \
	0x00FFFFFF, iter);
	free(iter);
}

/* Un caractere fait 7 pixels de cote */
void	print_hud(t_cplx *fractal)
{
	if (fractal->hstate % 2 == 1)
	{
		print_hud_pow_iter(fractal);
		if (fractal->name != MANDEL && fractal->name != BURNING)
			print_hud_cx_cy(fractal);
		print_hud_zoom(fractal);
	}
}
