
void	newton_init(t_cplx *newton, t_mlxsetup *set)
{
	newton->name = NEWTON;
	newton->px.x = 0;
	newton->px.y = 0;
	newton->z.x = 0;
	newton->z.y = 0;
	newton->q.x = 1;
	newton->q.y = 0;
	newton->r = 2;
	newton->imax = 100;
	newton->zoom = 1;
	newton->move.x = 0;
	newton->move.y = 0;
	newton->set = *set;
	newton->pow = 2;
	newton->imgprt = &newton->set.img;
	newton->imgdsp = &newton->set.img2;
	newton->a = 1;
	newton->b = 1.5;
	newton->cc = 1.5;
	newton->d = 1;
}

void	newton_z_incr(t_cplx *newton)
{
	newton->z.x = ((2 * newton->r * newton->px.x / WIDTH - newton->r) * \
	newton->zoom * RATIO + newton->move.x);
	newton->z.y = ((newton->r - 2 * newton->r * newton->px.y / HEIGHT) * \
	newton->zoom + newton->move.y);
	newton->c.x = ((2 * newton->r * newton->px.x / WIDTH - newton->r) * \
	newton->zoom * RATIO + newton->move.x);
	newton->c.y = ((newton->r - 2 * newton->r * newton->px.y / HEIGHT) * \
	newton->zoom + newton->move.y);
}

// void	newton_iter(t_cplx *newton)
// {
// 	double	denom;

// 	newton->old.x = newton->z.x;
// 	newton->old.y = newton->z.y;
// 	denom = newton->a * ft_pow(ft_pow(newton->z.x, 2) + ft_pow(newton->z.y, 2), 2);
// 	newton->tmp.x = (1/3) * (newton->z.x / 3 + (newton->d * (ft_pow(newton->z.x, 2) - ft_pow(newton->z.y, 2))) / (3 * denom));
// 	newton->tmp.y = (newton->z.y * denom - 2 * newton->d * newton->z.x) / (3 * denom);
// 	newton->z.x = newton->z.x - newton->tmp.x;
// 	newton->z.y = newton->z.y - newton->tmp.y;
// 	newton->tmp.y = ft_pow(newton->z.x - newton->old.x, 2) + \
// 	ft_pow(newton->z.y - newton->old.y, 2);
// }
void	newton_iter(t_cplx *newton)
{
	double	denom;

	newton->old.x = newton->z.x;
	newton->old.y = newton->z.y;
	denom = (9 * ft_pow(newton->a, 2) * ft_pow(newton->z.x, 4) + 9 * ft_pow(newton->a, 2) * ft_pow(newton->z.y, 4) + 4 * ft_pow(newton->b, 2) * ft_pow(newton->z.x, 2) + 4 * ft_pow(newton->b, 2) * ft_pow(newton->z.y, 2) + 27 * ft_pow(newton->a, 2) * ft_pow(newton->z.x, 2) * ft_pow(newton->z.y, 2) + 12 * newton->a * ft_pow(newton->z.x, 3) * newton->b + 6 * newton->a * ft_pow(newton->z.x, 2) * newton->cc - 9 * ft_pow(newton->a, 2) * ft_pow(newton->z.y, 2) * ft_pow(newton->z.x, 2) - 6 * newton->a * ft_pow(newton->z.y, 2) * newton->cc + 4 * newton->b * newton->cc * newton->z.x + 12 * newton->a * newton->b * newton->z.x * ft_pow(newton->z.y, 2) + ft_pow(newton->cc, 2));
	newton->tmp.x = (-newton->d * newton->cc + 6 * ft_pow(newton->a, 2) * ft_pow(newton->z.x, 5) + 2 * ft_pow(newton->z.x, 3) * ft_pow(newton->b, 2) + ft_pow(newton->z.x, 2) * newton->b * newton->cc - newton->b * ft_pow(newton->z.y, 2) * newton->cc + 12 * ft_pow(newton->a, 2) * ft_pow(newton->z.x, 3) * ft_pow(newton->z.y, 2) + 7 * newton->a * ft_pow(newton->z.x, 4) * newton->b + 2 * newton->a * ft_pow(newton->z.x, 3) * newton->cc + 6 * newton->z.x * ft_pow(newton->a, 2) * ft_pow(newton->z.y, 4) - newton->a * newton->b * ft_pow(newton->z.y, 4) + 2 * newton->z.x * ft_pow(newton->b,2) * ft_pow(newton->z.y,2) - 3 * newton->a * ft_pow(newton->z.x,2) * newton->d + 3 * newton->a * ft_pow(newton->z.y, 2) * newton->d - 2 * newton->b * newton->d * newton->z.x + 6 * newton->a * ft_pow(newton->z.x, 2) * newton->b * ft_pow(newton->z.y,2) - 6 * newton->a * newton->z.x * ft_pow(newton->z.y,2) * newton->cc) / denom;
	newton->z.y = (2 * ft_pow(newton->b, 2) * ft_pow(newton->z.y, 3) + 6 * ft_pow(newton->a, 2) * ft_pow(newton->z.y, 5) + 6 * ft_pow(newton->a, 2) * ft_pow(newton->z.x, 4) * newton->z.y + 12 * ft_pow(newton->a, 2) * ft_pow(newton->z.x, 2) * ft_pow(newton->z.y, 3) + 2 * ft_pow(newton->z.x, 2) * newton->z.y * ft_pow(newton->b, 2) + 2 * newton->b * newton->d * newton->z.y - 2 * newton->a * ft_pow(newton->z.y, 3) * newton->cc + 8 * newton->a * ft_pow(newton->z.x, 3) * newton->b * newton->z.y + 8 * newton->a * ft_pow(newton->z.x,3) * newton->b * newton->z.y + 8 * newton->a * newton->b * newton->z.x * ft_pow(newton->z.y, 3) + 6 * newton->a * newton->d * newton->z.x * newton->z.y + 6 * newton->a * ft_pow(newton->z.x, 2) * newton->cc * newton->z.y + 2 * newton->b * newton->cc * newton->z.x * newton->z.y + ft_pow(newton->cc, 2)) / denom;
	newton->z.x = newton->tmp.x;
	newton->tmp.y = ft_pow(newton->z.x - newton->old.x, 2) + \
	ft_pow(newton->z.y - newton->old.y, 2);
}

void	newton_set(t_cplx *newton)
{
	size_t	i;

	newton->px.x = 0;
	while (newton->px.x < WIDTH)
	{
		newton->px.y = 0;
		while (newton->px.y < HEIGHT)
		{
			newton_z_incr(newton);
			i = 1;
			newton->tmp.y = 1;
			while (newton->tmp.y > 0.001 && i < newton->imax && i++)
				newton_iter(newton);
			if (i == newton->imax)
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x00FF0000);
			// else if (newton->z.x <= 0.001 * -1)
			// 	my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
			// 	0x00ABBDFF + (i << 8)); //0x00a2dcc7 * i / 1000000
			// else if (newton->z.x >= 0.00001 * 1 && newton->z.y > 0)
			// 	my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
			// 	0x00894B77 + (i << 8)); //0x00a2dcc7 * i / 1000000
			// else if (newton->z.x >= 0.00001 * 1 && newton->z.y < 0)
			// 	my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
			// 	0x0099e1d9 + (i << 8)); //0x00a2dcc7 * i / 1000000
			else
				my_mlx_pixel_put(newton->imgprt, newton->px.x, newton->px.y, \
				0x00a2dcc7 * i / 1000000); //0x00a2dcc7 * i / 1000000
			newton->px.y++;
		}
		newton->px.x++;
	}
	switchimg(newton);
}

void	newton_display(t_mlxsetup *set, t_cplx *fractal)
{
	newton_init(fractal, set);
	newton_set(fractal);
	mlx_put_image_to_window(fractal->set.lnk.mlx, fractal->set.lnk.mlx_win, \
	fractal->imgdsp->img, 0, 0);
}
