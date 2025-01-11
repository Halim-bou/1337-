/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:28 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:28 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **lst)
{
	t_list	*tail;

	if (ft_lstsize(*lst) <= 1)
		return ;
	tail = *lst;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *lst;
	(*lst)->prev = tail;
	tail = tail->prev;
	tail->next = NULL;
	*lst = (*lst)->prev;
	(*lst)->prev = NULL;
	write(1, "rra\n", 4);
}
