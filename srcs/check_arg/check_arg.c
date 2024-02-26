/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:15 by morishitash       #+#    #+#             */
/*   Updated: 2024/02/26 10:30:55 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_arg.h"

static int	print_error(void)
{
	ft_putstr_fd(RED, 2);
	ft_putendl_fd("Error : Invalid input", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Usage : ./fractol mandelbrot", 2);
	ft_putendl_fd("        ./fractol julia [number1] [number2]", 2);
	ft_putstr_fd(BLUE, 2);
	ft_putendl_fd("Tips  : the numbers must be between -2 to 2.\n", 2);
	ft_putendl_fd("Recomend :", 2);
	ft_putendl_fd("        ./fractol julia 0 0.67", 2);
	ft_putendl_fd("        ./fractol julia 0.116 0.66", 2);
	ft_putstr_fd(RESET, 2);
	return (INVALID);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error());
	if (ft_strcmp(argv[1], "mandelbrot") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "burning_ship") != 0)
		return (print_error());
	return (VALID);
}
