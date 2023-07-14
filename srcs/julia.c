/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:17:31 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/14 20:54:17 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include <stdio.h>



typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_julia
{
	int		x;
	int		y;
	float	center_x;
	float	center_y;
	float	zx;
	float	zy;
}	t_julia;

void	julia_init(t_julia *jul)
{
	jul->zx = 0;
	jul->zy = 0;
	jul->center_x = (jul->x - DPWID / 2) * 4.0 / DPWID;
	jul->center_y = (jul->y - DPHEI / 2) * 4.0 / DPWID;
}

void	julia_calc(t_julia *jul)
{
	float	tmp;

	tmp = jul->zx * jul->zx - jul->zy * jul->zy + jul->center_x;
	jul->zy = 2 * jul->zx * jul->zy + jul->center_y;
	jul->zx = tmp;
}

int	julia(float x, float y)
{
	t_mlx	mlx;
	t_data	img;
	t_julia	jul;
	float	i;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, DPWID, DPHEI, "julia");
	img.img = mlx_new_image(mlx.mlx, DPWID, DPHEI);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	jul.x = 0;
	while (jul.x < DPWID)
	{
		jul.y = 0;
		while (jul.y < DPHEI)
		{
			julia_init(&jul);
			i = 0;
			while (jul.zx * jul.zx + jul.zy * jul.zy < 4 && i < 100)
			{
				julia_calc(&jul);
				i++;
			}
			my_mlx_pixel_put(&img, jul.x, jul.y, 0xFFFFFF * i / 5);
			jul.y++;
		}
		jul.x++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
