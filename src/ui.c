/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:56:22 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 15:47:35 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	add_ui(t_mlx *i)
{
	mlx_string_put(i->mlx, i->win, 70, 35, 0xE89000, "Controls");
	mlx_string_put(i->mlx, i->win, 25, 80, 0xE89000, "Move = ^ v < >");
	mlx_string_put(i->mlx, i->win, 25, 110, 0xE89000, "Zoom :");
	mlx_string_put(i->mlx, i->win, 35, 140, 0xE89000, "+/- or mouse wheel");
	mlx_string_put(i->mlx, i->win, 25, 170, 0xE89000, "Reset move = LCtrl");
	mlx_string_put(i->mlx, i->win, 25, 200, 0xE89000, "Pause = Space bar");
	mlx_string_put(i->mlx, i->win, 25, 230, 0xE89000, "Quit = Esc");
	mlx_string_put(i->mlx, i->win, 25, 290, 0xE89000, "Color:");
	mlx_string_put(i->mlx, i->win, 35, 320, 0xE89000, "Frequency = A D");
	mlx_string_put(i->mlx, i->win, 35, 350, 0xE89000, "Center = Q E");
	mlx_string_put(i->mlx, i->win, 35, 380, 0xE89000, "Delta = { }");
	mlx_string_put(i->mlx, i->win, 35, 410, 0xE89000, "Phase = P");
	mlx_string_put(i->mlx, i->win, 35, 450, 0xE89000, "Iterations = / *");
}

void	make_l(t_mlx *i)
{
	int		h;
	int		x;
	int		z;

	z = -1;
	h = 700;
	i->img = mlx_new_image(i->mlx, 2, 700);
	i->tab = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->e);
	while (h > 0)
	{
		x = 2;
		while (x > 0)
		{
			i->tab[++z] = 0x00;
			i->tab[++z] = 0x90;
			i->tab[++z] = 0xE8;
			i->tab[++z] = 0;
			x--;
		}
		z = z - 8;
		z = z + (i->sl);
		h--;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img, 230, 1);
}

void	make_pix(t_mlx *i, int x, int y, int c)
{
	long long	z;

	if (((x > 0) && (x < 1000)) && ((y > 0) && (y < 700)))
	{
		z = (i->sl) * (y) + 4 * x;
		i->tab[z] = (unsigned char)(sin(i->f * c + i->phr) * i->wid + i->cen);
		i->tab[++z] = (unsigned char)(sin(i->f * c + i->phg) * i->wid + i->cen);
		i->tab[++z] = (unsigned char)(sin(i->f * c + i->phb) * i->wid + i->cen);
		i->tab[++z] = 0;
	}
	else
		return ;
}

void	init_mandel(t_set *i)
{
	i->c = (t_cd *)malloc(sizeof(t_cd));
	i->t = (t_cd *)malloc(sizeof(t_cd));
	i->z = (t_cd *)malloc(sizeof(t_cd));
	i->r = (t_cd *)malloc(sizeof(t_cd));
}

void	calc_line(int d[3], int s[2], t_set *w, int err[2])
{
	err[1] = err[0] * 2;
	if (err[1] > -d[1])
	{
		err[0] -= d[1];
		w->z->x += s[0];
	}
	if (err[1] < d[0])
	{
		err[0] += d[0];
		w->z->y += s[1];
	}
}
