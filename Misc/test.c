#include "fractol.h"

/*
typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}			t_vars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;
typedef struct s_mlxsetup
{
	t_vars	lnk;
	t_img	img;
}			t_mlxsetup;
typedef struct s_coor
{
	double	x;
	double	y;
}			t_coor;

typedef struct s_cplx
{
	t_coor		z;
	t_coor		c;
	t_coor		tmp;
	double		r;
	double		imax;
	t_mlxsetup	set;
}				t_cplx;

typedef struct s_throd
{
	t_cplx		*cplx;
	size_t		i;
	t_coor		px;
	t_coor		z;
	t_coor		tmp;
	pthread_t	thread;
}			t_throd;

typedef struct s_thread
{
	size_t		i;
	pthread_t	thread;
}				t_thread;

typedef struct s_tcplx
{
	t_thread	t[8];
	size_t		i;
	t_coor		px;
	t_coor		z;
	t_coor		c;
	t_coor		tmp;
	t_mlxsetup	set;
	double		r;
	double		imax;
}				t_tcplx;


enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	julia_init(t_tcplx *julia, t_mlxsetup *set);

void	julia_z_incr(t_throd *julia);

void	julia_z_incr(t_tcplx *julia);

void	julia_iter(t_throd *julia);

void	julia_iter(t_tcplx *julia);

void	julia_set(t_tcplx *julia);

void	julia_calc(t_throd *julia);

void	julia_calc(t_tcplx *julia);

void	julia_display(t_mlxsetup *set, t_tcplx *julia);

 */
/*
void	julia_init(t_tcplx *julia, t_mlxsetup *set)
{
	julia->z.x = 0;
	julia->z.y = 0;
	julia->c.x = -0.4;
	julia->c.y = 0.6;
	julia->r = 2;
	julia->imax = 50;
	julia->set = *set;
}

void	julia_z_incr(t_tcplx *julia)
{
	julia->z.x = ((julia->px.x / (WIDTH / (julia->r * 2)) - \
	julia->r) \
	* WIDTH / HEIGHT);
	julia->z.y = (julia->r - (julia->px.y / (HEIGHT / \
	(julia->r * 2))));
}

void	julia_iter(t_tcplx *julia)
{
	julia->tmp.x = pow(julia->z.x, 2) - pow(julia->z.y, 2) + julia->c.x;
	julia->z.y = 2 * julia->z.x * julia->z.y + julia->c.y;
	julia->z.x = julia->tmp.x;
}

void	julia_set(t_tcplx *julia)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		julia->i = i;
		julia->z.x = 0;
		julia->z.y = 0;
		pthread_create(&julia->t[i].thread, NULL, (void *)julia_calc, &julia);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		pthread_join(julia->t[i].thread, NULL);
		i++;
	}
}

void	julia_seq(t_tcplx	*julia)
{
	size_t	i;

	julia_z_incr(julia);
	i = 1;
	while (zmod2(&julia->z) < 4. && i < julia->imax && i++)
	{
		julia_iter(julia);
	}
	if (i == julia->imax)
		my_mlx_pixel_put(&julia->set.img, julia->px.x, julia->px.y, \
		0x00FFFFFF);
	else
		my_mlx_pixel_put(&julia->set.img, julia->px.x, julia->px.y, \
		0x00a2dcc7 * i / 10000);
}

void	julia_calc(t_tcplx *julia)
{
	julia->px.x = WIDTH / 8 * (julia->i);
	while (julia->px.x < WIDTH / 8 * (julia->i + 1))
	{
		julia->px.y = 0;
		while (julia->px.y < HEIGHT)
		{
			julia_seq(julia);
			julia->px.y++;
		}
		julia->px.x++;
	}
}

void	julia_display(t_mlxsetup *set, t_tcplx *julia)
{
	julia_init(julia, set);
	julia_set(julia);
	mlx_put_image_to_window(julia->set.lnk.mlx, julia->set.lnk.mlx_win, \
	julia->set.img.img, 0, 0);
	//hooks(julia);
} */
