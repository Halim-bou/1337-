/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 19:40:27 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 19:40:27 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = dest;
	psrc = src;
	i = 0;
	if (pdest == psrc || n == 0)
		return (dest);
	if (pdest < psrc)
		ft_memcpy(pdest, psrc, n);
	else
	{
		i = n;
		while (i-- != 0)
			pdest[i] = psrc[i];
	}
	return (dest);
}
