/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:17:59 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/12 12:40:58 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fractol [mandelbrot | julia | burningship]\n");
		return (0);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot();
	// else if (ft_strcmp(argv[1], "julia") == 0)
	// 	julia();
	// else if (ft_strcmp(argv[1], "burningship") == 0)
	// 	burningship();
	else
		ft_printf("Usage: ./fractol [mandelbrot | julia | burningship]\n");
	return (0);
}
