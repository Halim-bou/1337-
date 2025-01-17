/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-17 10:43:02 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-17 10:43:02 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	free_split(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while(ptr->next)
	{
		free(ptr->content);
		ptr = ptr->next;
	}
	free(ptr->content);
}

void	free_all(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		free(ptr);
		ptr = *lst;
	}
	free(*lst);
}
