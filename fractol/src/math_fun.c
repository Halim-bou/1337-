/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:12:07 by abelboua          #+#    #+#             */
/*   Updated: 2025/04/04 22:42:09 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	map_normalizer(double unscaledNum, double x,
			double y, double old_y)
{
	int	old_x;

	old_x = 0;
	return ((y - x) * (unscaledNum - old_x) / (old_y - old_x) + x);
}

static double	parse_number(const char *str)
{
	double	val;
	double	scale;
	int		afterdot;

	val = 0;
	scale = 1;
	afterdot = 0;
	if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && afterdot)
		{
			scale = scale / 10;
			val += (*str - '0') * scale;
		}
		else if (*str >= '0' && *str <= '9')
			val = val * 10.0 + (*str - '0');
		else if (*str == '.' && !afterdot)
			afterdot++;
		else
			break ;
		str++;
	}
	return (val);
}

double	ft_atof(const char *str)
{
	int	neg;

	neg = 1;
	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	return (parse_number(str) * neg);
}
