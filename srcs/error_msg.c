/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:11:28 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/28 15:12:32 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
			if (ft_isdouble(argv[2]) == 1 || ft_isdouble(argv[3]) == 1)
				return (print_error());
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

int	print_error(void)
{
	ft_putstr_fd("\x1b[31m", 2);
	ft_putendl_fd("Error : Invalid input", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("Usage : ./fractol mandelbrot", 2);
	ft_putendl_fd("        ./fractol julia [number1] [number2]", 2);
	ft_putstr_fd("\033[1;34m", 2);
	ft_putendl_fd("Tips : the numbers must be between -2 to 2.", 2);
	ft_putstr_fd("\x1b[0m", 2);
	return (1);
}
