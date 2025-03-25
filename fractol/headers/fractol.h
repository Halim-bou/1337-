/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:45:12 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 15:44:08 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "/usr/include/X11/X.h"
# include "/usr/include/X11/keysym.h"

# define WIDTH 1000
# define HEIGHT 1000

//define comlex number as t_cnbr
typedef struct s_cnbr
{
	double	x;
	double	y;
}				t_cnbr;

//img struct addresses
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

//craeting struct to store all fractol data
typedef struct s_fractol
{
	void	*mlx_in;
	void	*mlx_win;
	char	*name;
	t_img	img;
	double	v_escape;
	int		iteration_value;
	double	shifting_x;
	double	shifting_y;
	double	mult_zoom;
	int		color;
	double	julia_x;
	double	julia_y;
	char	**julia_params;
}				t_fractol;

//helpers
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//functiont handler.c
void	cleanup_fractol(t_fractol *fractol);
int		stop_handle(t_fractol *fractol);
int		key_handle(int keycode, t_fractol *fractol);
int		button_handle(int button, int x, int y, t_fractol *fractol);

//functions render.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	calculate_complex_coordinates(int x, int y, t_fractol *fractol,
			t_cnbr *c);
void	handel_pixel_set(int x, int y, t_fractol *fractol);
void	fractol_render(t_fractol *fractol);

//julia
int		calculate_julia(t_cnbr z, t_fractol *fractol);

//madelbrot
int		calculate_mandelbrot(t_cnbr c, t_fractol *fractol);

//Function init.c
void	fractol_init(t_fractol *fractol);
void	event_init(t_fractol *fractol);
void	data_init(t_fractol *fractol);
void	mlx_allocation_error(void);

//math_fun
double	map_normalizer(double unscaledNum, double x, double y, double old_y);
double	ft_atof(const char *str);

//clear functions
void	clear_fractol(t_fractol *fractol);

#endif
