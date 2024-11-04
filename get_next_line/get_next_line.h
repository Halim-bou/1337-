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
	char		*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		line_breaks(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str);
char	*fix_str(t_list *lst);
void	read_buffer(int fd, t_list	*lst);
void	concat_line(char *line, t_list *lst)

#endif
#endif
