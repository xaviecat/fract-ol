void	mendel_iter(t_cplx *mendel)
{
	mendel->tmp.x = ft_pow(mendel->z.x * mendel->z.x + mendel->z.y * mendel->z.y, \
	mendel->pow / 2) * cos(mendel->pow * atan2(mendel->z.y, mendel->z.x)) + \
	mendel->c.x;
	mendel->z.y = ft_pow(mendel->z.x * mendel->z.x + mendel->z.y * mendel->z.y, \
	mendel->pow / 2) * sin(mendel->pow * atan2(mendel->z.y, mendel->z.x)) + \
	mendel->c.y;
	mendel->z.x = mendel->tmp.x;
}

void	julia_iter(t_cplx *julia)
{
	julia->tmp.x = ft_pow(julia->z.x * julia->z.x + julia->z.y * julia->z.y, \
	julia->pow / 2) * cos(julia->pow * atan2(julia->z.y, julia->z.x)) + \
	julia->c.x;
	julia->z.y = ft_pow(julia->z.x * julia->z.x + julia->z.y * julia->z.y, \
	julia->pow / 2) * sin(julia->pow * atan2(julia->z.y, julia->z.x)) + \
	julia->c.y;
	julia->z.x = julia->tmp.x;
}
