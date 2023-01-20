/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:02:00 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/20 18:10:01 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	zmod2(t_coor *pixels)
{
	return (pixels->x * pixels->x + pixels->y * pixels->y);
}

double	ft_pow(double nbr, size_t ft_pow)
{
	double	res;

	res = 1;
	while (ft_pow && ft_pow--)
		res *= nbr;
	return (res);
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

double	rcplxcos(t_coor top, t_coor bot)
{
	return (cos(rcplxdiv(top, bot)) * cosh(icplxdiv(top, bot)));
}

double	icplxcos(t_coor top, t_coor bot)
{
	return (-sin(rcplxdiv(top, bot)) * sinh(icplxdiv(top, bot)));
}

double	rcplxsin(t_coor top, t_coor bot)
{
	return (sin(rcplxdiv(top, bot)) * cosh(icplxdiv(top, bot)));
}

double	icplxsin(t_coor top, t_coor bot)
{
	return (cos(rcplxdiv(top, bot)) * sinh(icplxdiv(top, bot)));
}

double	rcplxpow2(t_coor z, size_t power)
{
	if (power == 6)
		return (ft_pow(z.x, 6) - 15 * ft_pow(z.x, 4) * ft_pow(z.y, 2) + 15 * \
		ft_pow(z.x, 2) * ft_pow(z.y, 4) - ft_pow(z.y, 6));
	else if (power == 7)
		return (ft_pow(z.x, 7) - 21 * ft_pow(z.x, 5) * ft_pow(z.y, 2) + 35 * \
		ft_pow(z.x, 3) * ft_pow(z.y, 4) - 7 * z.x * ft_pow(z.y, 6));
	else if (power == 8)
		return (ft_pow(z.x, 8) - 28 * ft_pow(z.x, 6) * ft_pow(z.y, 2) + 70 * \
		ft_pow(z.x, 4) * ft_pow(z.y, 4) - 28 * ft_pow(z.x, 2) * ft_pow(z.y, 6) \
		+ ft_pow(z.y, 8));
	else if (power == 9)
		return (ft_pow(z.x, 9) - 36 * ft_pow(z.x, 7) * ft_pow(z.y, 2) + 126 * \
		ft_pow(z.x, 5) * ft_pow(z.y, 4) - 84 * ft_pow(z.x, 3) * ft_pow(z.y, 6) \
		+ 9 * z.x * ft_pow(z.y, 8));
	else if (power == 10)
		return (ft_pow(z.x, 10) - 45 * ft_pow(z.x, 8) * ft_pow(z.y, 2) + 210 * \
		ft_pow(z.x, 6) * ft_pow(z.y, 4) - 210 * ft_pow(z.x, 4) * ft_pow(z.y, 6) \
		+ 45 * ft_pow(z.x, 2) * ft_pow(z.y, 8) - ft_pow(z.y, 10));
	return (0);
}

double	rcplxpow(t_coor z, size_t power)
{
	if (power == 1)
		return (ft_pow(z.x, 1));
	else if (power == 2)
		return (ft_pow(z.x, 2) - ft_pow(z.y, 2));
	else if (power == 3)
		return (ft_pow(z.x, 3) - 3 * z.x * ft_pow(z.y, 2));
	else if (power == 4)
		return (ft_pow(z.x, 4) - 6 * ft_pow(z.x, 2) * ft_pow(z.y, 2) + \
		ft_pow(z.y, 4));
	else if (power == 5)
		return (ft_pow(z.x, 5) - 10 * ft_pow(z.x, 3) * ft_pow(z.y, 2) + 5 * z.x \
		* ft_pow(z.y, 4));
	return (rcplxpow2(z, power));
}

double	icplxpow2(t_coor z, size_t power)
{
	if (power == 6)
		return (6 * ft_pow(z.x, 5) * z.y - 20 * ft_pow(z.x, 3) * ft_pow(z.y, 3) \
		+ 6 * z.x * ft_pow(z.y, 5));
	else if (power == 7)
		return (7 * ft_pow(z.x, 6) * z.y - 35 * ft_pow(z.x, 4) * ft_pow(z.y, 3) \
		+ 21 * ft_pow(z.x, 2) * ft_pow(z.y, 5) - ft_pow(z.y, 7));
	else if (power == 8)
		return (8 * ft_pow(z.x, 7) * z.y - 56 * ft_pow(z.x, 5) * ft_pow(z.y, 3) \
		+ 56 * ft_pow(z.x, 3) * ft_pow(z.y, 5) - 8 * z.x * ft_pow(z.y, 7));
	else if (power == 9)
		return (9 * ft_pow(z.x, 8) * z.y - 84 * ft_pow(z.x, 6) * ft_pow(z.y, 3) \
		+ 126 * ft_pow(z.x, 4) * ft_pow(z.y, 5) - 36 * ft_pow(z.x, 2) * \
		ft_pow(z.y, 7) + ft_pow(z.y, 9));
	else if (power == 10)
		return (10 * ft_pow(z.x, 9) * z.y - 120 * ft_pow(z.x, 7) * \
		ft_pow(z.y, 3) + 252 * ft_pow(z.x, 5) * ft_pow(z.y, 5) - 120 * \
		ft_pow(z.x, 3) * ft_pow(z.y, 7) + 10 * z.x * ft_pow(z.y, 9));
	return (0);
}

double	icplxpow(t_coor z, size_t power)
{
	if (power == 1)
		return (ft_pow(z.y, 1));
	else if (power == 2)
		return (2 * z.x * z.y);
	else if (power == 3)
		return (3 * ft_pow(z.x, 2) * z.y - ft_pow(z.y, 3));
	else if (power == 4)
		return (4 * ft_pow(z.x, 3) * z.y - 4 * z.x * ft_pow(z.y, 3));
	else if (power == 5)
		return (5 * ft_pow(z.x, 4) * z.y - 10 * ft_pow(z.x, 2) * ft_pow(z.y, 3) \
		+ ft_pow(z.y, 5));
	return (icplxpow2(z, power));
}
