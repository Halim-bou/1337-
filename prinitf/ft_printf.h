/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:25:00 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-17 16:25:00 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

struct convet
{
	char *sym;
	void *(f)(va_list);
};
typedef struct convet convet_t;

/* Main function for ft_printf */
int	ft_printf(const char *format, ...);
#endif