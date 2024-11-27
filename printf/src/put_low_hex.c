/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_low_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 07:59:54 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 07:59:54 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_puthex(unsigned int num, int *i)
{
	char	c;

	if (num >= 16)
	{
		ft_puthex(num / 16, i);
		ft_puthex(num % 16, i);
	}
	else
	{
		if (num < 10)
			c = num + '0';
		else
			c = num - 10 + 'a';
		write(1, &c, 1);
		(*i)++;
	}
}

int	call_low_hex(va_list args_list)
{
	unsigned int	num;
	int					i;

	num = va_arg(args_list, unsigned int);
	i = 0;
	ft_puthex(num, &i);
	return (i);
}
