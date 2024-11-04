/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:01:57 by abelboua          #+#    #+#             */
/*   Updated: 2024/11/01 11:01:58 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

/**
 * get_next_line: function that reads line from the fd e the BUFFER_SIZE less than line.
 * fd: file descriptor where to read from.
 * return: a pointer to the line ending buy new line or EOF.
 */
char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_buffer(fd, lst);
	if (!lst)
		return (NULL);
	concat_line(line, lst);

}

/**
 * buffers_to_nodes: function to full the linked list BUFFER_SIZES
 * tell the rich the new line or EOF
 * fd: file desciptor
 * lst: a pointer to the head pointer of linked list.
 * return: Nothing.
 */

void	read_buffer(int fd, t_list	*lst)
{
	char	*buff;
	int		done;
	t_list	*p;

	done = 1;
	buff = NULL;
	p = lst;
	while (!(line_breaks(p)) || done == 0)
	{
		buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		done = read(fd, buff, BUFFER_SIZE);
		if (done < 0)
		{
			free(buff);
			return (NULL);
		}
		p = ft_lstlast(lst);
		p->next = malloc(sizeof(t_list));
		if (!p->next)
			return (NULL);
		p = p->next;
		p->content = buff;
		p->next = NULL;
	}
}

/**
 * concat_line - concatinat all node content tell the end of line or new line
 * line:	pointer to string where to conat he new line
 * lst:		head of linked list
 * return:	nothing to return;
 */

void	concat_line(char *line, t_list *lst)
{
	t_list	*p;

	p = lst;
	while (p->next != NULL)
	{
		line = ft_strjoin(line, p->next->content);
		if (!line)
			return (NULL);
		p = p->next;
	}
	line = ft_strjoin(line, fix_str(p->next->content));
}
