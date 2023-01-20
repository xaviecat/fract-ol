/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:21 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/20 18:15:00 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
// # include <limits.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define WIDTH	500 //1920 /* x */
# define HEIGHT	500 //1080 /* y */
# define RATIO	WIDTH / HEIGHT //!attention
# define ERROR	"Please enter a valid argument among these:\n\
-Julia\n\
-Mendelbrot\n\
-Burning Ship\n"

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}			t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_mlxsetup
{
	t_vars	lnk;
	t_img	img;
	t_img	img2;
}			t_mlxsetup;
typedef struct s_coor
{
	double	x;
	double	y;
}			t_coor;

/* FRACTAL NAMES */
typedef enum e_name
{
	JULIA,
	MENDEL,
	BURNING,
	LEAF,
	LEAFT,
}t_name;

typedef struct s_cplx
{
	t_name		name;
	t_coor		px;
	t_coor		z;
	t_coor		c;
	t_coor		tmp;
	t_coor		move;
	double		r;
	double		imax;
	double		zoom;
	size_t		pow;
	t_mlxsetup	set;
	t_img		*imgtmp;
	t_img		*imgprt;
	t_img		*imgdsp;
}				t_cplx;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
/* KEY HOOK */
enum
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
	PLUS = 24,
	MINUS = 27,
	ESC = 53,
	B = 11,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	FOUR = 21,
	FIVE = 23,
};
/* MOUSE HOOK */
enum
{
	LEFTC = 1,
	RIGHTC = 2,
	SCROLLC = 3,
	SCROLLDOWN = 4,
	SCROLLUP = 5,
};

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	init_set(t_mlxsetup *set);
void	switchimg(t_cplx *fractal);

double	zmod2(t_coor *pixels);
double	ft_pow(double nbr, size_t pow);
double	rcplxpow(t_coor z, size_t power);
double	icplxpow(t_coor z, size_t power);
double	rcplxdiv(t_coor top, t_coor bot);
double	icplxdiv(t_coor top, t_coor bot);
double	rcplxcos(t_coor top, t_coor bot);
double	icplxcos(t_coor top, t_coor bot);
double	rcplxsin(t_coor top, t_coor bot);
double	icplxsin(t_coor top, t_coor bot);

void	julia_init(t_cplx *julia, t_mlxsetup *set);
void	julia_z_incr(t_cplx *julia);
void	julia_iter(t_cplx *julia);
void	julia_set(t_cplx *julia);
void	julia_display(t_mlxsetup *set, t_cplx *fractal);

void	mendel_init(t_cplx *mendel, t_mlxsetup *set);
void	mendel_z_incr(t_cplx *mendel);
void	mendel_iter(t_cplx *mendel);
void	mendel_set(t_cplx *mendel);
void	mendel_display(t_mlxsetup *set, t_cplx *fractal);

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

void	hooks(t_cplx *fractal);
int		process_key(int keycode, t_cplx	*fractal);
int		mouse_hook(int button, int x, int y, t_cplx	*fractal);
int		clear_close_exit(t_cplx *fractal);

# include <stdio.h>
#endif
