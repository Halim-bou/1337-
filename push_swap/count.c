/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:22:20 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 12:22:20 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	get_arg_count(char *s)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	if (all_args_are_valide_1(s) == -1)
		return (-1);
	while(s[i])
	{
		while (s[i] && s[i] == ' ')
			i++;
		j = i;
		while (s[j] && s[j] != ' ')
			j++;
		if (j != i)
			count++;
		i = j;
	}
	if (count == 0)
		return (-1);
	return (count);
}

int	count_numbers(int ac, char **av)
{
	int	i;
	int	count;
	int	current_count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		current_count = get_arg_count(av[i++]);
		if (current_count == -1)
			return (-1);
		count += current_count;
	}
	return (count);
}