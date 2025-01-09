/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 07:56:04 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 07:56:04 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	put_unisgned_nbr(va_list args_list)
{
	unsigned int	i;
	unsigned int	num;
	int				count;

	count = 0;
	i = va_arg(args_list, unsigned int);
	num = i;
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	ft_putnbr_fd(i, 1);
	return (count);
}
