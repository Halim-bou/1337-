/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-16 00:19:30 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-16 00:19:30 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 && !s2)
		return ((char *)ft_calloc(1, 1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s1_len + s2_len + 1);
	free((char *)s1);
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sl;
	size_t	dl;
	size_t	i;

	i = 0;
	sl = ft_strlen((char *)src);
	dl = ft_strlen((char *)dst);
	if (size <= dl)
		return (size + sl);
	while (src[i] && (dl + i) < size - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)malloc(number * size);
	if (!(ptr))
		return (NULL);
	while (i < (size * number))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
