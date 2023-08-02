/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:21 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/02 13:20:35 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "struct.h"
# include "mlx.h"
# define WIDTH		600//1920 // /* x */
# define HEIGHT		600//1080 // /* y */
# define DBLMAX		1000000000000000000000.
# define SJULIA		"Julia"
# define SMANDEL	"Mandelbrot"
# define SBURNING	"Burning_Ship"
# define SLEAF		"Leaf"
# define SLEAFT		"Leaft"
# define SNEWTON	"Newton"
# define SNOVA		"Nova"
# define RATIO		1 /* x / y */
# define ALP		0
# define RED		1
# define GRE		2
# define BLU		3

# define ERROR		"Please enter a valid argument among these:\n\
-Julia\n\
-Mandelbrot\n\
-Burning_Ship\n\
-Leaf\n\
-Leaft\n\
-Newton\n\
-Nova\n"

void	choose_fractal(int name, t_mlxsetup *set, t_cplx *fractal);

void	init_set(t_mlxsetup *set);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		clear_close_exit(t_cplx *fractal);
void	switchimg(t_cplx *fractal);

double	zmod2(t_coor *pixels);
double	ft_pow(double nbr, size_t pow);
double	rcplxdiv(t_coor top, t_coor bot);
double	icplxdiv(t_coor top, t_coor bot);

double	rcplxpow1to5(t_coor z, size_t power);
double	rcplxpow6to10(t_coor z, size_t power);
double	icplxpow1to5(t_coor z, size_t power);
double	icplxpow6to10(t_coor z, size_t power);

double	rcplxcos(t_coor top, t_coor bot);
double	icplxcos(t_coor top, t_coor bot);
double	rcplxsin(t_coor top, t_coor bot);
double	icplxsin(t_coor top, t_coor bot);

void	julia_init(t_cplx *julia, t_mlxsetup *set);
void	julia_z_incr(t_cplx *julia);
void	julia_iter(t_cplx *julia);
void	julia_set(t_cplx *julia);
void	julia_display(t_mlxsetup *set, t_cplx *fractal);

void	mandel_init(t_cplx *mandel, t_mlxsetup *set);
void	mandel_z_incr(t_cplx *mandel);
void	mandel_iter(t_cplx *mandel);
void	mandel_set(t_cplx *mandel);
void	mandel_display(t_mlxsetup *set, t_cplx *fractal);

void	burning_init(t_cplx *mendel, t_mlxsetup *set);
void	burning_z_incr(t_cplx *mendel);
void	burning_iter(t_cplx *mendel);
void	burning_ship(t_cplx *mendel);
void	burning_display(t_mlxsetup *set, t_cplx *fractal);

void	leaf_init(t_cplx *leaf, t_mlxsetup *set);
void	leaf_z_incr(t_cplx *leaf);
void	leaf_iter(t_cplx *leaf);
void	leaf_set(t_cplx *leaf);
void	leaf_display(t_mlxsetup *set, t_cplx *fractal);

void	leaft_init(t_cplx *leaft, t_mlxsetup *set);
void	leaft_z_incr(t_cplx *leaft);
void	leaft_iter(t_cplx *leaft);
void	leaft_set(t_cplx *leaft);
void	leaft_display(t_mlxsetup *set, t_cplx *fractal);

void	newton_init(t_cplx *newton, t_mlxsetup *set);
void	newton_z_incr(t_cplx *newton);
void	newton_iter(t_cplx *newton);
void	newton_set(t_cplx *newton);
void	newton_display(t_mlxsetup *set, t_cplx *fractal);

void	nova_init(t_cplx *nova, t_mlxsetup *set);
void	nova_z_incr(t_cplx *nova);
void	nova_iter(t_cplx *nova);
void	nova_set(t_cplx *nova);
void	nova_display(t_mlxsetup *set, t_cplx *fractal);

void	display_fractal(t_cplx	*fractal);
void	undo(int k, t_cplx	*fractal);
void	move_n_c(int k, t_cplx *fractal);
void	get_numpad_selector(int k, t_cplx *fractal);
void	iter_tol(int k, t_cplx *fractal);

int		mouse_hook(int button, int x, int y, t_cplx	*fractal);
int		movec(int x, int y, t_cplx	*fractal);
int		process_key(int keycode, t_cplx	*fractal);
void	hooks(t_cplx *fractal);

void	print_info(t_cplx *fractal);

void	print_hud(t_cplx *fractal);
void	print_hud_pow_iter(t_cplx *fractal);
void	print_hud_cx_cy(t_cplx *fractal);
void	print_hud_zoom(t_cplx *fractal);

void	color_pixels(t_cplx *fractal, size_t i);
void	newton_colors(size_t i, t_cplx *newton);

#endif
