/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/14 21:55:44 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

typedef struct s_data
{
	double    cx;//中心座標
	double    cy;//中心座標

	double    scale;//倍率

	double    c_re;//コマンドライン実部
	double    c_im;//コマンドライン虚部

	int        flag;//mandelbrot:0 julia:1

	int	tmp;

	void    *mlx;
	void    *win;
	void    *img;
	char    *addr;
	int      bits_per_pixel;
	int        line_length;
	int        endian;
}            t_data;

typedef struct s_complex
{
	double    re;
	double    im;
}            t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(void)
{
	t_data			img;
	float			i;
	int				x;
	int				y;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, DPWID, DPHEI, "fractol");
	img.img = mlx_new_image(img.mlx, DPWID, DPHEI);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	x = 0;
	while (x < DPWID)
	{
		y = 0;
		while (y < DPHEI)
		{
			img.cx = (x - DPWID / 2) * 4.0 / DPWID;
			img.cy = (y - DPHEI / 2) * 4.0 / DPWID;
			img.c_re = 0;
			img.c_im = 0;
			i = 0;
			while (img.c_re * img.c_re + img.c_im * img.c_im < 4 && i < 50)
			{
				img.tmp = img.c_re * img.c_re - img.c_im * img.c_im + img.cx;
				img.c_im = 2 * img.c_re * img.c_im + img.cy;
				img.c_re = img.tmp;
				i++;
			}
			if (i == 50)
				my_mlx_pixel_put(&img, x, y, 0x000000);
			else
				my_mlx_pixel_put(&img, x, y, 0xFFFFFF * i / 5);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}

// int mandeblow(float 50)
// {
// 	void	*mlx;
// 	void	*win;
// 	t_data	img;
// 	int		x;
// 	int		y;
// 	double	zx;
// 	double	zy;
// 	double	cx;
// 	double	cy;
// 	double	tmp;
// 	int		i;
// 	int		color;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1920, 1080, "Mandelbrot");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	x = 0;
// 	while (x < 1920)
// 	{
// 		y = 0;
// 		while (y < 1080)
// 		{
// 			zx = 0;
// 			zy = 0;
// 			cx = (x - 1920 / 2) * 4.0 / 1920;
// 			cy = (y - 1080 / 2) * 4.0 / 1920;
// 			i = 0;
// 			while (zx * zx + zy * zy < 4 && i < 50)
// 			{
// 				tmp = zx * zx - zy * zy + cx;
// 				zy = 2 * zx * zy + cy;
// 				zx = tmp;
// 				i++;
// 			}
// 			color = (i < 50) ? 0x000000 : 0xFFFFFF;
// 			my_mlx_pixel_put(&img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }
