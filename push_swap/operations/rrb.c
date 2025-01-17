/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:33 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:33 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_list **lst, int p)
{
	t_list	*tail;
	t_list	*n_tail;

	if (ft_lstsize(*lst) <= 1)
		return ;
	tail = *lst;
	while (tail->next != NULL)
		tail = tail->next;
	n_tail = tail->prev;
	n_tail->next = NULL;
	tail->next = *lst;
	(*lst)->prev = tail;
	*lst = tail;
	tail->prev = NULL;
	if (p)
		write(1, "rrb\n", 4);
}
