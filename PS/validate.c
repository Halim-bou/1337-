/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:24:01 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 12:24:01 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	has_duplicates(int *tab, size_t size)
{
	size_t	i;
	size_t	j;

	if (!tab || size <= 1)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_input(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != ' ' && !ft_isdigit(*str) && *str != '+' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
