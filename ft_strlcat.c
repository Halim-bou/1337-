/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:24:22 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/25 19:38:19 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sl;
	size_t	dl;
	size_t	i;

	i = 0;
	sl = ft_strlen((char *)src);
	dl = ft_strlen((char *)dst);
	if (sl > size)
		return (sl + dl);
	if (*src == 0)
		return (dl);
	while (size - dl > 1)
	{
		dst[dl] = src[i];
		i++;
		dl++;
	}
	dst[dl] = '\0';
	return (dl);
}
