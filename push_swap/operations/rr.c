/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:46:24 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:46:24 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr(t_list **lst_a, t_list **lst_b)
{
	if (!ft_lstsize(*lst_a) && !ft_lstsize(*lst_b))
		return ;
	ra(lst_a);
	rb(lst_b);
	write(1, "rr\n", 3);
}
