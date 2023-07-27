/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:11:28 by morishitash       #+#    #+#             */
/*   Updated: 2023/07/27 20:31:34 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	print_error(void)
{
	write(2, "\x1b[31m", 5);
	write(2, "Usage: ./fractol [mandelbrot | julia]\n", 38);
	write(2, "\x1b[0m", 4);
	return (1);
}
