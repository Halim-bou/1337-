#include "../includes/push_swap.h"

void	ra(t_list **lst_a, int size)
{
	int	temp;
	t_list *ptr;

	if (size <= 1)
		return;
	ptr = lst_a;
	temp = ptr->next->content;
	ptr->next->content = ptr->content;
	ptr->content = temp;
}
