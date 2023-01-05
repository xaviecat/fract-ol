/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:21:24 by xcharra           #+#    #+#             */
/*   Updated: 2022/12/15 14:00:28 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int nb)
{
	char	c;
	int		ret;

	c = '0';
	ret = 0;
	if (nb < 10)
		ret += ft_putchar(nb + c);
	if (nb >= 10)
	{
		ret += ft_putunbr(nb / 10);
		ret += ft_putunbr(nb % 10);
	}
	return (ret);
}
