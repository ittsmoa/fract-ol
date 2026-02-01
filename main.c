/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:26:20 by moatieh           #+#    #+#             */
/*   Updated: 2026/02/01 16:00:17 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	same_str(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] == 0 && b[i] == 0)
		return (1);
	return (0);
}

static int	set_mode(t_app *app, int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (same_str(av[1], "mandelbrot"))
	{
		app->mode = MODE_MANDEL;
		app->c_re = 0.0;
		app->c_im = 0.0;
		return (1);
	}
	if (ac == 4 && same_str(av[1], "julia"))
	{
		app->mode = MODE_JULIA;
		app->c_re = ft_atod(av[2]);
		app->c_im = ft_atod(av[3]);
		return (1);
	}
	return (0);
}

static void	show_usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "./fractol mandelbrot\n", 21);
	write(1, "./fractol julia <re> <im>\n", 26);
}

int	main(int ac, char **av)
{
	t_app	app;

	if (!set_mode(&app, ac, av))
	{
		show_usage();
		return (1);
	}
	start_app(&app, av);
	return (0);
}
