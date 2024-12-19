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

int	print_sym(const char *format, int *i, t_convert *func_list, va_list arg_list)
{
	int	idx;
	int	rem;

	rem = *i;
	(*i)++;
	idx = 0;
	while (func_list[idx].sym)
	{
		if (format[*i] == func_list[idx].sym[0])
			return (func_list[idx].f(arg_list));
		idx++;
	}
	if (format[*i] == 0)
		return (-1);
	*i = rem;
	return (write(1, "%", 1));
}

int	parsing(const char *format, t_convert *func_list, va_list arg_list)
{
	int	i;
	int	printed;
	int	count;

	i = 0;
	count = 0;
	while(format[i])
	{
		if (format[i] == '%')
			printed = print_sym(format, &i, func_list, arg_list);
		else
			printed = write(1, &format[i], 1);
		if (printed == -1)
			return (-1);
		count += printed;
		i++;
	}
	return (count);
}
