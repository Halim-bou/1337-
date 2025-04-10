/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:28:12 by abelboua          #+#    #+#             */
/*   Updated: 2025/03/18 06:12:03 by abelboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (!s1[i] || !s2[i] || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
