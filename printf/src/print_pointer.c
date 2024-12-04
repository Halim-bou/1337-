/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 08:01:54 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 08:01:54 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/**
 * The function with printf for always starting 0x7fff while my ft_printf doesn't hundel this case.
 */
int	print_pointer(va_list args_list)
{
	int					i;
	unsigned long int		num;

	i = 0;
	num = va_arg(args_list, unsigned long int);
	if (!num)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i = write(1, "0x", 2);
	ft_puthex(num, &i);
	return (i);
}
