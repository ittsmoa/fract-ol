/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:41:10 by moatieh           #+#    #+#             */
/*   Updated: 2026/01/31 18:41:10 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandel(double x, double y, t_app *app)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < app->max_iter)
	{
		tmp = zr * zr - zi * zi + x;
		zi = 2.0 * zr * zi + y;
		zr = tmp;
		i++;
	}
	return (i);
}

int	calc_julia(double x, double y, t_app *app)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = x;
	zi = y;
	i = 0;
	while (zr * zr + zi * zi <= 4.0 && i < app->max_iter)
	{
		tmp = zr * zr - zi * zi + app->c_re;
		zi = 2.0 * zr * zi + app->c_im;
		zr = tmp;
		i++;
	}
	return (i);
}
