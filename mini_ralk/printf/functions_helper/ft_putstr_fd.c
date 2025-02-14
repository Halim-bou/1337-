/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 15:02:33 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 15:02:33 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
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
}
