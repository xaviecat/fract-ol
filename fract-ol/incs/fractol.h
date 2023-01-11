/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:21 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/11 18:04:14 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// # include <limits.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"
# define WIDTH	1000 //1920 /* x */
# define HEIGHT	1000 //1080 /* y */
# define IMAX	100

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
	t_mlxsetup	set;
}				t_cplx;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
