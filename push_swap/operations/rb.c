#include "../includes/push_swap.h"

void	ra(t_list *lst_a, int size)
{
	int	temp;

	if (size <= 1)
		return;
	temp = lst_a->next->content;
	lst_a->next->content = lst_a->content;
	lst_a->content = temp;
}
