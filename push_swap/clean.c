/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 16:52:18 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 16:52:18 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	clean_exit(void *p1, void *p2, void *p3, void *p4)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	if (p3)
		free(p3);
	if (p4)
		free(p4);
	write(2, "Error!\n", 8);
	exit(1);
}