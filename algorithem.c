#include "push_swap.h"

/* ============ SIMPLE  O(n^2): selection sort ============ */
void	selection_sort(int *a, int *na, int *b, int *nb)
{
	int	pos;

	while (*na > 0)
	{
		pos = 0;
		while (a[pos] != *nb)
			pos++;
		while (pos > 0 && pos <= *na / 2)
		{
			ra(a, *na);
			pos--;
		}
		while (pos > *na / 2 && pos < *na)
		{
			rra(a, *na);
			pos++;
		}
		pb(a, na, b, nb);
	}
	while (*nb > 0)
		pa(a, na, b, nb);
}

/* ============ MEDIUM  O(n sqrt n): chunk sort ============ */
static void	push_back(int *a, int *na, int *b, int *nb)
{
	int	pos;

	while (*nb > 0)
	{
		pos = 0;
		while (b[pos] != *nb - 1)
			pos++;
		while (pos > 0 && pos <= *nb / 2)
		{
			rotate(b, *nb);
			write(1, "rb\n", 3);
			pos--;
		}
		while (pos > *nb / 2 && pos < *nb)
		{
			rev_rotate(b, *nb);
			write(1, "rrb\n", 4);
			pos++;
		}
		pa(a, na, b, nb);
	}
}

/* A -> B in chunks of sqrt(n) ranks, then B -> A biggest first */
void	chunk_sort(int *a, int *na, int *b, int *nb)
{
	int	pushed;
	int	chunk;

	pushed = 0;
	chunk = 0;
	while ((chunk + 1) * (chunk + 1) <= *na)
		chunk++;
	while (*na > 0)
	{
		if (a[0] > pushed + chunk)
			ra(a, *na);
		else
		{
			pb(a, na, b, nb);
			if (b[0] <= pushed && *nb > 1)
			{
				rotate(b, *nb);
				write(1, "rb\n", 3);
			}
			pushed++;
		}
	}
	push_back(a, na, b, nb);
}

/* ============ COMPLEX  O(n log n): radix sort ============ */
void	radix_sort(int *a, int *na, int *b, int *nb)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = *na;
	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if ((a[0] >> i) & 1)
				ra(a, *na);
			else
				pb(a, na, b, nb);
			j++;
		}
		while (*nb > 0)
			pa(a, na, b, nb);
		i++;
	}
}

/* ============ main entry: picks the algorithm ============ */

void	sort(int *a, int *na, int *b, int *nb)
{
	if (*na <= 20)
		selection_sort(a, na, b, nb);
	else if (*na <= 100)
		chunk_sort(a, na, b, nb);
	else
		radix_sort(a, na, b, nb);
}
