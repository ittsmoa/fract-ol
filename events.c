/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:42:11 by moatieh           #+#    #+#             */
/*   Updated: 2026/02/01 16:01:17 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_event(t_app *app)
{
	quit_app(app, 0);
	return (0);
}

int	key_event(int keycode, t_app *app)
{
	if (keycode == 65307)
		quit_app(app, 0);
	if (keycode == 65361)
		app->shift_x -= 0.05 / app->zoom;
	if (keycode == 65363)
		app->shift_x += 0.05 / app->zoom;
	if (keycode == 65362)
		app->shift_y -= 0.05 / app->zoom;
	if (keycode == 65364)
		app->shift_y += 0.05 / app->zoom;
	draw_view(app);
	return (0);
}

int	mouse_event(int button, int x, int y, t_app *app)
{
	double	factor;

	(void)x;
	(void)y;
	factor = 1.2;
	if (button == 4)
		app->zoom *= factor;
	if (button == 5)
		app->zoom /= factor;
	draw_view(app);
	return (0);
}
