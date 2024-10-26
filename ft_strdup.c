/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:21:17 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/25 19:12:41 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

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
