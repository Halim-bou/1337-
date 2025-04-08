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

int	stacks_init(t_stacks *stack, int ac, char **av)
{
	int	i;
	int	elem_count;

	i = 1;
	elem_count = count_numbers(ac, av);
	if (elem_count == 0)
		return (0);
	if (elem_count == -1)
		clean_exit(NULL, NULL, NULL, NULL);
	stack_allocation(stack, elem_count);
	set_stack(stack, elem_count);
	while (i < ac)
	{
		if (convert_args_to_int(stack->a, av[i]) == -1)
			clean_exit(stack->b->stack, stack->a->stack, stack->b, stack->a);
		i++;
	}
	stack->a->rear = stack->a->size % stack->a->capacity;
	stack->b->rear = stack->b->size % stack->b->capacity;
	return (1);
}