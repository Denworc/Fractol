/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:49:59 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 18:55:11 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_error_check(int n)
{
	if (n == 1)
	{
		ft_putstr("usage: ./fractol #\n1 - Mandelbrot set\n2 - Julia set\n");
		ft_putstr("3 - Burning Ship\n4 - Spider\n5 - Newton\n");
		ft_putstr("6 - Biomorphs\n7 - Binary tree\n");
		ft_putstr("*Maximum 2 parameters\n");
		exit(0);
	}
	return (0);
}

int		exit_hook(t_mlx *info)
{
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

void	ph_change(t_mlx *i)
{
	if (i->phb == 6)
		i->phb = 0;
	else
		i->phb++;
	if (i->phg > 4)
		i->phg = abs(5 - i->phg);
	else
		i->phg += 2;
	if (i->phr > 2)
		i->phr = abs(3 - i->phr);
	else
		i->phr += 4;
}

void	w_plus(t_mlx *i)
{
	if (((i->cen + i->wid) < 245) && ((i->cen - i->wid) > 10))
		i->wid += 5;
}

void	add_zoom(t_mlx *i)
{
	if ((ft_strequ(i->av, "7")) && (i->zoom > 1))
		return ;
	else
		i->zoom *= 1.1;
}
