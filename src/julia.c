/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:21:22 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 15:15:34 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_(t_mlx *i, t_set *w, int x[3], int mx)
{
	w->z->x = 1.5 * (x[1] - mx / 2) / (0.5 * i->zoom * mx) + i->movx;
	w->z->y = (x[0] - 700 / 2) / (0.5 * i->zoom * 700) + i->movy;
	while (++x[2] < i->iter)
	{
		w->t->x = w->z->x;
		w->t->y = w->z->y;
		w->z->x = w->t->x * w->t->x - w->t->y * w->t->y + i->cre;
		w->z->y = 2 * w->t->x * w->t->y + i->cim;
		if ((w->t->x * w->t->x + w->t->y * w->t->y) > i->max)
			break ;
	}
	if (x[2] < i->iter)
	{
		x[2] = (x[2] + 1 - (log(2) / sqrt(w->z->x * w->z->x +
											w->z->y * w->z->y)) / log(2));
		make_pix(i, x[1], x[0], x[2]);
	}
	x[2] = -1;
}

void	julia(t_mlx *i, int mx, int p[2], int x[3])
{
	t_set	w;

	init_mandel(&w);
	i->cre = (i->x * 4) / 1000 - 2;
	i->cim = (i->y * 4) / 700 - 2;
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			julia_(i, &w, x, mx);
		x[1] = -1;
	}
}
