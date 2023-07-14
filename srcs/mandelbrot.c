/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/14 20:22:34 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_mandelbrot
{
	int		x;
	int		y;
	float	center_x;
	float	center_y;
	float	zx;
	float	zy;
}	t_mandelbrot;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mandel_init(t_mandelbrot *mand)
{
	mand->zx = 0;
	mand->zy = 0;
	mand->center_x = (mand->x - DPWID / 2) * 4.0 / DPWID;
	mand->center_y = (mand->y - DPHEI / 2) * 4.0 / DPWID;
}

void	mandel_calc(t_mandelbrot *mand)
{
	float	tmp;

	tmp = mand->zx * mand->zx - mand->zy * mand->zy + mand->center_x;
	mand->zy = 2 * mand->zx * mand->zy + mand->center_y;
	mand->zx = tmp;
}

int	mandelbrot(void)
{
	t_mlx			mlx;
	t_data			img;
	t_mandelbrot	mand;
	float			i;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, DPWID, DPHEI, "fractol");
	img.img = mlx_new_image(mlx.mlx, DPWID, DPHEI);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mand.x = 0;
	while (mand.x < DPWID)
	{
		mand.y = 0;
		while (mand.y < DPHEI)
		{
			mandel_init(&mand);
			i = 0;
			while (mand.zx * mand.zx + mand.zy * mand.zy <= 4 && i < 50)
			{
				mandel_calc(&mand);
				i++;
			}
			if (i == 50)
				my_mlx_pixel_put(&img, mand.x, mand.y, 0x000000);
			else
				my_mlx_pixel_put(&img, mand.x, mand.y, 0xFFFFFF * i / 5);
			mand.y++;
		}
		mand.x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
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
