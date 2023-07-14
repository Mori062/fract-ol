/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/14 16:18:27 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_mandelbrot
{
	int	x;
	int	y;
	float	center_x;
	float	center_y;
}	t_mandelbrot;

# define DPHEI 1000
# define DPWID 1500

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(float max_iter)
{
	t_mlx	mlx;
	t_data	img;
	int		x;
	int		y;
	float	zx;
	float	zy;
	float	cx;
	float	cy;
	float	tmp;
	float	i;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "fractol");
	img.img = mlx_new_image(mlx.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			zx = 0;
			zy = 0;
			cx = (float)x / 200 - 2;
			cy = (float)y / 200 - 1.5;
			i = 0;
			while (zx * zx + zy * zy < 4 && i < max_iter)
			{
				tmp = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tmp;
				i++;
			}
			if (i == max_iter)
			{
				my_mlx_pixel_put(&img, x, y, 0x000000);
				printf("x = %d, y = %d\n", x, y);
			}
			else
				my_mlx_pixel_put(&img, x, y, 0x0000FF * i / max_iter);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}

// int mandeblow(float max_iter)
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
// 			while (zx * zx + zy * zy < 4 && i < max_iter)
// 			{
// 				tmp = zx * zx - zy * zy + cx;
// 				zy = 2 * zx * zy + cy;
// 				zx = tmp;
// 				i++;
// 			}
// 			color = (i < max_iter) ? 0x000000 : 0xFFFFFF;
// 			my_mlx_pixel_put(&img, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }
