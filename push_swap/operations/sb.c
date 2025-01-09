#include "../includes/push_swap.h"

void	rb(t_list **lst_b, int size)
{
	int	temp;
	t_list *ptr;

	if (size <= 1)
		return;
	ptr = lst_b;
	temp = ptr->next->content;
	ptr->next->content = ptr->content;
	ptr->content = temp;
}
