/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:27 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/12 19:44:53 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

int	mandelbrot(float max_iter);
void	julia(void);

#endif