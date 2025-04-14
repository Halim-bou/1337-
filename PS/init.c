/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.s                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:14:53 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 12:14:53 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	add_node_to_stack(t_stack **head, t_stack **current, int value)
{
	t_stack	*new_node;

	new_node = create_node(value);
	if (!new_node)
	{
		free_stack(*head);
		return (0);
	}
	if (!*head)
		*head = new_node;
	else
		(*current)->next = new_node;
	*current = new_node;
	return (1);
}

t_stack	*initialize_stack(int *arr, int size)
{
	t_stack	*head;
	t_stack	*current;
	int		i;

	if (size <= 0 || !arr)
		return (NULL);
	head = NULL;
	current = NULL;
	i = 0;
	while (i < size)
	{
		if (!add_node_to_stack(&head, &current, arr[i]))
			return (NULL);
		i++;
	}
	calculate_ranks(head);
	free(arr);
	return (head);
}
