/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:12:07 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/18 07:03:41 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

/**
 * map_normalizer - function take a range numbers and scale the
 * values down to fit another range
 */
double	map_normalizer(double unscaledNum, double x, double y, double old_x, double old_y)
{
	return ((y - x) * (unscaledNum - old_x) / (old_y - old_x) + x);
}

t_cnbr	sum_of_complex_nbr(t_cnbr a, t_cnbr b)
{
	t_cnbr	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_cnbr	square_of_complex_nbr(t_cnbr z)
{
	t_cnbr	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

