/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:42:32 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-17 16:42:32 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sym_found(char sym, convet_t *func_list)
{
	while (func_list->sym != NULL)
	{
		if (sym == func_list->sym[0])
			return (1);
		func_list++;
	}
	return (0);
}

int	print_sym(char c, convet_t *func_list, va_list arg_list)
{
	int	res;

	res = -1;
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

int	parsing(const char *format, convet_t *func_list, va_list arg_list)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && sym_found(format[i + 1], func_list))
			{
				printed += write(1, "%", 1);
				i++;
				printed += print_sym(format[i], func_list, arg_list);
				i++;
			}
			else if (format[i + 1] && format[i + 1] == '%')
			{
				printed += write(1, "%%", 2);
				i += 2;
			}
			else
			{
				return (-1);
			}
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