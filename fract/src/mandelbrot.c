/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:10:49 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/21 07:04:29 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	calculate_mandelbrot(t_cnbr c, t_fractol *fractol)
{
	t_cnbr	z;
	int		i;
	double	temp;
	double	z_sqaure;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	temp = (c.x - 0.25) * (c.x - 0.25) + c.y * c.y;
	if (temp * (temp + (c.x - 0.25)) <= 0.25 * c.y * c.y)
		return fractol->iteration_value;
	if ((c.x + 1.0) * (c.x + 1.0) + c.y * c.y <= 0.0625)
		return fractol->iteration_value;
	while (i < fractol->iteration_value)
	{
		temp = z.x * z.x;
		z_sqaure = temp + (z.y * z.y);
		if (z_sqaure > fractol->v_escape)
			return (i);
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = temp - (z.y * z.y - c.y * c.y) + c.x;
		i++;
	}
	return (fractol->iteration_value);
}
