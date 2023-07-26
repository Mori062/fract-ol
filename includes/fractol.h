/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:56:27 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/26 19:57:04 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/include/libft.h"
# include "../minilibx/mlx.h"

# define DPHEI 1500
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

void	visual_fractol(int flag, float x, float y, double scale);
void julia(t_data *img, double c_re, double c_im, double zoom_scale);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mandelbrot(t_data *img, float zoom_scale);
void	zoomed_fractol(float x, float y, double scale, t_data *data);
int color2rainbow(int i);
int	close_window_botton(t_data *img);
int	close_window_esc(int keycode, t_data *img);
int	mouse_hook(int mousecode, int x, int y, t_data *data);



#endif