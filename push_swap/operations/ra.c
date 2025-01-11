/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:13 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:13 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **head)
{
	t_list	*tail;
	t_list	*ptr;

	if (ft_lstsize(*head) <= 1)
		return;
	tail = *head;
	while (tail->next->next != NULL)
		tail = tail->next;
	ptr = (*head)->next;
	tail->next = *head;
	(*head)->prev = tail;
	(*head)->next = NULL;
	tail = tail->next;
	*head = ptr;
	(*head)->prev = NULL;
	ptr = NULL;
	write(1, "ra\n", 3);
}
