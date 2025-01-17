/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-30 09:28:28 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-30 09:28:28 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !del || !*lst)
		return ;
	while (*lst != NULL)
	{
		ptr = *lst;
		del((*lst)->content);
		(*lst)->prev = NULL;
		*lst = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}
