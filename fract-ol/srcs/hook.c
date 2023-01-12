/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xcharra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:49 by xcharra           #+#    #+#             */
/*   Updated: 2023/01/12 17:43:32 by xcharra          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	process_key(int keycode, t_cplx	*julia)
{
	if (keycode == 53)
		clear_close_exit(julia);
	else if (keycode == 126)
		julia->c.y += 0.01;
	else if (keycode == 125)
		julia->c.y -= 0.01;
	else if (keycode == 124)
		julia->c.x += 0.01;
	else if (keycode == 123)
		julia->c.x -= 0.01;
	else if (keycode == 11)
		julia_init(julia, &julia->set);
	else if (keycode == 27)
		julia->imax -= 10;
	else if (keycode == 24)
		julia->imax += 100;
	else
		return (ft_printf("Key : %d\n", keycode));
	julia_set(julia);
	mlx_put_image_to_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win, \
	julia->set.img.img, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_cplx	*julia)
{
	(void)x;
	(void)y;
	if (button == 5)
		julia->r /= 1.1;
	else if (button == 4)
		julia->r *= 1.1;
	else
		return (ft_printf("Key : %d\n", button));
	julia_set(julia);
	mlx_put_image_to_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win, \
	julia->set.img.img, 0, 0);
	return (0);
}

void	hooks(t_cplx *julia)
{
	mlx_hook(julia->set.lnk.mlx_win, ON_KEYDOWN, 0L, &process_key, julia);
	mlx_hook(julia->set.lnk.mlx_win, ON_DESTROY, 0L, &clear_close_exit, julia);
	mlx_mouse_hook(julia->set.lnk.mlx_win, mouse_hook, julia);
}

