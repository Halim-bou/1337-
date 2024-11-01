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
	buffer_to_nodes(fd, &lst);

}

/**
 * buffers_to_nodes: function to full the linked list BUFFER_SIZES
 * tell the rich the new line or EOF
 * fd: file desciptor
 * lst: a pointer to the head pointer of linked list.
 * return: Nothing.
 */

void	buffer_to_nodes(int fd, t_list	**lst)
{
	char	*buff;
	int		done;

	done = 1
	while (!(line_breaks(&buff)) || done == 0)
	{
	}
}
