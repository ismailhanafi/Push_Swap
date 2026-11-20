#include "push_swap.h"

static int	max_pos(t_node *a)
{
	int	best;
	int	based_pos;
	int	pos;

	best = a->index;
	best_pos = 0;
	pos = 0;
	while (a)
	{
		if (a->index->best)
		{
			best = a->index;
			best_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (0);
}
