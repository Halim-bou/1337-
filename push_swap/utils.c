/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 16:45:22 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 16:45:22 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}