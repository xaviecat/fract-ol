/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:29:27 by xcharra           #+#    #+#             */
/*   Updated: 2022/11/22 17:58:01 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (((char *)str)[i] && ((char *)str)[i] != (unsigned char)c)
		i++;
	if (((char *)str)[i] == (unsigned char)c)
		return (&((char *)str)[i]);
	return (NULL);
}
