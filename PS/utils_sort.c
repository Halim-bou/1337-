/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:13:56 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:13:56 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	max = stack->nb;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	min = stack->nb;
	tmp = stack->next;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int	find_index(int target, t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->nb == target)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	move_min_to_top(t_stack **stack, int distance, int size)
{
	if (distance <= size / 2)
	{
		while (distance-- > 0)
			ra(stack);
	}
	else
	{
		distance = size - distance;
		while (distance-- > 0)
			rra(stack);
	}
}
