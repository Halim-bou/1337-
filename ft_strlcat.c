/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:44:44 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 13:44:44 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sl;
	size_t	dl;
	size_t	i;

	i = 0;
	sl = ft_strlen((char *)src);
	dl = ft_strlen((char *)dst);
	if (size <= dl)
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
