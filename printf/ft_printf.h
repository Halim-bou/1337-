/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 23:51:48 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-17 23:51:48 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

struct convet
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convet convet_t;

/* Main function for ft_printf */
int	ft_printf(const char *format, ...);
int	parsing(const char *format, convet_t *func_list, va_list arg_list);
int	put_str(va_list args_list);
int	print_sym(char c, convet_t *func_list, va_list arg_list);
int	sym_found(char sym, convet_t *func_list);
int	print_percent(va_list args_list);
#endif