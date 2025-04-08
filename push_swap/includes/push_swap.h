/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 10:46:33 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-10 10:46:33 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int		*stack;
	int		size;
	int		front;
	int		rear;
	int		capacity;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		capacity;
}	t_stacks;

//init functions
int	stacks_init(t_stacks *stack, int ac, char **av);
#endif
