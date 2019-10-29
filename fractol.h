/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 01:30:35 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/18 20:00:50 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H
# include "libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# include <math.h>

typedef	struct s_mlx	t_mlx;
typedef	struct s_cd		t_cd;
typedef	struct s_f		t_f;
typedef	struct s_set	t_set;

struct		s_set
{
	t_cd	*c;
	t_cd	*t;
	t_cd	*z;
	t_cd	*r;
	float	tmp;
};

struct		s_cd
{
	float	x;
	float	y;
};

struct		s_mlx
{
	void	*mlx;
	void	*win;
	void	*win2;
	char	*title;
	float	movx;
	float	movy;
	float	zoom;
	void	*img;
	void	*img2;
	char	*tab;
	int		bpp;
	int		sl;
	int		e;
	int		iter;
	int		max;
	char	*av;
	int		p;
	float	cre;
	float	cim;
	float	tmp;
	int		phr;
	int		phg;
	int		phb;
	int		cen;
	int		wid;
	float	f;
	int		q;
	float	x;
	float	y;
	int		ch;
	int		fn;
};

struct		s_f
{
	t_mlx	*i;
	int		y;
};

void		my_pid(t_mlx *i, char *av);
void		my_hooks(t_mlx *i);
int			expose_hook(t_mlx *i);
int			motion_hook(int x, int y, t_mlx *i);
void		init_info(t_mlx *i);
void		init_info_(t_mlx *i);
void		make_im(t_mlx *i);
void		add_f(t_mlx *i);
void		*operate_fl(void *th);
void		newton(t_mlx *i, int mx, int p[2], int x[3]);
void		newton_(t_mlx *i, t_set *w, int x[3], int mx);
void		spider(t_mlx *i, int mx, int p[2], int x[3]);
void		spider_(t_mlx *i, t_set *w, int x[3], int mx);
void		b_ship(t_mlx *i, int mx, int p[2], int x[3]);
void		b_ship_(t_mlx *i, t_set *w, int x[3], int mx);
void		julia(t_mlx *i, int mx, int p[2], int x[3]);
void		julia_(t_mlx *i, t_set *w, int x[3], int mx);
void		mandelbrot(t_mlx *i, int mx, int p[2], int x[3]);
void		mandelbrot_(t_mlx *i, t_set *w, int x[3], int mx);
void		bio(t_mlx *i, int mx, int p[2], int x[3]);
void		bio_(t_mlx *i, t_set *w, int x[3], int mx);
void		b_tree(t_mlx *i, int mx, int p[2], int x[3]);
void		b_tree_(t_mlx *i, t_set *w, float l, int p[2]);
void		drawline(t_mlx *i, t_set *w, int p[2]);
void		fill_line(int d[3], int s[2], t_set *w, int err[2]);
void		calc_line(int d[3], int s[2], t_set *w, int err[2]);
void		init_mandel(t_set *i);
void		make_pix(t_mlx *i, int x, int y, int c);
void		make_l(t_mlx *i);
void		add_ui(t_mlx *i);
int			key_hook(int keycode, t_mlx *info);
int			mouse_hook(int b, int x, int y, t_mlx *i);
void		make_zoom(t_mlx *i, float x, float y, int q);
void		move_im(int keycode, t_mlx *i);
void		rot_im(int keycode, t_mlx *i);
void		add_zoom(t_mlx *i);
void		w_plus(t_mlx *i);
void		ph_change(t_mlx *i);
int			exit_hook(t_mlx *info);
int			ft_error_check(int n);

#endif
