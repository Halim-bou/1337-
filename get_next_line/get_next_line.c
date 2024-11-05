/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-05 14:40:44 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-05 14:40:44 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * get_next_line - function that reads and returns one line from
	filedescriptor fd each time it is called.
 * fd: file descriptor.
 * Return: one line readed or NULL.
 */

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_store(fd, &lst);
	if (!lst)
		return NULL;
	assemble_line(lst, &line);
	correct_list(&lst);
	if (line[0] == '\0')
	{
		free_list(lst);
		lst = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/**
 * read-store - Function to read from file and
 * data to list.
 * fd: file desicriptor to read from.
 * lst: pointer to head of list we store to.
 * Return: Nothing.
 */

void	read_store(int fd, t_list **lst)
{
	char	*buff;
	ssize_t		size;

	size = 1;
	while (!(newline_exist(*lst)) && size != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		size = read(fd, buff, BUFFER_SIZE);
		if ((*lst == NULL && size == 0) || size == -1)
		{
			free(buff);
			return ;
		}
		buff[size] = '\0';
		add_buffer(lst, buff, size);
		free(buff);
	}
}

/**
 * add_buffer - function adds a new parts of
 *  line from buffer to the end fo list
 * lst: head pointer to the list.
 * buff: buffer where part of line stored
 * size: size of line readed.
 * Return: Nothing.
 */
void	add_buffer(t_list *lst, char *buff, ssize_t size)
{
	t_list	*n_node;
	t_list	*last_node;
	ssize_t	i;

	i = 0;
	n_node = malloc(sizeof(t_list));
	if (!n_node)
		return ;
	n_node->content = malloc(sizeof(char) * (size + 1));
	if (!n_node->content)
		return ;
	n_node->next = NULL;
	while (buff[i] && i <= size)
	{
		n_node->content[i] = buff[i];
		i++;
	}
	n_node->content[i + 1] = '\0';
	last_node = ft_lstlast(lst);
	last_node->next = n_node;
}

/**
 * assmble_line - Function that assembles characters from
 * list into line stoping after '\n' found.
 * lst: linked list from where data stored.
 * line: line we generate
 * Return: Nothing.
 */

void	assemble_line(t_list *lst, char **line)
{
	ssize_t	i;
	ssize_t	j;
	if (!lst)
		return ;
	*line = allocate_line(&lst);
	if (!*line)
		return ;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->content[i] || lst->content[i] != '\n')
		{
			(*line)[j] = lst->content[i];
			i++;
			j++;
		}
		if (lst->content[i] == '\n')
			(*line)[j] = lst->content[]
	}
}
