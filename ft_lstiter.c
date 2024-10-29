/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 23:24:43 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-29 23:24:43 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if(!lst || !f)
		return ;
	ptr = lst;
	while(ptr != NULL)
	{
		(*f)(ptr->content);
		ptr = ptr->next;
	}
}
