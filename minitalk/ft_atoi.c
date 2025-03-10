/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-05 16:31:39 by abelboua          #+#    #+#             */
/*   Updated: 2025-03-05 16:31:39 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/mini_talk.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_isspace(int c)
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
			return (-1);
		i++;
	}
	while (n[i])
	{
		if (!(ft_isdigit(n[i])))
			return (-1);
		result = result * 10 + n[i] - 48;
		i++;
	}
	return (result * sign);
}
