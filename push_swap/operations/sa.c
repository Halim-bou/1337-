/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:44:48 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:44:48 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_list **lst_a, int p)
{
	int		temp;
	t_list	*ptr;

	if (ft_lstsize(*lst_a) <= 1)
		return;
	ptr = (*lst_a)->next;
	(*lst_a)->next = ptr->next;
	ptr->next = *lst_a;
	*lst_a = ptr;
	if (p)
		write(1, "sa\n", 3);
}
