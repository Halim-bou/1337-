/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 07:54:14 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 07:54:14 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	put_char(va_list args_list)
{
	char	c;

	c = va_arg(args_list, int);
	return (write(1, &c, 1));
}
