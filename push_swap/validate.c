/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-08 12:24:01 by abelboua          #+#    #+#             */
/*   Updated: 2025-04-08 12:24:01 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

//not used yet
int	non_valide_nbr(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (ft_isnum(*s) == 0)
			return (1);
		s++;
	}
	return (0);
}

int	all_args_are_valide_1(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
		{
			if (i > 0 && s[i - 1] != ' ')
				return (-1);
			if (s[i] && !ft_isnum(s[i + 1]))
				return (-1);
		}
		else if (ft_isnum(s[i]) == 0 && s[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	exist_in_stack(t_stack *s, int n)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (get_elem(s, i) == n)
			return (1);
		i++;
	}
	return (0);
}

int	is_not_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (empty_stack(stack))
		return (0);
	if (stack->size != stack->capacity)
		return (1);
	while (i < stack->size - 1)
	{
		if (get_elem(stack, i) > get_elem(stack, i + 1))
			return (1);
		i++;
	}
	return (0);
}