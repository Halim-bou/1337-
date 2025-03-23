/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:12:07 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/23 18:04:15 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

double	map_normalizer(double unscaledNum, double x,
			double y, double old_y)
{
	int	old_x = 0;
	return ((y - x) * (unscaledNum - old_x) / (old_y - old_x) + x);
}
