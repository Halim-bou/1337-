/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 14:49:28 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-05 14:49:28 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * allocate_line - function that count size of line and allcoate it.
 * lst: linked list where we generate line.
 * Return: pointer to memory allocated.
 */

char	*allocate_line(t_list **lst)
{
	ssize_t	len;
	ssize_t	i;
	char	*line;

	len = 0;
	i = 0;
	if (!lst || !*lst)
		return (NULL);
	while (*lst)
	{
		while((*lst)->content[i] != '\n')
		{
			len++;
			i++;
		}
		*lst = (*lst)->next;
	}
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	return (line);
}

/**
 * ft_strlen - function that count length
 * s: string to count length
 * Return: length.
 */

ssize_t	ft_strlen(char *s)
{
	ssize_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * free_list - function to free all linked list.
 * lst: list to be freed
 * Return: Nothing.
 */

void	free_list(t_list *lst)
{
	t_list	*ptr;

	while (lst)
	{
		ptr = lst;
		free(lst->content);
		lst = lst->next;
		free(ptr);
	}
	lst = NULL;
}

/**
 * ft_lstlast - function that return addresse to last-
 * node in linked list.
 * lst: head pointer of linked list.
 * Return : addresse of last node reached or NULL.
 */

t_list	*ft_lstlast(t_list **lst)
{
	if (!*lst)
		return (NULL);
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	return (*lst);
}

/**
 * newline_exist - function that check if there-
 * is any newline in last node added the linked list.
 * lst: pointer to head of linked list.
 * return:  1 if newline exist in the node content else return 0.
 */

int	newline_exist(t_list *lst)
{
	ssize_t	i;

	i = 0;
	if (!lst)
		return (0);
	lst = ft_lstlast(&lst);
	if (!lst->content)
		return (0);
	while (lst->content[i])
	{
		if (lst->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
