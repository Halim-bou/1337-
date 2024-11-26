/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 07:54:45 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 07:54:45 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_nbr(va_list args_list)
{
	int	num;
	int	count;
	int copy;

	count = 0;
	num = va_arg(args_list, int);
	if (num == -2147483648)
	{
		return(ft_putstr("-2147483648"));
	}
	else
	{
		copy = num;
		if (copy <= 0)
			count++;
		while (copy > 0)
		{
			count++;
			copy /= 10;
		}
		ft_putnbr_fd(num, 1);
	}
	return (count);
}
