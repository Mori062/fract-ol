/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:11:28 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/27 20:58:20 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_error(void)
{
	ft_putstr_fd("\x1b[31m", 2);
	ft_putendl_fd("Error : Invalid input", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd(" Usage : ./fractol mandelbrot", 2);
	ft_putendl_fd("         ./fractol julia [number1] [number2]", 2);
	ft_putendl_fd("", 2);
	ft_putendl_fd("the number must be between -2 to 2", 2);
	ft_putstr_fd("\x1b[0m", 2);
	return (1);
}
