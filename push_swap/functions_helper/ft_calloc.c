/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:43:16 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 13:43:16 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_calloc(size_t number, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(number * sizeof(size));
	if (!(ptr))
		return (NULL);
	while (i < (size * number))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
