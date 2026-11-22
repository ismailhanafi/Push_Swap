#include "push_swap.h"

/*=================selection_sort=================================*/
void	Selection(int *arr, int size)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{`
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
		i++;
	}
}
/*=================chunk_sort=================================*/
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
			rb(b, *nb);
			pos--;
		}
		while (pos > *nb / 2 && pos < *nb)
		{
			rrb(b, *nb);
			pos++;
		}
		pa(a, na, b, nb);
	}
}

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
				rb(b, nb);
			pushed++;
		}
	}
	push_back(a, na, b, nb);
}

/*=================radix_sort=================================*/
static int	max_bits(int *a, int n)
{
	int	max;
	int	bits;
	int	i;

	max = a[0];
	i = 1;
	while (i < n)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void	Radix(int *a, int *na, int *b, int *nb)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = *na;
	bits = max_bits(a, *na);
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
