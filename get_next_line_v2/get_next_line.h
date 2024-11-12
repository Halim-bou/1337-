/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 15:56:13 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-12 15:56:13 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Main function get next line prototype */
char	*get_next_line(int fd);
char	*read_buffer(int fd, char *buff);
char	*line_fixed(char *s);
char	*buffer_fixed(char *s);
/* functions Helpers */
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strchr(const char	*s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
#endif
#endif
