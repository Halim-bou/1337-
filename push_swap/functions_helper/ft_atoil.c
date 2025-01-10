/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:42:56 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 13:42:56 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoil(const char *n)
{
	long unsigned int	i;
	long					result;
	long					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (is_space(n[i]) && n[i] != '-' && n[i] != '+')
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign = -1;
		else if (!(ft_isdigit(n[i + 1])))
			return (0);
		i++;
	}
	while (ft_isdigit(n[i]))
	{
		result = result * 10 + n[i] - 48;
		i++;
	}
	return (result * sign);
}
