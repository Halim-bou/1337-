#include "./includes/push_swap.h"

void	push_swap(t_list *lst)
{
	int	size_a;
	int	size_b;
	t_list *lst_b;

	lst_b = (t_list *){NULL, NULL};
	size_a = ft_lstsize(lst);
	size_b = ft_lstsize(lst_b);
	ra(&lst, size_a);
}

int	*create_list(char **arr, int len)
{
	int	i;
	t_list	*head;

	if (ft_strcmp(*arr[0], "./push_swap"))
		i = 1;
	else
		i = 0;
	head = ft_lstnew(ft_atoi(*arr[i]));
	i++;
	while (*arr[i])
	{
		ft_lstadd_bak(&head, ft_lstnew(ft_atoi(*arr[i])));
		i++;
	}
	return (head);
}

int main(int argc, char **argv)
{
	char	**nums;
	int		*numbers;
	int		i;

	i = 0;
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	else if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		while (*nums[i])
			i++;
		numbers = create_list(nums, i);
	}
	else
	{
		numbers = create_list(argv, argc);
	}
	push_swap(numbers);
}
