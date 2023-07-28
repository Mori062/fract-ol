/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:17:59 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/28 14:45:18 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	visual_fractol(float x, float y, t_data *data)
{
	data->img = mlx_new_image(data->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
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

static void	make_display(int flag, float x, float y, float scale)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, DISPLAY_WIDTH,
			DISPLAY_HEIGHT, "fract-ol");
	data.flag = flag;
	data.scale = scale;
	visual_fractol(x, y, &data);
}

int	main(int argc, char **argv)
{
	if (valid_arg(argc, argv) == 1)
		return (1);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		make_display(MANDELBROT, 0, 0, 1.0);
	else if (ft_strcmp(argv[1], "julia") == 0)
		make_display(JULIA, ft_atof(argv[2]), ft_atof(argv[3]), 1.0);
	else
		return (print_error());
	return (0);
}
