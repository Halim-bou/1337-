/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 07:50:40 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 07:50:40 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	put_str(va_list args_list)
{
	char	*str;
	int		i;

	str = va_arg(args_list, char *);
	i = ft_strlen(str);
	ft_putstr(str);
	return (i);
}
