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

int	stack_sorted(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	stack_rev_sorted(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		if (ptr->num < ptr->next->num)
			return (0);
	}
	return (1);
}

void	reverse_stack(t_list **lst)
{
	t_list	*ptr;
	int		i;

	ptr = NULL;
	i = ft_lstsize(*lst);
	while (*lst)
		pa(lst, &ptr, ft_lstsize(*lst), ft_lstsize(ptr));
	while (ptr)
	{
		pb(lst, &ptr, ft_lstsize(*lst), ft_lstsize(ptr));
		ra(lst, 1);
	}
}

void	reverse_short(t_list **lst)
{
	if (ft_lstsize(*lst) <= 3)
	{
		t_list	*tail;

		tail = *lst;
		while (tail->next)
			tail = tail->next;
		if ((*lst)->num > (*lst)->next->num &&
				(*lst)->num > tail->num)
		{
			ra(lst, 1);
			sa(lst, 1);
		}
		else if (tail->num < tail->prev->num)
		{
			rra(lst, 1);
			sa(lst, 1);
		}
		else if ((*lst)->num > (*lst)->next->num)
				sa(lst, 1);
	}
}

void	basic_sort(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	// if (stack_sorted(stack_a))
	// 	return ;
	while (*stack_a)
	{
		pa(stack_a, &stack_b, ft_lstsize(*stack_a), ft_lstsize(stack_b));
		while(stack_b->next && (stack_b->num > stack_b->next->num))
		{
			sb(&stack_b, 1);
			pb(stack_a, &stack_b, ft_lstsize(*stack_a), ft_lstsize(stack_b));
		}
	}
	return ;
}


