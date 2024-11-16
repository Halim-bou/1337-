/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-16 00:19:35 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-16 00:19:35 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * read_buffer - function that read buffer each
 * time tell the newline found.
 * fd: fil descriptor to read from.
 * line: pointer to where we join the generated
 * buffer with data we had.
 * Return: an assmbled buffers or NULL if it failed.
 */

char	*read_buffer(int fd, char *line)
{
	char	*buff;
	ssize_t	size;

	if (!line)
		line = (char *)ft_calloc(1, 1);
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (NULL);
		}
		if (size == 0)
			break ;
		line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (line);
}

/**
 * line_fixed - Function to remove all character
 * found after newline.
 * line: line to fix.
 * return: new generated line or NULL if it failed.
 */

char	*line_fixed(char *line)
{
	char	*n_line;
	ssize_t	i;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	n_line = (char *)ft_calloc(sizeof(char), i + 2);
	if (!n_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		n_line[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		n_line[i++] = '\n';
	n_line[i] = '\0';
	return (n_line);
}

/**
 * buffer_fixed - function the fix the last buffer
 * containe newline buy removing all charcters found
 * before newline.
 * buff: string to fix.
 * Return: NULL if it failed or fixed buffer.
 */

char	*buffer_fixed(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
		return (NULL);
	line = (char *)ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		line[j++] = buff[i++];
	free(buff);
	return (line);
}

/**
 * get_next_line - function that read a specific
 *  buffers size from file descriptortell found
 * newline and fix the buffer for the next call.
 * fd: file descriptor to read from.
 * Return: line gnerated or NULL if it failed.
 */

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff[fd] = read_buffer(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = line_fixed(buff[fd]);
	if (!line)
	{
		free(buff[fd]);
		return (NULL);
	}
	buff[fd] = buffer_fixed(buff[fd]);
	return (line);
}
