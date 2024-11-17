/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:24:06 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-17 16:24:06 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	int	printed;
	convet_t func_list[] = {
		{"s", put_str},
		{NULL, NULL},
	};
	if (format == NULL)
		return (-1);
	va_list arg_list;
	va_start(arg_list, format);
	printed = parsing(format, func_list, arg_list);
	va_end(arg_list);
	return (printed);
}