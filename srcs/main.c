/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:17:59 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/12 09:16:26 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	mlx_init(&mlx, argv[1]);
	mlx_loop(mlx.mlx);
	return (0);
}
