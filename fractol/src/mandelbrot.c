/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:10:49 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/25 01:35:29 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	calculate_mandelbrot(t_cnbr c, t_fractol *fractol)
{
	t_cnbr	z;
	int		i;
	double	z_squared_mag;
	double	temp;

	z.x = 0.0;
	z.y = 0.0;
	i = -1;
	while (++i < fractol->iteration_value)
	{
		z_squared_mag = (z.x * z.x) + (z.y * z.y);
		if (z_squared_mag >= fractol->v_escape)
			return (i);
		temp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2.0 * temp * z.y) + c.y;
	}
	return (fractol->iteration_value);
}
