/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:27 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/25 21:40:15 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"

# define DPHEI 1000
# define DPWID 1000

# define MANDELBROT 0
# define JULIA 1


typedef struct s_data
{
	double	cx;//中心座標
	double	cy;//中心座標

	double	scale;//倍率

	double	c_re;//コマンドライン実部
	double	c_im;//コマンドライン虚部
	int		flag;//コマンドラインフラグ

	double	tmp;

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

int	mandelbrot(t_data *img, int zoom_scale);
// int		julia(int flag, float a, float b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	close_window_botton(t_data *img);
int	close_window_esc(int keycode, t_data *img);
void	visual_fractol(int flag, float x, float y, float scale);
int	mouse_hook(int mousecode, int x, int y, t_data *data);

#endif