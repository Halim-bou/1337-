/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:02:01 by abelboua          #+#    #+#             */
/*   Updated: 2024/11/01 11:49:09 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024

#include <stdlib.h>

typedef struct	s_list
{
	void		*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int	line_breaks(char **line);
void	buffer_to_nodes(int fd, t_list	**lst);

#endif
#endif
