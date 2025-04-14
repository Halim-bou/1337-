/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 16:52:18 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 16:52:18 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_stack(t_stack *head)
{
	t_stack	*current;

	if (!head)
		return ;
	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

void	free_stacks(t_stack *head_a, t_stack *head_b)
{
	free_stack(head_a);
	free_stack(head_b);
}

void	ft_free_str_array(char **ars)
{
	int	i;

	i = 0;
	if (!ars)
		return ;
	while (ars[i])
	{
		free(ars[i]);
		i++;
	}
	free(ars);
}
