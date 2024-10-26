/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:07:37 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/24 15:30:10 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p != '\0')
	{
		if (*p == c)
			return ((char *)p);
		p++;
	}
	if (*p == '\0' && c == '\0')
		return ((char *)p);
	return (NULL);
}
