/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ship.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:23:15 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 15:16:56 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	b_ship_(t_mlx *i, t_set *w, int x[3], int mx)
{
	w->c->x = 1.5 * (x[1] - mx / 2) / (0.5 * i->zoom * mx) + i->movx;
	w->c->y = (x[0] - 700 / 2) / (0.5 * i->zoom * 700) + i->movy;
	w->z->x = 0;
	w->z->y = 0;
	while (++x[2] < i->iter)
	{
		w->t->x = w->z->x;
		w->t->y = w->z->y;
		w->z->x = fabsf(w->t->x * w->t->x - w->t->y * w->t->y + w->c->x);
		w->z->y = fabsf(2 * w->t->x * w->t->y + w->c->y);
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

void	b_ship(t_mlx *i, int mx, int p[2], int x[3])
{
	t_set	w;

	init_mandel(&w);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			b_ship_(i, &w, x, mx);
		x[1] = -1;
	}
}
