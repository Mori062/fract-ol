/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/25 21:38:15 by morishitash      ###   ########.fr       */
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

int	mandelbrot(t_data *img, int zoom_scale)
{
	double			x;
	double			y;
	double			i;

	x = 0;
	while (x < DPHEI)
	{
		y = 0;
		while (y < DPWID)
		{
			img->cx = (x - DPWID / 2) * 4.0 / DPWID * zoom_scale;
			img->cy = (y - DPHEI / 2) * 4.0 / DPWID * zoom_scale;
			img->c_re = 0;
			img->c_im = 0;
			img->tmp = 0;
			i = 0;
			while (i < 50)
			{
				img->tmp = img->c_re * img->c_re - img->c_im * img->c_im + img->cx;
				img->c_im = 2 * img->c_re * img->c_im + img->cy;
				img->c_re = img->tmp;
				if (img->c_re * img->c_re + img->c_im * img->c_im < 4)
				{
					my_mlx_pixel_put(img, x, y, 0xFFFFFF / 50 * i);
				}
				i++;
			}
			y++;
		}
		x++;
	}
	return (0);
}
