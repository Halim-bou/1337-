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

void	stack_allocation(t_stacks *stack, int args_count)
{
	stack->a = (t_stack *)malloc(sizeof(t_stack));
	if (stack->a == NULL)
		clean_exit(NULL, NULL, NULL, NULL);
	stack->a->stack = malloc(sizeof(int) * (args_count));
	if (stack->a->stack == NULL)
		clean_exit(stack->a, NULL, NULL, NULL);
	stack->b = (t_stack *)malloc(sizeof(t_stack));
	if (stack->b == NULL)
		clean_exit(stack->a->stack, stack->a, NULL, NULL);
	stack->b->stack = malloc(sizeof(int) * (args_count));
	if (stack->b->stack == NULL)
		clean_exit(stack->b, stack->a->stack, stack->a, NULL);
}

void	set_stack(t_stacks *stack, int elem_count)
{
	stack->capacity = elem_count;
	stack->a->capacity = elem_count;
	stack->a->size = 0;
	stack->a->front = 0;
	stack->b->capacity = elem_count;
	stack->b->size = 0;
	stack->b->front = 0;
}

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