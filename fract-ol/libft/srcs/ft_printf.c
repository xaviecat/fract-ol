/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:12:04 by xcharra           #+#    #+#             */
/*   Updated: 2022/12/15 14:03:48 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	display(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putnbr_base(va_arg(args, size_t), HEXAL));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), HEXAL));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), HEXAU));
	else
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		ret;

	i = 0;
	va_start(args, str);
	ret = 0;
	if (write(1, 0, 0) < 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ret += ft_putchar(str[i]);
		if (str[i] == '%' && str[i + 1])
		{
			ret += display(args, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}
