/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:02:00 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/27 17:30:25 by xcharra          ###   ########lyon.fr   */
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
static size_t	get_len(double n, long num, size_t len, size_t precision)
{

	if (num == 0)
		len = 1;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	len += precision + 1;
	if (n < 0)
		len++;
	return (len);
}

static size_t	get_int_part(char *str, double n, long num, size_t i)
{
	long	tmp;
	size_t	ret;

	num = (long)n;
	tmp = num;
	ret = 0;
	while (tmp)
	{
		tmp /= 10;
		ret++;
	}
	while (num != 0)
	{
		str[ret] = (num % 10) + '0';
		num /= 10;
		ret--;
		i++;
	}
	if (n < 1 && n > -1)
		str[i++] = '0';
	return (i);
}

static void	get_dec_part(char *str, double dec, long num, size_t len)
{
	size_t	i;

	i = 0;
	str[i] = '.';
	i++;
	while (i < len)
	{
		dec *= 10;
		num = (long)dec;
		str[i] = (num % 10) + '0';
		dec -= (double)num;
		i++;
	}
	str[i] = '\0';
}

/* Precision 15 */
char	*ft_dtoa(double n, size_t precision)
{
	char	*str;
	size_t	i;
	size_t	len;
	double	dec;
	long	num;

	len = 0;
	num = (long)n;
	len = get_len(n, num, len, precision);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	i = get_int_part(str, n, num, i);
	dec = n - (double)num;
	len -= i;
	get_dec_part(&str[i], dec, num, len);
	return (str);
}
