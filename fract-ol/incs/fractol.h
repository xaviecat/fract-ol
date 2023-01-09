/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:50:21 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/09 17:56:53 by xcharra          ###   ########lyon.fr   */
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
# include <mlx.h>
# define WIDTH	1920 /* x */
# define HEIGHT	1080 /* y */
# define IMAX	1000

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_complex
{
	double	x;
	double	xtemp;
	double	y;
}			t_complex;

#endif
