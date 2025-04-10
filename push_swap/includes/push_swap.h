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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
void	stack_allocation(t_stacks *stack, int args_count);
//clean functions
void	clean_exit(void *p1, void *p2, void *p3, void *p4);
void	free_stacks(t_stacks stack);
//utils function
int	ft_isnum(int c);
int	max(int a, int b);
//utils_stack functions
int	empty_stack(t_stack *stack);
int	get_elem(t_stack *stack, int idx);
//validate functions
int	non_valide_nbr(char *s);
int	all_args_are_valide_1(char *s);
int	exist_in_stack(t_stack *s, int n);
int	is_not_sorted(t_stack *stack);
//convert functions
int	ft_atoi_safe(t_stack *stack, char *s, int size);
int	convert_args_to_int(t_stack *a, char *s);
//count functions
int	get_arg_count(char *s);
int	count_numbers(int ac, char **av);

#endif
