/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:29:56 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/21 06:51:12 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	dst;

	dst = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(dst + img->addr) = color;
}

void	init_color_map(t_fractol *fractol)
{
	int i;

	if (fractol->color_map)
		free(fractol->color_map);
	fractol->color_map = malloc(sizeof(int) * (fractol->iteration_value + 1));
	if (!fractol->color_map)
		mlx_allocation_error();
	i = 0;
	while (i <= fractol->iteration_value)
	{
		fractol->color_map[i] = map_normalizer(i, BLACK, WHITE, 0,
												fractol->iteration_value);
		i++;
	}
}

void	calculate_complex_coordinates(int x, int y, t_fractol *fractol,
											t_cnbr *c)
{
	c->x = (map_normalizer(x, -2, +2, 0, WIDTH) * fractol->mult_zoom)
							+ fractol->shifting_x;
	c->y = (map_normalizer(y, +2, -2, 0, HEIGHT) * fractol->mult_zoom)
							+ fractol->shifting_y;
}

void	handel_pixel_set(int x, int y, t_fractol *fractol)
{
	t_cnbr	c;
	int	iterations;
	int	color;

	calculate_complex_coordinates(x, y, fractol, &c);
	if (ft_strncmp(fractol->name, "mandelbrot", 10) == 0)
		iterations = calculate_mandelbrot(c, fractol);
	else if (ft_strncmp(fractol->name, "julia", 5) == 0)
		iterations = calculate_julia(c, fractol);
	else
		iterations = calculate_mandelbrot(c, fractol);
	if (iterations < fractol->iteration_value)
        color = fractol->color_map[iterations];
	else
		color = BLACK;
	my_mlx_pixel_put(&fractol->img, x, y, color);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	if (!fractol->color_map || fractol->color_map_dirty)
		init_color_map(fractol);
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			handel_pixel_set(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_in, fractol->mlx_win,
								fractol->img.img, 0, 0);
}
