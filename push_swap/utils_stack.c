/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 16:48:06 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 16:48:06 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	empty_stack(t_stack *stack)
{
	return (stack->size == 0);
}

int	get_elem(t_stack *stack, int idx)
{
	if (idx < 0)
		return (stack->stack[(stack->rear + idx + stack->capacity)
				% stack->capacity]);
	return (stack->stack[(stack->front + idx) % stack->capacity]);
}