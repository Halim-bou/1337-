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

void	calculate_ranks(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		rank;

	current = stack;
	while (current)
	{
		rank = 0;
		compare = stack;
		while (compare)
		{
			if (compare->nb < current->nb)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

static int	calculate_total_length(int ac, char **av)
{
	int	total_length;
	int	i;

	total_length = 0;
	i = 1;
	while (i < ac)
	{
		total_length += ft_strlen(av[i]) + 1;
		i++;
	}
	return (total_length);
}

static void	concatenate_args(int ac, char **av, char *result)
{
	int	i;

	result[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(result, av[i]);
		if (i < ac - 1)
			ft_strcat(result, " ");
		i++;
	}
}

char	*join_args(int ac, char **av)
{
	int		total_length;
	char	*result;

	if (ac < 2)
		return (NULL);
	total_length = calculate_total_length(ac, av);
	result = malloc(total_length);
	if (!result)
		return (NULL);
	concatenate_args(ac, av, result);
	return (result);
}