/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 20:12:41 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 20:12:41 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;
	ssize_t			res;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i] != '\0')
	{
		res = write(fd, &s[i], 1);
		if (res == -1)
			return ;
		i++;
	}
	write(fd, "\n", 1);
}
