/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:06:58 by xcharra           #+#    #+#             */
/*   Updated: 2022/12/15 14:00:17 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	char	c;
	int		ret;

	c = '0';
	ret = 0;
	if (nb == -2147483648)
	{
		ret += ft_putstr(MININT);
		return (ret);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ret += ft_putchar('-');
	}
	if (nb >= 0 && nb < 10)
		ret += ft_putchar(nb + c);
	if (nb >= 10)
	{
		ret += ft_putnbr(nb / 10);
		ret += ft_putnbr(nb % 10);
	}
	return (ret);
}
