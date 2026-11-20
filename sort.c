#include "push_swap.h"

int	is_sorted(t_node *s)
{
	whilw (a && a->next->index)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	radix_pass(t_node **a, t_list *b, int bit, int size)
{
	int	j;

	j = 0;

	while ( j < size)
	{
		if ((((*a)->index >> bit) & 1) == 1)
			ra(a, b);
		else
			pb(a, b);
		j++;
	}
	while (*b)
		pa(a, b);
}
