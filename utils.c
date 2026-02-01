/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:36:51 by moatieh           #+#    #+#             */
/*   Updated: 2026/02/01 04:42:18 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static double	parse_sign(char **s)
{
	double	sign;

	sign = 1.0;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1.0;
		(*s)++;
	}
	return (sign);
}

double	ft_atod(char *s)
{
	double	res;
	double	div;
	double	sign;

	res = 0.0;
	div = 1.0;
	sign = parse_sign(&s);
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10.0 + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		div *= 10.0;
		res += (*s - '0') / div;
		s++;
	}
	return (res * sign);
}

void	quit_app(t_app *app, char *msg)
{
	if (msg)
		write(2, msg, str_len(msg));
	if (app->img)
		mlx_destroy_image(app->mlx, app->img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	exit(0);
}
