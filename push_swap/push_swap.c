#include "./includes/push_swap.h"

void	*create_list(char **arr, int len)
{
	int	i;
	t_list	*head;

	head = NULL;
	i = 0;
	head = ft_lstnew(arr[i]);
	i++;
	while (i < len)
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
	if (argc <= 1)
		return (1);
	else if (argc == 2)
	{
		if (!argv[1][0])
			return (1);
		nums = ft_split(argv[1], ' ');
		while (*nums[i])
			i++;
		numbers = create_list(nums, i);
	}
	else
		numbers = create_list(argv++, argc - 1);
	if (!validation(&numbers) || !check_chars(numbers))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (numbers->next)
	{
		printf("%i\n", numbers->content);
		numbers = numbers->next;
	}
	return (0);
}
