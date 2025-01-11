/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelboua <abelboua@student.1337.ma>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-11 18:44:36 by abelboua          #+#    #+#             */
/*   Updated: 2025-01-11 18:44:36 by abelboua         ###   ########.ma       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <stdio.h>

void	free_all(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		free(ptr);
		ptr = *lst;
	}
	free(*lst);
}
void	*create_list(char **arr, int len)
{
	int	i;
	t_list	*head;

	head = NULL;
	i = 0;
	head = ft_lstnew(arr[i]);
	i++;
	while (i <= len)
	{
		ft_lstadd_back(&head, ft_lstnew(arr[i]));
		i++;
	}
	return (head);
}

int main(int argc, char **argv)
{
	char	**nums;
	t_list	*numbers;
	int		i;

	i = 0;
	nums = NULL;
	if (argc <= 1)
		return (1);
	else if (argc == 2)
	{
		if (!argv[1][0])
			return (1);
		nums = ft_split(argv[1], ' ');
		while (nums[i])
			i++;
		numbers = create_list(nums, i);
	}
	else
		numbers = create_list(argv + 1, argc - 1);
	if (!check_chars(numbers) || !validation(&numbers))
	{
		if (nums != NULL)
		{
			free_split(&numbers);
			free(nums);
		}
		free_all(&numbers);
		write(2, "Error\n", 6);
		return (1);
	}
	// t_list *test = NULL;
	// test = ft_lstnew(NULL);
	// test->num = 1;
	// ft_lstadd_front(&test, ft_lstnew(NULL));
	// pa(&, &test, ft_lstsize(numbers), ft_lstsize(test));
	int tmp = 0;
	t_list *ptr = numbers;
	while (ptr->next)
	{
		tmp = ptr->num;
		printf("|  %i  |\n", tmp);
		ptr = ptr->next;
	}
	if (nums != NULL)
	{
		free_split(&numbers);
		free(nums);
	}
	free_all(&numbers);
	return (0);
}
