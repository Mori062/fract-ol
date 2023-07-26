/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:44:19 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/26 20:10:41 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

// hsv2rgb
int	hsv2rgb(double h, double s, double v, int *r, int *g, int *b)
{
	double	f;
	int		i;
	double	p;
	double	q;
	double	t;

	if (s == 0)
	{
		*r = v * 255;
		*g = v * 255;
		*b = v * 255;
		return (0);
	}
	h /= 60;
	i = (int)floor(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	if (i == 0)
		*r = v * 255, *g = t * 255, *b = p * 255;
	else if (i == 1)
		*r = q * 255, *g = v * 255, *b = p * 255;
	else if (i == 2)
		*r = p * 255, *g = v * 255, *b = t * 255;
	else if (i == 3)
		*r = p * 255, *g = q * 255, *b = v * 255;
	else if (i == 4)
		*r = t * 255, *g = p * 255, *b = v * 255;
	else
		*r = v * 255, *g = p * 255, *b = q * 255;
	return (0);
}

// come integer from 0 to 50
// change to hsv color and return rgb color
int	color2rainbow(int i)
{
	int		r;
	int		g;
	int		b;
	double	h;
	double	s;
	double	v;

	h = i * 1.0;
	s = 1.0;
	v = 1.0;
	h = h / 50 * 360;
	hsv2rgb(h, s, v, &r, &g, &b);
	return (r << 16 | g << 8 | b);
}
