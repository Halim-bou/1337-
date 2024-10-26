/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:48:40 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/26 16:18:39 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	count_words(char const *s, char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = ft_strtrim(s, &c);
	if (!ptr)
		return (0);
	while (*ptr)
	{
		if (*ptr == c)
			i++;
		while (*ptr == c)
			ptr++;
		ptr++;
	}
	return (i + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int	j;
	char	**arr;

	i = 0;
	j = 0;
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > 0)
		{
			arr[j] = ft_substr(s, 0, i);
			j++;
		}
		s += i;
	}
	arr[j] = 0;
	return (arr);
}
