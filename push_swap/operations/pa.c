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

void	pa(t_list **lst_a, t_list **lst_b, int size_a, int size_b)
{
	t_list	*ptr;

	if (size_b == 0)
		return;
	if (size_b == 1)
	{
		ft_lstadd_front(lst_a, *lst_b);
		*lst_b = NULL;
		write(1, "pa\n", 3);
		return;
	}
	ptr = *lst_b;
	*lst_b = (*lst_b)->next;
	(*lst_b)->prev = NULL;
	ptr->next = *lst_a;
	ptr->prev = NULL;
	*lst_a = ptr;
	write(1, "pa\n", 3);
}
