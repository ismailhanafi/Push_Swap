#include "push_swap.h"

void	swap(int *s, int n)
{
	int	tmp;

	if (n < 2)
		return ;
	tmp = s[0];
	s[0] = s[1];
	s[1] = tmp;
}

void	push(int *from, int *nfrom, int *to, int *nto)
{
	int	i;

	if (!*nfrom)
		return ;
	i = *nto;
	while (i > 0)
	{
		to[i] = to[i - 1];
		i--;
	}
	to[0] = from[0];
	(*nto)++;
	i = 0;
	while (i < *nfrom - 1)
	{
		from[i] = from[i + 1];
		i++;
	}
	(*nfrom)--;
}

void	rotate(int *s, int n)
{
	int	first;
	int	i;

	if (n < 2)
		return ;
	first = s[0];
	i = 0;
	while (i < n - 1)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[n - 1] = first;
}

void	rev_rotate(int *s, int n)
{
	int	last;
	int	i;

	if (n < 2)
		return ;
	last = s[n - 1];
	i = n - 1;
	while (i > 0)
	{
		s[i] = s[i - 1];
		i--;
	}
	s[0] = last;
}
