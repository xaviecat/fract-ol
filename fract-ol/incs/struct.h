/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:42:23 by xcharra           #+#    #+#             */
/*   Updated: 2023/08/01 17:52:46 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	MANDEL,
	BURNING,
	LEAF,
	LEAFT,
	NEWTON,
	NOVA,
}t_name;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_cplx
{
	t_name			name;
	char			*sname;
	t_coor			px;
	t_coor			z;
	t_coor			c;
	t_coor			q;
	t_coor			tmp;
	t_coor			old;
	t_coor			move;
	t_coor			mouse;
	size_t			cstate;
	size_t			hstate;
	size_t			nstate;
	size_t			selector;
	double			tol;
	double			a;
	double			b;
	double			cc;
	double			d;
	double			r;
	double			imax;
	double			zoom;

	size_t			pow;
	t_mlxsetup		set;
	t_img			*imgtmp;
	t_img			*imgprt;
	t_img			*imgdsp;
	unsigned int	color_max;
	unsigned int	color_drv;
	t_bool			clickstatus;
}				t_cplx;

typedef enum e_num_pad
{
	NUM0 = 65438,
	NUM1 = 65436,
	NUM2 = 65433,
	NUM3 = 65435,
	NUM4 = 65430,
	NUM5 = 65437,
	NUM6 = 65432,
	NUM7 = 65429,
	NUM8 = 65431,
	NUM9 = 65434,
}	t_num_pad;

/* MOUSE HOOK LINUX */
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

/* KEY HOOK LINUX*/
enum
{
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361,
	PLUS = 61,
	MINUS = 45,
	ESC = 65307,
	B = 98,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	I = 105,
	K = 107,
	L = 108,
	J = 106,
	H = 104,
	N = 110,
	CBL = 91,
	CBR = 93,
	ONE = 49,
	TWO = 50,
	THREE = 51,
	FOUR = 52,
	FIVE = 53,
	SIX = 54,
	SEVEN = 55,
	EIGHT = 56,
	NINE = 57,
	ZERO = 48,
};

/* MOUSE HOOK LINUX*/
enum
{
	LEFTC = 1,
	RIGHTC = 3,
	SCROLLC = 2,
	SCROLLDOWN = 5,
	SCROLLUP = 4,
};

/* KEY HOOK MAC*/
/*
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
	I = 34,
	K = 40,
	L = 37,
	J = 38,
	H = 4,
	N = 0x0,
	CBL = 33,
	CBR = 30,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	FOUR = 21,
	FIVE = 23,
	SIX = 22,
	SEVEN = 26,
	EIGHT = 28,
	NINE = 25,
	ZERO = 29,
};
*/
/* MOUSE HOOK MAC*/
/*
enum
{
	LEFTC = 1,
	RIGHTC = 2,
	SCROLLC = 3,
	SCROLLDOWN = 4,
	SCROLLUP = 5,
};
*/

#endif