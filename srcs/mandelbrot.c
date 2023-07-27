/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/27 20:43:48 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot_init(t_data *img, double x, double y, float zoom_scale)
{
	img->cx = (x - DPHEI / 1.5) / DPHEI * 4.0 * zoom_scale;
	img->cy = (y - DPWID / 2) / DPHEI * 4.0 * zoom_scale;
	img->c_re = img->cx;
	img->c_im = img->cy;
	img->tmp = 0;
}

void	mandelbrot(t_data *img, float zoom_scale)
{
	double			x;
	double			y;
	int				i;

	x = 0;
	while (x < DPHEI)
	{
		y = 0;
		while (y < DPWID)
		{
			mandelbrot_init(img, x, y, zoom_scale);
			i = 0;
			while (i < 50 * (1 / zoom_scale))
			{
				img->tmp = pow(img->cx, 2) - pow(img->cy, 2) + img->c_re;
				img->cy = 2 * img->cx * img->cy + img->c_im;
				img->cx = img->tmp;
				if (pow(img->cx, 2) + pow(img->cy, 2) < 4)
					my_mlx_pixel_put(img, x, y, color2rainbow(i));
				i++;
			}
			y++;
		}
		x++;
	}
}
