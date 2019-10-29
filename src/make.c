/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 16:35:30 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 20:09:02 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		motion_hook(int x, int y, t_mlx *i)
{
	if ((x >= 230 && x <= 1230) && (y >= 0 && y <= 700))
	{
		if (!(i->p))
		{
			i->x = x - 230;
			i->y = y;
			if ((ft_strequ(i->av, "2")) || (ft_strequ(i->av, "6")) ||
				(ft_strequ(i->av, "7")))
				make_im(i);
		}
	}
	return (0);
}

int		expose_hook(t_mlx *i)
{
	if (i->ch)
		make_im(i);
	i->ch = 0;
	return (0);
}

void	my_hooks(t_mlx *i)
{
	mlx_hook(i->win, 2, 0, key_hook, i);
	mlx_mouse_hook(i->win, mouse_hook, i);
	mlx_hook(i->win, 6, 0, motion_hook, i);
	mlx_hook(i->win, 17, 0, exit_hook, i);
	mlx_loop(i->mlx);
}

void	my_pid(t_mlx *i, char *av)
{
	if (!(ft_strequ(av, "1") || ft_strequ(av, "2") ||
			ft_strequ(av, "3") || ft_strequ(av, "4") ||
			ft_strequ(av, "5") || ft_strequ(av, "6") ||
			ft_strequ(av, "7")))
		ft_error_check(1);
	i->av = av;
	i->mlx = mlx_init();
	init_info(i);
	i->win = mlx_new_window(i->mlx, 1230, 700, i->title);
	add_ui(i);
	make_l(i);
	make_im(i);
	my_hooks(i);
}
