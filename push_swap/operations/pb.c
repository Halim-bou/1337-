/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:09 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:09 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_list **lst_a, t_list **lst_b, int size_a, int size_b)
{
	t_list	*ptr;

	if (size_a == 0)
		return;
	if (size_a == 1)
	{
		ft_lstadd_front(lst_b, *lst_a);
		*lst_a = NULL;
		write(1, "pb\n", 3);
		return;
	}
	ptr = *lst_a;
	(*lst_a) = (*lst_a)->next;
	(*lst_a)->prev = NULL;
	ptr->next = *lst_b;
	ptr->prev = NULL;
	*lst_b = ptr;
	write(1, "pb\n", 3);
}
