/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:39:17 by moatieh           #+#    #+#             */
/*   Updated: 2026/01/31 18:39:17 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_values(t_app *app)
{
	app->zoom = 1.0;
	app->shift_x = 0.0;
	app->shift_y = 0.0;
	app->max_iter = 100;
}

static void	init_image(t_app *app)
{
	app->img = mlx_new_image(app->mlx, WIN_W, WIN_H);
	app->pix = mlx_get_data_addr(app->img, &app->bpp, &app->line, &app->endian);
}

void	start_app(t_app *app, char **av)
{
	(void)av;
	app->mlx = mlx_init();
	if (!app->mlx)
		quit_app(app, 0);
	app->win = mlx_new_window(app->mlx, WIN_W, WIN_H, "fractol");
	if (!app->win)
		quit_app(app, 0);
	init_values(app);
	init_image(app);
	draw_view(app);
	mlx_key_hook(app->win, key_event, app);
	mlx_mouse_hook(app->win, mouse_event, app);
	mlx_hook(app->win, 17, 0, close_event, app);
	mlx_loop(app->mlx);
}
