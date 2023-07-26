/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:18:27 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/27 01:56:31 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_in(t_data *data)
{
	data->scale *= 0.9;
	mlx_destroy_image(data->mlx, data->img);
	zoomed_fractol(data->c_re, data->c_im, data->scale, data);
}

void	zoom_out(t_data *data)
{
	data->scale *= 1.1;
	mlx_destroy_image(data->mlx, data->img);
	zoomed_fractol(data->c_re, data->c_im, data->scale, data);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		zoom_in(data);
	if (mousecode == 5)
		zoom_out(data);
	return (0);
}
