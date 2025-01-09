#include "../includes/push_swap.h"

void	pa(t_list **lst_a, t_list **lst_b, int size_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	t_list	*tmp;

	ptr_a = lst_a;
	ptr_b = lst_b;
	if (size_b == 1)
	{
		ptr_b->content = ptr_a->content;
		tmp = ptr_a;
		ptr_a = ptr_a->next;
		free(tmp);
	}
	else
}
