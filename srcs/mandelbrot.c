/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/26 20:05:24 by shmorish         ###   ########.fr       */
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

void	mandelbrot(t_data *img, float zoom_scale)
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
			img->cx = (x - DPHEI / 1.5) / DPHEI * 4.0 * zoom_scale;
			img->cy = (y - DPWID / 2) / DPHEI * 4.0 * zoom_scale;
			img->c_re = 0;
			img->c_im = 0;
			img->tmp = 0;
			i = 0;
			while (i < 50 * (1 / zoom_scale))
			{
				img->tmp = img->c_re * img->c_re - img->c_im * img->c_im + img->cx;
				img->c_im = 2 * img->c_re * img->c_im + img->cy;
				img->c_re = img->tmp;
				if (img->c_re * img->c_re + img->c_im * img->c_im < 4)
					my_mlx_pixel_put(img, x, y, color2rainbow(i));
				i++;
			}
			y++;
		}
		x++;
	}
}

// void	mandelbrot(t_data *img, float zoom_scale)
// {
// 	double			x;
// 	double			y;
// 	double			i;

// 	x = 0;
// 	while (x < DPHEI)
// 	{
// 		y = 0;
// 		while (y < DPWID)
// 		{
// 			img->cx = (x - DPHEI / 1.5) / DPHEI * 4.0 * zoom_scale;
// 			img->cy = (y - DPWID / 2) / DPHEI * 4.0 * zoom_scale;
// 			img->tmp = 0;
// 			i = 0;
// 			img->c_re = 0;
// 			img->c_im = 0;
// 			while (i < 50)
// 			{
// 				img->tmp = img->cx * img->cx - img->cy * img->cy + img->c_re;
// 				img->cy = 2 * img->cx * img->cy + img->c_im;
// 				img->cx = img->tmp;
// 				if (img->cx * img->cx + img->cy * img->cy < 4)
// 					my_mlx_pixel_put(img, x, y, color2rainbow(i));
// 				i++;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }