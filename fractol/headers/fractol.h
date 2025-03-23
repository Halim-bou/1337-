/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:45:12 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 18:04:47 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "/usr/include/minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "/usr/include/X11/X.h"
#include "/usr/include/X11/keysym.h"


#define WIDTH 799
#define HEIGHT 799

//colors

#define BLACK      0x000000
#define WHITE      0xFFFFFF
#define RED        0xFF0000
#define GREEN      0x00FF00
#define BLUE       0x0000FF

// Psychedelic colors
#define PINK       0xFF00FF
#define CYAN       0x00FFFF
#define YELLOW     0xFFFF00
#define ORANGE     0xFFA500
#define LIME       0x00FF80
#define PURPLE     0x8000FF
#define MAGENTA    0xFF0080
#define TEAL       0x008080
#define VIOLET     0x7F00FF
#define NEON_GREEN 0x39FF14
#define HOT_PINK   0xFF69B4
#define ELECTRIC_BLUE 0x7DF9FF

//define comlex number as t_cnbr
typedef struct s_cnbr
{
	double	x;//real
	double	y;//imaginary
}				t_cnbr;


//img struct addresses
typedef struct	s_img {
	void	*img;
	char	*addr;//addr is pointing to the actual pixels
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
	int		*color_map;
	double	julia_x;
	double	julia_y;
	char	**julia_params;
}				t_fractol;

//helpers
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//functiont handler.c
void	update_fractol_params(t_fractol *fractol);
void	cleanup_fractol(t_fractol *fractol);
int		stop_handle(t_fractol *fractol);
int		key_handle(int keycode, t_fractol *fractol);
int		button_handle(int button, int x, int y, t_fractol *fractol);

//functions render.c
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	init_color_map(t_fractol *fractol);
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

# endif
