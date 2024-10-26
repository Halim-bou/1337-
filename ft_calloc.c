/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:06:58 by abelboua          #+#    #+#             */
/*   Updated: 2024/10/25 20:50:38 by abelboua         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(number * sizeof(size));
	if (!(ptr))
		return (NULL);
	while (i < (size * number))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
