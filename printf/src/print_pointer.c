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

int	print_pointer(va_list args_list)
{
	int					i;
	unsigned long int	num;

	num = va_arg(args_list, unsigned long int);
	i = write(1, "0x", 2);
	ft_puthex(num, &i);
	return (i);
}
