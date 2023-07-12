/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:37:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/12 12:44:40 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//mlx_init() is a function that returns a pointer to a newly created mlx instance.
//mlx_loop() is a function that loops through the mlx instance and waits for events.

void	mlx_new_window(t_mlx *mlx, int width, int height, char *title)
{
	mlx->win = mlx_new_window(mlx->mlx, width, height, title);
}

void	mlx_init(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 500, 500, "Mandelbrot");
}

void	mlx_loop(t_mlx mlx)
{
	mlx_loop(mlx.mlx);
}

void	mandelbrot(void)
{
	t_mlx	mlx;

	mlx_init(&mlx);
	mlx_loop(mlx.mlx);
}
