/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 16:48:06 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 16:48:06 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

t_stack	*create_node(int nb)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nb = nb;
	new_node->rank = -1;
	new_node->next = NULL;
	return (new_node);
}

int	check_for_empty_argument(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
	{
		return (0);
	}
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && ft_isspace(av[i][j]))
			j++;
		if (av[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
