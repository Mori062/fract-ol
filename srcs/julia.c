/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:17:31 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/28 14:42:19 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	julia_init(t_data *img, float x, float y, float zoom_scale)
{
	img->cx = (x - DISPLAY_WIDTH / 1.5) / DISPLAY_WIDTH * 4.0 * zoom_scale;
	img->cy = (y - DISPLAY_HEIGHT / 2) / DISPLAY_WIDTH * 4.0 * zoom_scale;
	img->tmp = 0;
}

static void	julia_calculate(t_data *img)
{
	img->tmp = pow(img->cx, 2) - pow(img->cy, 2) + img->c_re;
	img->cy = 2 * img->cx * img->cy + img->c_im;
	img->cx = img->tmp;
}

void	julia(t_data *img, float c_re, float c_im, float zoom_scale)
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
			julia_init(img, x, y, zoom_scale);
			img->c_re = c_re;
			img->c_im = c_im;
			i = 0;
			while (i < (30 / sqrt(zoom_scale)))
			{
				julia_calculate(img);
				if (img->cx * img->cx + img->cy * img->cy < 4)
					my_mlx_pixel_put(img, x, y, color2rainbow(i));
				i++;
			}
			y++;
		}
		x++;
	}
}
