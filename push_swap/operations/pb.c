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

	if (size_b == 0)
		return;
	ptr = *lst_a;
	*lst_a = (*lst_a)->next;
	ptr->next = *lst_b;
	(*lst_b)->prev = ptr;
	*lst_b = (*lst_b)->prev;
	write(1, "pb\n", 3);
}
