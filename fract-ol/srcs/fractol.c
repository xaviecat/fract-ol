/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <xcharra@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:24 by xcharra           #+#    #+#             */
/*   Updated: 2023/02/07 12:11:48 by xcharra          ###   ########.fr       */
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
	//print_hud(&fractal);
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

/* TEST LINUX */
/* void	settest(t_cplx *fractal, t_mlxsetup *set)
{
	set->lnk.mlx = mlx_init();
	set->lnk.mlx_win = mlx_new_window(set->lnk.mlx, WIDTH, HEIGHT, "fract-ol");
	set->img.img = mlx_new_image(set->lnk.mlx, WIDTH, HEIGHT);
	set->img.addr = mlx_get_data_addr(set->img.img, \
	&set->img.bits_per_pixel, &set->img.line_length, &set->img.endian);
	set->img2.img = mlx_new_image(set->lnk.mlx, WIDTH, HEIGHT);
	fractal->set = *set;
	fractal->pow = 2;
	fractal->imgprt = &fractal->set.img;
	fractal->imgdsp = &fractal->set.img2;
}

int	keytest(int k, t_cplx *fractal)
{
	(void)fractal;
	printf("KEY = %d\n", k);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	return (0);
}

int	mousetest(int k, int x, int y, t_cplx *fractal)
{
	(void)fractal;
	printf("KEY = %d at (%d,%d)\n", k, x , y);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_mlxsetup	set;
	t_cplx		fractal;
	
	settest(&fractal, &set);
	mlx_hook(fractal.set.lnk.mlx_win, ON_KEYDOWN, 1L<<0, keytest, &fractal);
	mlx_mouse_hook(fractal.set.lnk.mlx_win, mousetest, &fractal);
	mlx_put_image_to_window(fractal.set.lnk.mlx, fractal.set.lnk.mlx_win, \
	fractal.imgdsp->img, 0, 0);
	mlx_string_put(fractal.set.lnk.mlx, fractal.set.lnk.mlx_win, 10, 70, \
	0x00FFFFFF, "zoom = ");
	mlx_loop(set.lnk.mlx);
} */