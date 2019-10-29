/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spider.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:24:57 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 15:10:25 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	spider_(t_mlx *i, t_set *w, int x[3], int mx)
{
	w->z->x = 1.5 * (x[1] - mx / 2) / (0.5 * i->zoom * mx) + i->movx;
	w->z->y = (x[0] - 700 / 2) / (0.5 * i->zoom * 700) + i->movy;
	w->c->x = w->z->x;
	w->c->y = w->z->y;
	while (++x[2] < i->iter)
	{
		w->t->x = w->z->x;
		w->t->y = w->z->y;
		w->r->x = w->c->x;
		w->r->y = w->c->y;
		w->z->x = w->t->x * w->t->x - w->t->y * w->t->y + w->c->x;
		w->z->y = 2 * w->t->x * w->t->y + w->c->y;
		w->c->x = w->r->x / 2 + w->z->x;
		w->c->y = w->r->y / 2 + w->z->y;
		if ((w->z->x * w->z->x + w->z->y * w->z->y) > i->max)
			break ;
	}
	if (x[2] < i->iter)
	{
		x[2] = (x[2] + 1 - (log(2) / sqrt(w->z->x * w->z->x + w->z->y *
											w->z->y)) / log(2));
		make_pix(i, x[1], x[0], x[2]);
	}
	x[2] = -1;
}

void	spider(t_mlx *i, int mx, int p[2], int x[3])
{
	t_set	w;

	init_mandel(&w);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			spider_(i, &w, x, mx);
		x[1] = -1;
	}
}
