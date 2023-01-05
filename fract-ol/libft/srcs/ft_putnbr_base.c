/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:30:48 by xcharra           #+#    #+#             */
/*   Updated: 2022/12/15 14:00:09 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(size_t nb, char *base)
{
	int		ret;

	ret = 0;
	if (nb < 16)
		ret += ft_putchar(base[nb]);
	if (nb >= 16)
	{
		ret += ft_putnbr_base(nb / 16, base);
		ret += ft_putnbr_base(nb % 16, base);
	}
	return (ret);
}
