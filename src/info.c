/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:32:08 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 15:32:51 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	*operate_fl(void *th)
{
	t_f		*fl;
	int		p[2];
	int		x[3];

	x[0] = -1;
	x[1] = -1;
	x[2] = -1;
	fl = (t_f*)th;
	p[0] = fl->y;
	p[1] = (700 / fl->i->fn + fl->y);
	ft_strequ(fl->i->av, "1") ? mandelbrot(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "2") ? julia(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "3") ? b_ship(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "4") ? spider(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "5") ? newton(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "6") ? bio(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "7") ? b_tree(fl->i, 1000, p, x) : (0);
	pthread_exit(NULL);
}

void	add_f(t_mlx *i)
{
	int			j;
	pthread_t	th[i->fn];
	t_f			fl[i->fn];

	j = -1;
	while (++j < i->fn)
	{
		fl[j].y = j * 700 / i->fn;
		fl[j].i = i;
		pthread_create(&th[j], NULL, operate_fl, (void*)&fl[j]);
	}
	j = -1;
	while (++j < i->fn)
		pthread_join(th[j], NULL);
}

void	make_im(t_mlx *i)
{
	mlx_destroy_image(i->mlx, i->img);
	i->img = mlx_new_image(i->mlx, 1000, 700);
	i->tab = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->e);
	add_f(i);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 232, 1);
}

void	init_info_(t_mlx *i)
{
	i->cre = -0.70176;
	i->cim = -0.3842;
	i->phr = 3;
	i->phg = 5;
	i->phb = 6;
	i->cen = 128;
	i->wid = 115;
	i->f = 0.02;
	i->q = -1;
	i->ch = 0;
	i->x = 500;
	i->y = 200;
	i->fn = 7;
}

void	init_info(t_mlx *i)
{
	ft_strequ(i->av, "1") ? (i->title = "Mandelbrot set") : (0);
	ft_strequ(i->av, "2") ? (i->title = "Julia set") : (0);
	ft_strequ(i->av, "3") ? (i->title = "Burning Ship") : (0);
	ft_strequ(i->av, "4") ? (i->title = "Spider") : (0);
	ft_strequ(i->av, "5") ? (i->title = "Newton fractal") : (0);
	ft_strequ(i->av, "6") ? (i->title = "Biomorphs") : (0);
	ft_strequ(i->av, "7") ? (i->title = "Binary tree") : (0);
	i->iter = 128;
	i->max = 4;
	i->zoom = 0.5;
	i->movx = 0;
	i->movy = 0;
	i->p = 1;
	init_info_(i);
}
