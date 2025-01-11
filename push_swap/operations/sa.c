#include "../includes/push_swap.h"

void	sa(t_list **lst_a, int size)
{
	int		temp;
	t_list	*ptr;

	if (size <= 1)
		return;
	ptr = (*lst_a)->next;
	(*lst_a)->next = ptr->next;
	ptr->next = *lst_a;
	*lst_a = ptr;
}
