/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 00:23:32 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/28 14:22:11 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	value0to2(t_color *color, float f, int i)
{
	if (i == 0)
	{
		color->r = color->v * 255;
		color->g = color->v * (1 - color->s * (1 - f)) * 255;
		color->b = color->v * (1 - color->s) * 255;
	}
	else if (i == 1)
	{
		color->r = color->v * (1 - color->s * f) * 255;
		color->g = color->v * 255;
		color->b = color->v * (1 - color->s) * 255;
	}
	else if (i == 2)
	{
		color->r = color->v * (1 - color->s) * 255;
		color->g = color->v * 255;
		color->b = color->v * (1 - color->s * (1 - f)) * 255;
	}
}

void	value3to5(t_color *color, float f, int i)
{
	if (i == 3)
	{
		color->r = color->v * (1 - color->s) * 255;
		color->g = color->v * (1 - color->s * f) * 255;
		color->b = color->v * 255;
	}
	else if (i == 4)
	{
		color->r = color->v * (1 - color->s * (1 - f)) * 255;
		color->g = color->v * (1 - color->s) * 255;
		color->b = color->v * 255;
	}
	else
	{
		color->r = color->v * 255;
		color->g = color->v * (1 - color->s) * 255;
		color->b = color->v * (1 - color->s * f) * 255;
	}
}

void	hsv2rgb(t_color *color)
{
	float	f;
	int		i;

	i = (int)floor(color->h);
	f = color->h - i;
	if (i < 3)
		value0to2(color, f, i);
	else
		value3to5(color, f, i);
}

// come integer from 0 to 50
// change to hsv color and return rgb color
int	color2rainbow(int i)
{
	t_color	color;

	color.h = i * 0.12;
	color.s = 1.0;
	color.v = 1.0;
	if (color.s == 0)
	{
		color.r = color.v * 255;
		color.g = color.v * 255;
		color.b = color.v * 255;
		return (color.r << 16 | color.g << 8 | color.b);
	}
	hsv2rgb(&color);
	return (color.r << 16 | color.g << 8 | color.b);
}
