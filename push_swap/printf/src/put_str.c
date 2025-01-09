/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 07:50:40 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-26 07:50:40 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	put_str(va_list args_list)
{
	char	*str;
	int		i;

	str = va_arg(args_list, char *);
	i = ft_strlen(str);
	return (write(1, str, i));
}
