/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 13:30:50 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 13:30:50 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_len(int n)
{
	int	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = number_len(n);
	nbr = ft_calloc((len + 1), sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		nbr[--len] = n % 10 + 48;
		n /= 10;
	}
	return (nbr);
}

/*
char	*ft_itoa(int n)
{
	char	*nbr;

	nbr = malloc(2);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
	{
		nbr[0] = '-';
		nbr[1] = '\0';
		nbr = ft_strjoin(nbr, ft_itoa(-n));
	}
	else if (n >= 10)
	{
		nbr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	}
	else if (n <= 9)
	{
		nbr[0] = n + 48;
		nbr[1] = '\0';
	}
	return (nbr);
}
*/
