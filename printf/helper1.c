/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-17 16:40:52 by abelboua          #+#    #+#             */
/*   Updated: 2024-11-17 16:40:52 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(va_list args_list)
{
	char	*str;
	int		i;

	str = va_arg(args_list, char *);
	i = ft_strlen(str);
	ft_pustr(str);
	return (i);
}
// int	print_percent(va_list args_list)
// {
// 	if (va_arg(args_list, void *))
// 		return (-1);
// 	write(0, "%", 1);
// 	return (1);
// }

int	put_char(va_list args_list)
{
	char	c;

	c = va_arg(args_list, char);
	return (write(1, &c,1));
}

int	put_nbr(va_list args_list)
{
	int	num;
	int	count;
	int copy;

	count = 0;
	num = va_arg(args_list, int);
	if (num == "-2147483648")
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else
	{
		copy = num;
		if (copy <= 0)
			count++;
		while (copy > 0)
		{
			count++;
			copy /= 10;
		}
		ft_putnbr(num);
	}
	return (copy);
}

void	ft_puthex(ssize_t num, int *i)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, i);
		ft_puthex(num % 16, i);
	}
	else if (num < 10)
	{
		write(1, num + 48, 1);
		i += 1;
	}
	else
	{
		write(1, num + 87, 1);
		i += 1;
	}
}

int	call_low_hex(va_list args_list)
{
	ssize_t	num;
	int		i;

	num = va_arg(args_list, ssize_t);
	i = 0;
	ft_puthex(num, &i);
	return (i);
}


void	ft_put_upp_hex(ssize_t num, int *i)
{
	if (num >= 16)
	{
		ft_put_upp_hex(num / 16, i);
		ft_put_upp_hex(num % 16, i);
	}
	else if (num < 10)
	{
		write(1, num + 48, 1);
		i += 1;
	}
	else
	{
		write(1, num + 55, 1);
		i += 1;
	}
}

int call_upp_hex(va_list args_list)
{
	ssize_t	num;
	int		i;

	num = va_arg(args_list, ssize_t);
	i = 0;
	ft_put_upp_hex(num, &i);
	return (i);
}

int	print_pointer(va_list args_list)
{
	ssize_t	i;
	ssize_t	num;

	num = va_arg(args_list, ssize_t);
	i = 2;
	ft_putstr("0x");
	ft_puthex(num, &i);
	return (i);
}