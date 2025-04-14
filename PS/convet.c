/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 13:45:44 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-17 13:45:44 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	skip_whitespace(char **str)
{
	while (**str && ft_isspace(**str))
		(*str)++;
	return (**str != '\0');
}

static int	parse_sign(char **str, long *sign)
{
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else
	{
		*sign = 1;
		if (**str == '+')
			(*str)++;
	}
	return (**str >= '0' && **str <= '9');
}

static int	convert_digits(char **str, long *res, long sign, int *error)
{
	while (**str >= '0' && **str <= '9')
	{
		*res = *res * 10 + (**str - '0');
		if ((*res * sign) > 2147483647)
		{
			*error = 1;
			return (2147483647);
		}
		else if ((*res * sign) < -2147483648)
		{
			*error = 1;
			return (-2147483648);
		}
		(*str)++;
	}
	return (**str == '\0');
}

int	safe_ft_atoi(char *str, int *error)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	*error = 0;
	if (!skip_whitespace(&str) || !parse_sign(&str, &sign)
		|| !convert_digits(&str, &res, sign, error))
	{
		*error = 1;
		return (0);
	}
	return ((int)(res * sign));
}

int	*process_2d_array(char **array, int *error, int num_strings)
{
	int	*tab;
	int	i;

	i = 0;
	if (!array || !error || num_strings <= 0)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * num_strings);
	if (!tab)
	{
		*error = 1;
		return (NULL);
	}
	while (i < num_strings)
	{
		tab[i] = safe_ft_atoi(array[i], error);
		if (*error)
		{
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}