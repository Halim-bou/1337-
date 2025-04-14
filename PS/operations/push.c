/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:06:57 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:06:57 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	push(t_stack **src, t_stack **dest)
{
	t_stack	*new_node;
	t_stack	*temp;

	if (!src || !*src)
		return (0);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->nb = (*src)->nb;
	new_node->rank = (*src)->rank;
	new_node->next = *dest;
	*dest = new_node;
	temp = *src;
	*src = (*src)->next;
	free(temp);
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return (0);
	if (push(stack_b, stack_a))
	{
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return (0);
	if (push(stack_a, stack_b))
	{
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}