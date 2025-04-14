/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:08:28 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:08:28 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	return (1);
}

int	ra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	if (rotate(stack_a))
	{
		write(1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int	rb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	if (rotate(stack_b))
	{
		write(1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = rotate(stack_a);
	rotated_b = rotate(stack_b);
	if (rotated_a || rotated_b)
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}