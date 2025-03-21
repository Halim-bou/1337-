/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 06:19:35 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/21 06:52:24 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	calculate_julia(t_cnbr z, t_fractol *fractol)
{
	t_cnbr	c;
	int		i;
	double	temp;
	double	z_sqaure;

	c.x = fractol->julia_x;
	c.y = fractol->julia_y;
	i = 0;
	while (i < fractol->iteration_value)
	{
		temp = z.x * z.x;
		z_sqaure = temp + (z.y * z.y);
		if (z_sqaure > fractol->v_escape)
			return (i);
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = temp - (z.y * z.y) + c.x;
		i++;
	}
	return (fractol->iteration_value);
}
