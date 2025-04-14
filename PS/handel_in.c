/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:05:34 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:05:34 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static char	*process_arguments(int ac, char **av)
{
	char	*str;

	str = join_args(ac, av);
	if (!is_valid_input(str))
	{
		write(2, "Error\n", 6);
		free(str);
		return (NULL);
	}
	return (str);
}

static char	**split_and_validate_numbers(char *str)
{
	char	**numbers;

	numbers = ft_split_whitespace(str);
	free(str);
	if (!numbers)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (numbers);
}

static int	*process_numbers(char **numbers, int *argnum, int *error)
{
	int	*tab;

	*argnum = ft_str_array_len(numbers);
	tab = process_2d_array(numbers, error, *argnum);
	if (!tab && *error == 1)
	{
		ft_free_str_array(numbers);
		write(2, "Error\n", 6);
		return (NULL);
	}
	ft_free_str_array(numbers);
	return (tab);
}

static int	*check_duplicates(int *tab, int argnum)
{
	if (has_duplicates(tab, argnum))
	{
		free(tab);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (tab);
}

int	*handle_input(int ac, char **av, int *argnum)
{
	char	*str;
	char	**numbers;
	int		*tab;
	int		error;

	error = 0;
	str = process_arguments(ac, av);
	if (!str)
		return (NULL);
	numbers = split_and_validate_numbers(str);
	if (!numbers)
		return (NULL);
	tab = process_numbers(numbers, argnum, &error);
	if (!tab)
		return (NULL);
	tab = check_duplicates(tab, *argnum);
	return (tab);
}