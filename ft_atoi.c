/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:42:56 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 13:42:56 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *n)
{
	long unsigned int	i;
	int					result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(n[i]) && n[i] != '-' && n[i] != '+')
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
