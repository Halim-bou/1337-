/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 05:45:12 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/19 06:40:39 by abelboua         ###   ########.fr       */
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
}				t_fractol;

//helpers
void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

//functiont events handlers
int	key_handle(int keycode, t_fractol *fractol);
int	stop_handle(t_fractol *fractol);
int	button_handle(int button, int x, int y, t_fractol *fractol);


//math_fun
t_cnbr	square_of_complex_nbr(t_cnbr z);
t_cnbr	sum_of_complex_nbr(t_cnbr a, t_cnbr b);
double	map_normalizer(double unscaledNum, double x, double y, double old_x, double old_y);
//functions
void	fractol_render(t_fractol *fractol);
void	fractol_init(t_fractol *fractol);
# endif
