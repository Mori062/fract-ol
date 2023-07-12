/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:17:59 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/12 12:27:20 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
