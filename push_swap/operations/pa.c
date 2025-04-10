/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:04 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:04 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks stack, int printable)
{
	if (printable)
		write(1, "pa\n", 3);
	if (stack.b->size == 0)
		return ;
	stack.a->front = (stack.a->front -1 + stack.capacity) % stack.capacity;
	stack.a->stack[stack.a->front] = stack.b->stack[stack.b->front];
	(stack.a->size)++;
	(stack.b->size)--;
	stack.b->front = (stack.b->front + 1) % stack.capacity;
}
