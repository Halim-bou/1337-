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

void	print(t_list *lst)
{
	while(lst)
	{
		printf("| %li |\n", lst->num);
		lst = lst->next;
	}
}

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

void	reverse_stack(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
		pb(stack_a, stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
	print(*stack_b);
	while (*stack_b)
	{
		pa(stack_a, stack_b, ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		ra(stack_a, 1);
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
	if (stack_sorted(stack_a))
		return ;
	if (stack_rev_sorted(stack_a))
	{
		reverse_stack(stack_a, &stack_b);
		return ;
	}
	while (*stack_a)
	{
		pb(stack_a, &stack_b, ft_lstsize(*stack_a), ft_lstsize(stack_b));
		while(stack_b->next && (stack_b->num < stack_b->next->num))
		{
			sb(&stack_b, 1);
			pa(stack_a, &stack_b, ft_lstsize(*stack_a), ft_lstsize(stack_b));
		}
	}

	while(stack_b)
	{
		pa(stack_a, &stack_b, ft_lstsize(*stack_a), ft_lstsize(stack_b));
	}
}


