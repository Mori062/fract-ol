/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:17:59 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/26 18:51:18 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

static int	print_error(void)
{
	write(2, "\x1b[31m", 5);
	write(2, "Usage: ./fractol [mandelbrot | julia | burningship]\n", 58);
	write(2, "\x1b[0m", 4);
	return (1);
}

int	valid_arg(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			return (0);
		else
			return (print_error());
	}
	else if (argc == 4)
	{
		if (ft_strcmp(argv[1], "julia") == 0)
		{
			// float error hanndling needed!
			if (ft_atof(argv[2]) < -2.0 || ft_atof(argv[2]) > 2.0)
				return (print_error());
			if (ft_atof(argv[3]) < -2.0 || ft_atof(argv[3]) > 2.0)
				return (print_error());
			return (0);
		}
		else
			return (print_error());
	}
	else
		return (print_error());
	return (0);
}

void	zoomed_fractol(float x, float y, double scale, t_data *data)
{
	data->img = mlx_new_image(data->mlx, DPHEI, DPWID);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (data->flag == MANDELBROT)
		mandelbrot(data, data->scale);
	else if (data->flag == JULIA)
		julia(data, x, y, data->scale);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_hook(data->win, 17, 0L, close_window_botton, data);
	mlx_hook(data->win, 2, 1L << 0, close_window_esc, data);
	mlx_loop(data->mlx);
}

void	visual_fractol(int flag, float x, float y, double scale)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, DPHEI, DPWID, "fract-ol");
	data.img = mlx_new_image(data.mlx, DPHEI, DPWID);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	data.flag = flag;
	data.scale = scale;
	if (flag == MANDELBROT)
		mandelbrot(&data, data.scale);
	else if (flag == JULIA)
		julia(&data, x, y, data.scale);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0L, close_window_botton, &data);
	mlx_hook(data.win, 2, 1L << 0, close_window_esc, &data);
	mlx_loop(data.mlx);
}

int	main(int argc, char **argv)
{
	if (valid_arg(argc, argv) == 1)
		return (1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		visual_fractol(MANDELBROT, 0, 0, 1.0);
	else if (ft_strcmp(argv[1], "julia") == 0)
		visual_fractol(JULIA, ft_atof(argv[2]), ft_atof(argv[3]), 1.0);
	else
		return (print_error());
	return (0);
}
