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

void	*create_list(char **arr, int len)
{
	int	i;
	t_list	*head;

	head = NULL;
	i = 0;
	head = ft_lstnew(arr[i]);
	i++;
	while (arr[i])
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
	if (argc <= 1 || !argv[1][0])
		return (1);
	else if (argc == 2)
	{
		if (!argv[1][0])
			return (1);
		nums = ft_split(argv[1]);
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
	///////////
	basic_sort(&numbers);
	//t_list	*b = NULL;
	//pb(&numbers, &b, ft_lstsize(numbers), ft_lstsize(b));
	// pb(&numbers, &numbers, ft_lstsize(numbers), ft_lstsize(numbers));
	// int tmp = 0;
	// t_list *ptr = numbers;
	// while (ptr)
	// {
	// 	tmp = ptr->num;
	// 	printf("|  %i  |\n", tmp);
	// 	ptr = ptr->next;
	// }
	////////////
	if (nums != NULL)
	{
		free_split(&numbers);
		free(nums);
	}
	free_all(&numbers);
	return (0);
}
