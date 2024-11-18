/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:40:52 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-17 16:40:52 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(va_list args_list)
{
	int	i;
	char	*s;

	i = 0;
	if (!(s = va_arg(args_list, char *)))
		return (-1);
	while (s[i])
	{
		write(0, &s[i], 1);
		i++;
	}
	return (1);
}

int	print_percent(__attribute__((unused))va_list args_list)
{
	write(0, "%", 1);
	return (1);
}