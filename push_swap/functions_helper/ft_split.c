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

static int	is_space(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

static int	count_words(char const *s)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (*s)
			i++;
		while (*s && !is_space(*s))
			s++;
	}
	return (i + 1);
}

static void	free_arr(char **arr, int last)
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
		free_arr(arr, j - 1);
		return (NULL);
	}
	return (arr[j]);
}

char	**ft_split(char const *s)
{
	size_t	i;
	int		j;
	char	**arr;

	j = 0;
	arr = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (is_space(*s))
			s++;
		i = 0;
		while (s[i] != '\0' && !is_space(s[i]))
			i++;
		if (i > 0)
		{
			if (!(full_arr(arr, j, i, s)))
				return (NULL);
			j++;
		}
		s += i;
	}
	arr[j] = NULL;
	return (arr);
}
