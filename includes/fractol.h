/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:27 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/28 14:44:05 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define DISPLAY_WIDTH 1500
# define DISPLAY_HEIGHT 1000

# define MANDELBROT 0
# define JULIA 1

typedef struct s_data
{
	float	cx;
	float	cy;
	float	scale;

	float	c_re;
	float	c_im;
	int		flag;
	float	tmp;

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	float	h;
	float	s;
	float	v;
}		t_color;

typedef struct s_move
{
	float	x;
	float	y;
}		t_move;

// color.c
int		color2rainbow(int i);

// destroy_window.c
int		close_window_esc(int keycode, t_data *img);
int		close_window_botton(t_data *img);

// error_msg.c
int		print_error(void);
int		valid_arg(int argc, char **argv);

// julia.c
void	julia(t_data *img, float c_re, float c_im, float zoom_scale);

// mandelbrot.c
void	mandelbrot(t_data *img, float zoom_scale);

// zoom.c
int		mouse_hook(int mousecode, int x, int y, t_data *data);

// main.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	visual_fractol(float x, float y, t_data *data);

#endif