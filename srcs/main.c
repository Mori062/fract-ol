/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:35:52 by morishitash       #+#    #+#             */
/*   Updated: 2024/02/26 10:25:55 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	// t_data		*data;
	check_args(argc, argv);
	return (0);
}

#ifdef DEBUG

__attribute__((destructor))
static void	destructor(void)
{
	printf("---------------------------\n");
	system("leaks -q fractol");
}

#endif
