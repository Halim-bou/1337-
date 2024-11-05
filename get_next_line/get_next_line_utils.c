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
