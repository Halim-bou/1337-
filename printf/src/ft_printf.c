/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 01:47:11 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-25 01:47:11 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	printed;
	convet_t	func_list[] = {
		{"s", put_str},
		{"c", put_char},
		{"d", put_nbr},
		{"i", put_nbr},
		{"x", call_low_hex},
		{"X", call_upp_hex},
		{"p", print_pointer},
		{" ", flag_space},
		{NULL, NULL},
		};
	create_list(&func_list);
	if (format == NULL)
		return (-1);
	va_list	arg_list;
	va_start(arg_list, format);
	printed = parsing(format, func_list, arg_list);
	va_end(arg_list);
	return (printed);
}
