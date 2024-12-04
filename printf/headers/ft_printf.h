/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 01:47:16 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-25 01:47:16 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct convert
{
	char	*sym;
	int		(*f)(va_list);
}	t_convert;

/* Main function for ft_printf */
int		ft_printf(const char *format, ...);
int		parsing(const char *format, t_convert *func_list, va_list arg_list);
int		print_sym(char c, t_convert *func_list, va_list arg_list);
int		print_needed_sym(char c, char s,
			t_convert *func_list, va_list arg_list);
int		sym_found(char sym, t_convert *func_list);
int		put_nbr(va_list args_list);
int		put_str(va_list args_list);
int		put_char(va_list args_list);
int		call_low_hex(va_list args_list);
int		print_pointer(va_list args_list);
int		call_upp_hex(va_list args_list);
int		put_unisgned_nbr(va_list args_list);
int		print_space(__attribute__((unused))va_list args_list);
void	ft_puthex(unsigned long int num, int *i);
void	ft_put_upp_hex(unsigned int num, int *i);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
#endif
