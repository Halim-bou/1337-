/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-30 09:49:46 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-30 09:49:46 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*ptr;

	n_lst = ft_lstnew(lst->content);
	lst->content = f(lst->content);
	if (!n_lst)
	{
		ft_lstclear(&n_lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst != NULL)
	{
		ptr = ft_lstnew(lst->content);
		if (!ptr)
		{
			ft_lstclear(&n_lst, del);
			return (NULL);
		}
		ptr->content = (f(ptr->content));
		ft_lstadd_back(&n_lst, ptr);
		lst = lst->next;
	}
	return (n_lst);
}
