/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-31 17:28:31 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-31 17:28:31 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i + 1);
}

static void	free_all(char **arr, int last)
{
	while (last >= 0)
	{
		free(arr[last]);
	}
	free(arr);
}

static char	*full_arr(char **arr, int j, size_t i, const char *s)
{
	arr[j] = ft_substr(s, 0, i);
	if (!arr[j])
	{
		free_all(arr, j - 1);
		return (NULL);
	}
	return (arr[j]);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**arr;

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
			if (!(full_arr(arr, j, i, s)))
				return (NULL);
			j++;
		}
		s += i;
	}
	arr[j] = 0;
	return (arr);
}
