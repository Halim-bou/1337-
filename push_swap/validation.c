/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-10 10:46:21 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-10 10:46:21 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <limits.h>
#include <stdio.h>

static int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	check_int(long int num)
{
	if (num >= INT_MIN && num <= INT_MAX)
		return (1);
	else
		return (0);
}

int	check_dup(t_list *lst)
{
	t_list	*ptr;

	while (lst->next != NULL)
	{
		ptr = lst->next;
		while(ptr->next != NULL)
		{
			if (lst->num == ptr->num)
				return (0);
			ptr = ptr->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	check_chars(t_list *lst)
{
	int	i;
	char	*num;

	i = 0;
	while (lst->next != NULL)
	{
		num = (char *)lst->content;
		while (num[i])
		{
			if (ft_isdigit(num[i]) || is_sign(num[i]))
				i++;
			else
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}
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

int	validation(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr->next)
	{
		ptr->num = ft_atoil(ptr->content);
		//free(ptr->content);
		if (!(check_int(ptr->num)))
			return (0);
		ptr = ptr->next;
	}
	//free(ptr->content);
	if (!(check_dup(*lst)))
		return (0);
	return (1);
}
