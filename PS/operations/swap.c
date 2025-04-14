/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:09:30 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:09:30 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	swap(t_stack **stack)
{
	int		temp_nb;
	int		temp_rank;
	t_stack	*next;
	t_stack	*current;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	current = *stack;
	next = current->next;
	if (next)
	{
		temp_nb = next->nb;
		temp_rank = next->rank;
		next->nb = current->nb;
		next->rank = current->rank;
		current->nb = temp_nb;
		current->rank = temp_rank;
	}
	return (1);
}

int	sa(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	if (swap(stack_a))
	{
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	if (swap(stack_b))
	{
		write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	swapped_a;
	int	swapped_b;

	swapped_a = swap(stack_a);
	swapped_b = swap(stack_b);
	if (swapped_a || swapped_b)
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (0);
}