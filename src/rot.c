/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:52:23 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 20:07:28 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	rot_im(int keycode, t_mlx *i)
{
	if (keycode == 69)
		add_zoom(i);
	else if ((keycode == 78) && (i->zoom > 0.1))
		i->zoom /= 1.1;
	else if ((keycode == 75) && (i->iter > 2))
		i->iter -= 50;
	else if (keycode == 67)
		i->iter += 50;
	else if (keycode == 49)
		i->p = !(i->p);
	else if (keycode == 35)
		ph_change(i);
	else if (keycode == 30)
		w_plus(i);
	else if ((keycode == 33) && (i->wid > 5))
		i->wid -= 5;
	else if ((keycode == 12) && ((i->cen - i->wid) > 10))
		i->cen -= 5;
	else if ((keycode == 14) && ((i->cen + i->wid) < 245))
		i->cen += 5;
	else if ((keycode == 0) && (i->f > 0.0))
		i->f -= 0.01;
	else if ((keycode == 2) && (i->f < 1))
		i->f += 0.01;
}

void	move_im(int keycode, t_mlx *i)
{
	if (keycode == 123)
		i->movx -= 0.3 / i->zoom;
	else if (keycode == 124)
		i->movx += 0.3 / i->zoom;
	else if (keycode == 126)
		i->movy -= 0.3 / i->zoom;
	else if (keycode == 125)
		i->movy += 0.3 / i->zoom;
	else if (keycode == 256)
	{
		i->iter = 128;
		i->zoom = 0.5;
		i->movx = 0;
		i->movy = 0;
		i->p = 1;
	}
}

void	make_zoom(t_mlx *i, float x, float y, int q)
{
	if (q)
	{
		i->zoom *= 1.1;
		i->movx += -((730 - x) / 1000) / i->zoom;
		i->movy += -((350 - y) / 700) / i->zoom;
	}
	else
	{
		i->zoom /= 1.1;
		i->movx += -((730 - x) / 1000) / i->zoom;
		i->movy += -((350 - y) / 700) / i->zoom;
	}
}

int		mouse_hook(int b, int x, int y, t_mlx *i)
{
	if (b == 4)
		make_zoom(i, x, y, 0);
	else if ((b == 5) && (ft_strequ(i->av, "7")) && (i->zoom > 1))
		return (0);
	else if (b == 5)
		make_zoom(i, x, y, 1);
	make_im(i);
	return (0);
}

int		key_hook(int keycode, t_mlx *info)
{
	if (keycode == 53)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	else if (keycode > 120)
		move_im(keycode, info);
	else if (keycode < 120)
		rot_im(keycode, info);
	make_im(info);
	return (0);
}
