#include "push_swap.h"

int	stack_size(t_node *s)
{
	int	x;

	x = 0;
	while (s)
	{
		x++;
		s = s->next;
	}
	return (x);
}

t_node	*last_node(t_node *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

void	free_stack(t_node **s)
{
	t_node	*tmp;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

int	has_value(t_node *s, int value)
{
	while (s)
	{
		if (s->value == value)
			return (1);
		s = s->next;
	}
	return (0);
}

int	add_back(t_node **a, int value)
{
	t_node	*node;

	if (has_value(*a, value))
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	if (!*a)
		*a = node;
	else
		last_node(*a)->next = node;
	return (1);
}
