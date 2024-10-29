/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 21:45:54 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-29 21:45:54 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int	i;

	i = 1;
	ptr = lst;
	while(ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
