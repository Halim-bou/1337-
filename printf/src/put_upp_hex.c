/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_upp_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 08:01:03 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 08:01:03 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_upp_hex(unsigned long int num, int *i)
{
	char	c;
	if (num >= 16)
	{
		ft_put_upp_hex(num / 16, i);
		ft_put_upp_hex(num % 16, i);
	}
	else
	{
		if (num < 10)
			c = num + '0';
		else
			c = num - 10 + 'A';
		write(1, &c, 1);
		(*i)++;
	}
}

int call_upp_hex(va_list args_list)
{
	unsigned long int	num;
	int		i;

	num = va_arg(args_list, unsigned long int);
	i = 0;
	ft_put_upp_hex(num, &i);
	return (i);
}
