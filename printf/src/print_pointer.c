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

#include "ft_printf.h"

int	print_pointer(va_list args_list)
{
	unsigned long int	i;
	unsigned long int	num;

	num = va_arg(args_list, unsigned long int);
	i = 2;
	ft_putstr("0x");
	ft_puthex(num, &i);
	return (i);
}
