/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:02:00 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 16:56:56 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	zmod2(t_coor *pixels)
{
	return (pixels->x * pixels->x + pixels->y * pixels->y);
}

double	ft_pow(double x, size_t pow)
{
	if (pow == 1)
		return (x);
	else if (pow == 2)
		return (x * x);
	else if (pow == 3)
		return (x * x * x);
	else if (pow == 4)
		return (x * x * x * x);
	else if (pow == 5)
		return (x * x * x * x * x);
	else if (pow == 6)
		return (x * x * x * x * x * x);
	else if (pow == 7)
		return (x * x * x * x * x * x * x);
	else if (pow == 8)
		return (x * x * x * x * x * x * x * x);
	else if (pow == 9)
		return (x * x * x * x * x * x * x * x * x);
	else if (pow == 10)
		return (x * x * x * x * x * x * x * x * x * x);
	else if (pow == 11)
		return (x * x * x * x * x * x * x * x * x * x * x);
	else if (pow == 12)
		return (x * x * x * x * x * x * x * x * x * x * x * x);
	return (1);
}

double	rcplxdiv(t_coor top, t_coor bot)
{
	return ((top.x * bot.x) / \
	(ft_pow(bot.x, 2) + ft_pow(bot.y, 2)) + \
	(top.y * bot.y) / \
	(ft_pow(bot.x, 2) + ft_pow(bot.y, 2)));
}

double	icplxdiv(t_coor top, t_coor bot)
{
	return ((bot.x * top.y) / \
	(ft_pow(bot.x, 2) + ft_pow(bot.y, 2)) - \
	(top.x * bot.y) / \
	(ft_pow(bot.x, 2) + ft_pow(bot.y, 2)));
}
