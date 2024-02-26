/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:59:08 by morishitash       #+#    #+#             */
/*   Updated: 2024/02/26 10:25:20 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# include "check_arg.h"

// print colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

// check errors
# define VALID 0
# define INVALID 1

# define MINILIBX_ERR "Minilibx error\n"

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 720

typedef struct s_data
{
}	t_data;

#endif
