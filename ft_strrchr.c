/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:25:43 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/24 15:40:25 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	if (c == '\0')
		return ((char *)p);
	while (p >= s)
	{
		if (*p == c)
			return ((char *)p);
		p--;
	}
	return (NULL);
}
