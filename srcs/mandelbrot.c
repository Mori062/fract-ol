/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/28 14:42:51 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	mandelbrot_init(t_data *img, float x, float y, float zoom_scale)
{
	img->cx = (x - DISPLAY_WIDTH / 1.5) / DISPLAY_WIDTH * 4.0 * zoom_scale;
	img->cy = (y - DISPLAY_HEIGHT / 2) / DISPLAY_WIDTH * 4.0 * zoom_scale;
	img->c_re = img->cx;
	img->c_im = img->cy;
	img->tmp = 0;
}

static void	mandelbrot_calculate(t_data *img)
{
	img->tmp = pow(img->cx, 2) - pow(img->cy, 2) + img->c_re;
	img->cy = 2 * img->cx * img->cy + img->c_im;
	img->cx = img->tmp;
}

void	mandelbrot(t_data *img, float zoom_scale)
{
	float	x;
	float	y;
	int		i;

	x = 0;
	while (x < DISPLAY_WIDTH)
	{
		y = 0;
		while (y < DISPLAY_HEIGHT)
		{
			mandelbrot_init(img, x, y, zoom_scale);
			i = 0;
			while (i < (30 / sqrt(zoom_scale)))
			{
				mandelbrot_calculate(img);
				if (pow(img->cx, 2) + pow(img->cy, 2) < 4)
					my_mlx_pixel_put(img, x, y, color2rainbow(i));
				i++;
			}
			y++;
		}
		x++;
	}
}
