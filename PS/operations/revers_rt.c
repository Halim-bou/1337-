/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:07:33 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:07:33 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	if (reverse_rotate(stack_a))
	{
		write(1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return (0);
	if (reverse_rotate(stack_b))
	{
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	rotated_a;
	int	rotated_b;

	rotated_a = reverse_rotate(stack_a);
	rotated_b = reverse_rotate(stack_b);
	if (rotated_a || rotated_b)
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}
