/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:29:56 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/19 06:38:12 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"
#include <stdio.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	dst;

	dst = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(dst + img->addr) = color;
}

static void	handel_pixel_set(int x, int y, t_fractol *fractol)
{
	t_cnbr	z;
	t_cnbr	c;
	int		i;
	int		color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map_normalizer(x, -2, +2, 0, WIDTH) * fractol->mult_zoom) + fractol->shifting_x;
	c.y = (map_normalizer(y, +2, -2, 0, HEIGHT) * fractol->mult_zoom) + fractol->shifting_y;
	//how many time to check if z^2 +c escaped
	while(i++ < fractol->iteration_value)
	{
		z = sum_of_complex_nbr(square_of_complex_nbr(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->v_escape)
		{
			color = map_normalizer(i, BLACK, WHITE, 0, fractol->iteration_value);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractol->img, x, y, BLACK);
}
/**
 * this file is handling the cheking
 * which fractal we gonna work with
 *
 */

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
			handel_pixel_set(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_in,
							fractol->mlx_win,
								fractol->img.img,
								0, 0);
}
