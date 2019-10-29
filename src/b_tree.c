/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:16:02 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 15:22:32 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	b_tree_(t_mlx *i, t_set *w, float l, int p[2])
{
	float	a;
	float	y;
	float	x;
	float	c;

	if (l < 2)
		return ;
	w->c->x = floor(w->z->x + l * cos(w->r->x));
	w->c->y = floor(w->z->y + l * sin(w->r->x));
	drawline(i, w, p);
	w->t->y += 1;
	w->z->y = w->c->y;
	w->z->x = w->c->x;
	y = w->z->y;
	x = w->z->x;
	a = w->r->x;
	c = w->t->y;
	w->r->x += 3.141592653 / 4 + ((i->x - 500) * 3.141592653 / 1000);
	b_tree_(i, w, (l * 0.65 * i->zoom), p);
	w->z->y = y;
	w->z->x = x;
	w->t->y = c;
	w->r->x = a - 3.141592653 / 4 + ((i->x - 500) * 3.141592653 / 1000);
	b_tree_(i, w, (l * 0.65 * i->zoom), p);
}

void	b_tree(t_mlx *i, int mx, int p[2], int x[3])
{
	t_set	w;

	mx = 0;
	init_mandel(&w);
	w.z->x = 500;
	w.z->y = 700;
	w.t->x = 700 * 0.3 * i->zoom;
	w.t->y = 1;
	w.r->x = -3.141592653 / 2 + ((i->x - 500) * 3.141592653 / 1000);
	x[2] = 1;
	b_tree_(i, &w, w.t->x, p);
}
