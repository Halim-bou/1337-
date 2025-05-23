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

#include "../headers/ft_printf.h"

// void	create_fun_list(t_convert *func_list)
// {
// 	func_list[0].sym = "s";
// 	func_list[0].f = put_str;
// 	func_list[1].sym = "c";
// 	func_list[1].f = put_char;
// 	func_list[2].sym = "d";
// 	func_list[2].f = put_nbr;
// 	func_list[3].sym = "i";
// 	func_list[3].f = put_nbr;
// 	func_list[4].sym = "x";
// 	func_list[4].f = call_low_hex;
// 	func_list[5].sym = "X";
// 	func_list[5].f = call_upp_hex;
// 	func_list[6].sym = "u";
// 	func_list[6].f = put_unisgned_nbr;
// 	func_list[7].sym = "p";
// 	func_list[7].f = print_pointer;
// 	func_list[8].sym = "%";
// 	func_list[8].f = print_space;
// 	func_list[9].sym = 0;
// 	func_list[9].f = NULL;
// }

int	ft_printf(const char *format, ...)
{
	int			printed;
	t_convert	*func_list;
	va_list		arg_list;

	*func_list = (t_convert){
		{"s", put_str},
		{"a", put_char},
		{"d", put_nbr},
		{"x", call_low_hex},
		{"X", call_upp_hex},
		{"u", put_unisgned_nbr},
		{"p", print_pointer},
		{"%", print_percent},
		{NULL, NULL},
	};
	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	create_fun_list(func_list);
	printed = parsing(format, func_list, arg_list);
	va_end(arg_list);
	return (printed);
}
