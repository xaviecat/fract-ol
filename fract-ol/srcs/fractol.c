/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:24 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/27 17:33:51 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* Un caractere fait 7 pixels de cote */
void	print_info(t_cplx *fractal)
{
	char	*pow;
	char	*iter;
	char	*cx;
	char	*cy;
	char	*zoom;


	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 20, 0x00FFFFFF, fractal->sname);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 30, 0x00FFFFFF, "Pow : ");
	pow = ft_itoa(fractal->pow);
	if (!pow)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 30, 0x00FFFFFF, pow);
	free(pow);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 40, 0x00FFFFFF, "Iterations : ");
	iter = ft_itoa(fractal->imax);
	if (!iter)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 101, 40, 0x00FFFFFF, iter);
	free(iter);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 50, 0x00FFFFFF, "c.x = ");
	cx = ft_dtoa(fractal->c.x, 10);
	if (!cx)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 50, 0x00FFFFFF, cx);
	free(cx);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 60, 0x00FFFFFF, "c.y = ");
	cy = ft_dtoa(fractal->c.y, 10);
	if (!cy)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 60, 0x00FFFFFF, cy);
	free(cy);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 10, 70, 0x00FFFFFF, "zoom = ");
	zoom = ft_dtoa(fractal->zoom, 10);
	if (!zoom)
		clear_close_exit(fractal);
	mlx_string_put(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, 52, 70, 0x00FFFFFF, zoom);
	free(zoom);




	// printf("%.10f", fractal->c.x);
}

void	choose_fractal(int name)
{
	t_mlxsetup	set;
	t_cplx		fractal;

	init_set(&set);
	if (name == JULIA)
		julia_display(&set, &fractal);
	else if (name == MENDEL)
		mendel_display(&set, &fractal);
	else if (name == BURNING)
		burning_display(&set, &fractal);
	else if (name == LEAF)
		leaf_display(&set, &fractal);
	else if (name == LEAFT)
		leaft_display(&set, &fractal);
	else if (name == NEWTON)
		newton_display(&set, &fractal);
	else if (name == NOVA)
		nova_display(&set, &fractal);
	hooks(&fractal);
	print_info(&fractal);

	mlx_loop(set.lnk.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_putstr(ERROR));
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
		choose_fractal(JULIA);
	else if (ft_strncmp(argv[1], "Mendelbrot", 11) == 0)
		choose_fractal(MENDEL);
	else if (ft_strncmp(argv[1], "Burning Ship", 13) == 0)
		choose_fractal(BURNING);
	else if (ft_strncmp(argv[1], "Leaf", 5) == 0)
		choose_fractal(LEAF);
	else if (ft_strncmp(argv[1], "Leaft", 6) == 0)
		choose_fractal(LEAFT);
	else if (ft_strncmp(argv[1], "Newton", 7) == 0)
		choose_fractal(NEWTON);
	else if (ft_strncmp(argv[1], "Nova", 5) == 0)
		choose_fractal(NOVA);
	else
		return (ft_putstr(ERROR));
}
