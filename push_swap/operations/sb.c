/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:44:55 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:44:55 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_list **lst_b, int size)
{
	int		temp;
	t_list	*ptr;

	if (size <= 1)
		return;
	ptr = (*lst_b)->next;
	(*lst_b)->next = ptr->next;
	ptr->next = *lst_b;
	*lst_b = ptr;
	write(1, "sb\n", 3);
}
