/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:41:38 by moatieh           #+#    #+#             */
/*   Updated: 2026/02/01 04:36:27 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pick_color(int iter, int max)
{
	int	r;
	int	g;
	int	b;

	if (iter >= max)
		return (0x000000);
	r = (iter * 9) % 256;
	g = (iter * 4) % 256;
	b = (iter * 15) % 256;
	return (r << 16 | g << 8 | b);
}
