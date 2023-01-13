/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:21 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/13 15:49:54 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
// # include <limits.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "mlx.h"
# define WIDTH	800 //1920 /* x */
# define HEIGHT	800 //1080 /* y */

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

typedef struct s_cplx
{
	t_coor		px;
	t_coor		z;
	t_coor		c;
	t_coor		tmp;
	double		r;
	double		imax;
	t_mlxsetup	set;
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

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	init_set(t_mlxsetup *set);

double	zmod2(t_coor *pixels);

void	julia_init(t_cplx *julia, t_mlxsetup *set);
void	julia_z_incr(t_cplx *julia);
void	julia_iter(t_cplx *julia);
void	julia_set(t_cplx *julia);
void	julia_display(t_mlxsetup *set, t_cplx *julia);

void	hooks(t_cplx *julia);
int		process_key(int keycode, t_cplx	*julia);
int		clear_close_exit(t_cplx *julia);

# include <stdio.h>
#endif
