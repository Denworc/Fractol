/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:03:41 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/17 17:12:30 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int ac, char **av)
{
	pid_t	pid[2];
	t_mlx	i;
	int		j;

	j = 0;
	if (ac == 2)
		my_pid(&i, av[1]);
	else if (ac == 3)
		while (++j < ac)
		{
			pid[j] = fork();
			if (pid[1])
				my_pid(&i, av[2]);
			else
				my_pid(&i, av[j]);
		}
	else
		ft_error_check(1);
	return (0);
}
