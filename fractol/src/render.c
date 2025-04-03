/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:29:56 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 23:21:56 by abelboua         ###   ########.fr       */
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
	c->x = (map_normalizer(x, -2, +2, WIDTH) * fractol->mult_zoom);
	c->y = (map_normalizer(y, +2, -2, HEIGHT) * fractol->mult_zoom);
}

void	handel_pixel_set(int x, int y, t_fractol *fractol)
{
	t_cnbr	c;
	int		iterations;

	calculate_complex_coordinates(x, y, fractol, &c);
	if (ft_strncmp(fractol->name, "julia", 5) == 0)
		iterations = calculate_julia(c, fractol);
	else
		iterations = calculate_mandelbrot(c, fractol);
	if (iterations < fractol->iteration_value)
	{
		if (iterations == 0)
			iterations = 1;
		my_mlx_pixel_put(&fractol->img, x, y,
			(fractol->color / iterations) * fractol->iteration_value);
	}
	else
	{
		my_mlx_pixel_put(&fractol->img, x, y, 0x000000);
	}
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handel_pixel_set(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_in, fractol->mlx_win,
		fractol->img.img, 0, 0);
}
