/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:40:22 by moatieh           #+#    #+#             */
/*   Updated: 2026/01/31 18:40:22 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_dot(t_app *app, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dst = app->pix + (y * app->line + x * (app->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_view(t_app *app)
{
	int		x;
	int		y;
	int		iter;
	double	re;
	double	im;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			re = (x - WIN_W / 2.0) / (0.5 * app->zoom * WIN_W) + app->shift_x;
			im = (y - WIN_H / 2.0) / (0.5 * app->zoom * WIN_H) + app->shift_y;
			if (app->mode == MODE_MANDEL)
				iter = calc_mandel(re, im, app);
			else
				iter = calc_julia(re, im, app);
			put_dot(app, x, y, pick_color(iter, app->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img, 0, 0);
}
