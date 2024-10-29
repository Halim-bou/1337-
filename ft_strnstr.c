/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:45:04 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 13:45:04 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == 0)
		return ((char *)big);
	while (little[j])
		j++;
	while (big[i] && i + j <= len)
	{
		if (ft_strncmp(&big[i], little, j) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
