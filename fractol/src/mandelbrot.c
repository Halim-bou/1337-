/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:10:49 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 16:54:34 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	calculate_mandelbrot(t_cnbr c, t_fractol *fractol)
{
	t_cnbr	z;
	double	temp;
	int		i;
	double	z_squared_mag;
	double	x_temp;

	z.x = 0.0;
	z.y = 0.0;
	i = -1;
	temp = (c.x - 0.25) * (c.x - 0.25) + c.y * c.y;
	if (temp * (temp + (c.x - 0.25)) <= 0.25 * c.y * c.y)
		return (fractol->iteration_value);
	if ((c.x + 1.0) * (c.x + 1.0) + c.y * c.y <= 0.0625)
		return (fractol->iteration_value);
	while (++i < fractol->iteration_value)
	{
		temp = z.x * z.x;
		z_squared_mag = temp + (z.y * z.y);
		if (z_squared_mag > fractol->v_escape)
			return (i);
		x_temp = z.x;
		z.x = temp - (z.y * z.y) + c.x;
		z.y = 2.0 * x_temp * z.y + c.y;
	}
	return (fractol->iteration_value);
}
