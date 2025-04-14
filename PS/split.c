/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-14 17:02:19 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-14 17:02:19 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static int	countw(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
		{
			count++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (count);
}

static char	*wordcpy_and_len(char *str, int *len)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	*len = i;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_processing(char **ars, char *s)
{
	int	i;
	int	str_i;
	int	len;

	i = 0;
	str_i = 0;
	while (s[str_i])
	{
		while (s[str_i] && ft_isspace(s[str_i]))
			str_i++;
		if (s[str_i])
		{
			len = 0;
			ars[i] = wordcpy_and_len(&s[str_i], &len);
			if (!ars[i])
			{
				ft_free_str_array(ars);
				return (0);
			}
			i++;
			str_i += len;
		}
	}
	ars[i] = NULL;
	return (1);
}

char	**ft_split_whitespace(char *s)
{
	char	**ar;
	int		count;

	if (!s)
		return (NULL);
	count = countw(s);
	ar = (char **)malloc((count + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	if (!ft_processing(ar, s))
		return (NULL);
	return (ar);
}