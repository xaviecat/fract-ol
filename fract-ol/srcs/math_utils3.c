/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:57:25 by xcharra           #+#    #+#             */
/*   Updated: 2023/04/28 16:57:28 by xcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
