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

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			status;

	if (ac == 1)
		return (0);
	status = stacks_init(&stacks, ac, av);
	if (status == 0)
		return (status);
	if (is_not_sorted(stacks.a))
	{
		write(1, "passed\n", 7);
		if (stacks.capacity <= 3)
			status = short_sort_3(stacks);
		else if (stacks.capacity <= 6)
			status = short_sort_6(stacks);
		else
			status = sort_stack(stacks);
	}
	free_stacks(stacks);
	if (status == -1)
		exit(1);
	return (0);
}