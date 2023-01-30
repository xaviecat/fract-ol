/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:24 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/30 13:45:50 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	print_hud(&fractal);
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
