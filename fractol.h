/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:23:36 by moatieh           #+#    #+#             */
/*   Updated: 2026/01/31 18:23:36 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define WIN_W 800
# define WIN_H 800
# define MODE_MANDEL 1
# define MODE_JULIA 2

typedef struct s_app
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pix;
	int		bpp;
	int		line;
	int		endian;
	double	zoom;
	double	shift_x;
	double	shift_y;
	double	c_re;
	double	c_im;
	int		max_iter;
	int		mode;
}			t_app;
void		start_app(t_app *app, char **av);
void		draw_view(t_app *app);
void		put_dot(t_app *app, int x, int y, int color);
int			calc_mandel(double x, double y, t_app *app);
int			calc_julia(double x, double y, t_app *app);
int			key_event(int keycode, t_app *app);
int			close_event(t_app *app);
int			mouse_event(int button, int x, int y, t_app *app);
int			pick_color(int iter, int max);
double		ft_atod(char *s);
void		quit_app(t_app *app, char *msg);

#endif
