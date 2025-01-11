/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:39 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:39 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_list **lst_a, t_list **lst_b)
{
	if (!ft_lstsize(*lst_a) && !ft_lstsize(*lst_b))
		return ;
	rra(lst_a);
	rrb(lst_b);
	write(1, "rrr\n", 4);
}
