/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:44:36 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:44:36 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int	main(int ac, char **av)
{
	int		argnum;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (!check_for_empty_argument(ac, av))
		return (-1);
	stack_b = NULL;
	int *arr = handle_input(ac, av, &argnum);
	stack_a = initialize_stack(arr, argnum);
	if (!stack_a)
		return (-1);
	if (!is_sorted(stack_a))
	{
		if (argnum <= 12)
			small_sort(&stack_a, &stack_b, argnum);
		else
			radix_sort(&stack_a, &stack_b, argnum);
	}
	free_stacks(stack_a, stack_b);
	return (0);
}