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


/**
 * function puthex need to be debugged while trid with 42 it gives 0xc7728840 insted 0x7fffc7728840.
 * recursive needs to be checked again in line 24 to 37.
 */
void	ft_puthex(unsigned long int num, int *i)
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
	unsigned long int	num;
	int					i;

	num = va_arg(args_list, unsigned long int);
	i = 0;
	ft_puthex(num, &i);
	return (i);
}
