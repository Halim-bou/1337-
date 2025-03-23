/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:19:35 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 16:55:40 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	calculate_julia(t_cnbr z, t_fractol *fractol)
{
	t_cnbr	c;
	int		i;
	double	z_squared_mag;
	double	x_new;

	c.x = fractol->julia_x;
	c.y = fractol->julia_y;
	i = 0;
	while (i < fractol->iteration_value)
	{
		z_squared_mag = z.x * z.x + z.y * z.y;
		if (z_squared_mag > fractol->v_escape)
			return (i);
		x_new = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = x_new;
		i++;
	}
	return (fractol->iteration_value);
}
