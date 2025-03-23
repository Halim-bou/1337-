/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:29:56 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 18:04:26 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	dst;

	dst = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(dst + img->addr) = color;
}

void	calculate_complex_coordinates(int x, int y, t_fractol *fractol,
											t_cnbr *c)
{
	c->x = (map_normalizer(x, -2, +2, WIDTH) * fractol->mult_zoom)
		+ fractol->shifting_x;
	c->y = (map_normalizer(y, +2, -2, HEIGHT) * fractol->mult_zoom)
		+ fractol->shifting_y;
}

void	handel_pixel_set(int x, int y, t_fractol *fractol)
{
	t_cnbr	c;
	int		iterations;
	int		color;

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

void	pixel_set(int tile_x, int tile_y, int tile_size, t_fractol *fractol)
{
	int	x;
	int	y;

	y = tile_y;
	while (y < tile_y + tile_size && y < HEIGHT)
	{
		x = tile_x;
		while (x < tile_x + tile_size && x < WIDTH)
		{
			handel_pixel_set(x, y, fractol);
			x++;
		}
		y++;
	}
}

void	fractol_render(t_fractol *fractol)
{
	int	tile_x;
	int	tile_y;
	int	tile_size;

	tile_size = 100;
	init_color_map(fractol);
	tile_y = 0;
	while (tile_y < HEIGHT)
	{
		tile_x = 0;
		while (tile_x < WIDTH)
		{
			pixel_set(tile_x, tile_y, tile_size, fractol);
			mlx_put_image_to_window(fractol->mlx_in,
				fractol->mlx_win, fractol->img.img, 0, 0);
			tile_x += tile_size;
		}
		tile_y += tile_size;
	}
}
