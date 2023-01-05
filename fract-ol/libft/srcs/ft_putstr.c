/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:05:08 by xcharra           #+#    #+#             */
/*   Updated: 2022/12/15 14:00:24 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ret += ft_putchar(str[i]);
		i++;
	}
	return (ret);
}
