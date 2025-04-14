/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 13:45:44 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-17 13:45:44 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if (find_min(*stack_a) == (*stack_a)->nb)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (find_max(*stack_a) == (*stack_a)->nb)
	{
		ra(stack_a);
		if (!is_sorted(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (find_index(find_max(*stack_a), *stack_a) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	distance;

	if (is_sorted(*stack_a) || size <= 1)
		return ;
	if (size == 2)
		sa(stack_a);
	else
	{
		while (size > 3)
		{
			distance = find_index(find_min(*stack_a), *stack_a);
			move_min_to_top(stack_a, distance, size);
			pb(stack_a, stack_b);
			size--;
		}
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}

static int	get_max_bits(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->rank;
	max_bits = 0;
	while (head)
	{
		if (head->rank > max)
			max = head->rank;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		max_bits;
	int		j;
	t_stack	*head_a;

	i = 0;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->rank >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}

