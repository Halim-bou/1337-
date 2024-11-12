/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 13:02:59 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-05 13:02:59 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H_1
#define GET_NEXT_LINE_H_1

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_list
{
	char	*content;
	struct s_list	*next;
}	t_list;

/* Main functions to get next line */
char	*get_next_line(int fd);
void	correct_list(t_list **lst);
void	assemble_line(t_list *lst, char **line);
void	add_buffer(t_list **lst, char *buff, ssize_t size);
void	read_store(int fd, t_list **lst);
/* Function Helper */
ssize_t	ft_strlen(char *s);
char	*allocate_line(t_list **lst);
int	newline_exist(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	free_list(t_list *lst);

#endif
