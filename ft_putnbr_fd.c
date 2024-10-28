/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-28 15:16:50 by abelboua          #+#    #+#             */
/*   Updated: 2024-10-28 15:16:50 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;

	if (fd < 0)
		return ;
	nbr = ft_itoa(n);
	if (!nbr)
		return ;
	ft_putstr_fd(nbr, fd);
	free(nbr);
}
