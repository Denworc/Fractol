/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:59:42 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/17 17:10:02 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	fill_line(int d[3], int s[2], t_set *w, int err[2])
{
	d[0] = fabsf(w->c->x - w->z->x);
	d[1] = fabsf(w->c->y - w->z->y);
	s[0] = w->z->x < w->c->x ? 1 : -1;
	s[1] = w->z->y < w->c->y ? 1 : -1;
	err[0] = d[0] - d[1];
	if (d[0] > d[1])
		d[2] = d[0];
	else
		d[2] = d[1];
}

void	drawline(t_mlx *i, t_set *w, int p[2])
{
	int		d[3];
	int		s[2];
	int		err[2];

	fill_line(d, s, w, err);
	if ((w->z->y >= p[0]) && (w->z->y < p[1]))
		make_pix(i, w->z->x, w->z->y, w->t->y);
	while (w->z->x != w->c->x || w->z->y != w->c->y)
	{
		if ((w->z->y >= p[0]) && (w->z->y < p[1]))
			make_pix(i, w->z->x, w->z->y, w->t->y);
		calc_line(d, s, w, err);
	}
}
