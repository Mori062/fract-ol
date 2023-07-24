/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:17:59 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/24 13:09:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	print_error(void)
{
	write(2, "\x1b[31m", 5);
	write(2, "Usage: ./fractol [mandelbrot | julia | burningship]\n", 58);
	write(2, "\x1b[0m", 4);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error());
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		print_error();
		// mandelbrot();
	// else if (ft_strcmp(argv[1], "julia") == 0)
	// 	julia(0.285, 0.01);
		// julia(ft_atol(argv[2]), ft_atol(argv[3]));
	// else if (ft_strcmp(argv[1], "burningship") == 0)
	// 	burningship();
	else
		return (print_error());
	return (0);
}
