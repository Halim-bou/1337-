/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:01:53 by abelboua          #+#    #+#             */
/*   Updated: 2024/11/01 11:01:54 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"

int	line_breaks(t_list *lst)
{
	t_list	*p;
	int		i;

	i = 0;
	if (!lst)
		return (1);
	p = ft_lstlast(lst);
	while (p->content[i])
	{
		if (p->content[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next!= NULL)
		lst = lst->next;
	return (lst);
}

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen((char *)str) + 1));
	if (!(ptr))
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 && !s2)
		return (ft_calloc(1, 1));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, s1, s1_len + 1);
	ft_strlcat(ptr, s2, s1_len + s2_len + 1);
	return (ptr);
}

char	*fix_str(t_list *lst)
{
	int	i;
	int		j;
	char	*str;

	i = 0;
	if (!lst)
		return (NULL);
	while(lst->content[i] != '\n')
		i++;
	i++;
	str = malloc(sizeof(char *) * i + 1);
	if (!str)
		return (NULL);
	j = 0;
	str[i + 1] = '\0';
	while (j <= i)
	{
		str[j + i] = lst->content[i];
		j++;
	}
	return (str);
}
