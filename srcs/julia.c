/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:17:31 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/27 21:06:38 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia_init(t_data *img, double x, double y, float zoom_scale)
{
	img->cx = (x - DPHEI / 1.5) / DPHEI * 4.0 * zoom_scale;
	img->cy = (y - DPWID / 2) / DPHEI * 4.0 * zoom_scale;
	img->tmp = 0;
}

void	julia_calculate(t_data *img)
{
	img->tmp = img->cx * img->cx - img->cy * img->cy + img->c_re;
	img->cy = 2 * img->cx * img->cy + img->c_im;
	img->cx = img->tmp;
}

void	julia(t_data *img, double c_re, double c_im, double zoom_scale)
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
			julia_init(img, x, y, zoom_scale);
			img->c_re = c_re;
			img->c_im = c_im;
			i = 0;
			while (i < 50 * (0.6 / zoom_scale))
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
