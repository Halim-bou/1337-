/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:47:45 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:47:45 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_list **lst_a, t_list **lst_b, int size_a, int size_b)
{
	if (size_a <= 1 && size_b <= 1)
		return ;
	sa(lst_a, size_a);
	sb(lst_b, size_b);
	write(1, "ss\n", 3);
}
