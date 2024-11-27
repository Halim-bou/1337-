/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 01:47:34 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-25 01:47:34 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	sym_found(char sym, convert_t *func_list)
{
	while (func_list->sym != NULL)
	{
		if (sym == func_list->sym[0])
			return (1);
		func_list++;
	}
	return (0);
}

int	print_sym(char c, convert_t *func_list, va_list arg_list)
{
	int	res;

	res = -1;
	if (!sym_found(c, func_list))
		return (-1);
	while (func_list->sym != NULL)
	{
		if (func_list->sym[0] == c)
		{
			res = func_list->f(arg_list);
			break ;
		}
		func_list++;
	}
	return (res);
}

int	parsing(const char *format, convert_t *func_list, va_list arg_list)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && (sym_found(format[i + 1], func_list)))
			{
				printed += print_sym(format[i + 1], func_list, arg_list);
				i += 2;
			}
			else if (format[i + 1] != '%' && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					printed += write(1, &format[i], 1);
					printed += write(1, &format[i + 1], 1);
					i += 2;
				}
			}
			else
				return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			printed += 1;
		}
	}
	return (printed);
}
