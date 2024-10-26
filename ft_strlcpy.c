/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:46:00 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/24 18:25:08 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	real_size;

	i = 0;
	if (size == 0)
		return (ft_strlen((char *)src));
	if (ft_strlen((char *)src) >= size)
	{
		real_size = size - 1;
	}
	else
	{
		real_size = ft_strlen((char *)src);
	}
	while (i < real_size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}
