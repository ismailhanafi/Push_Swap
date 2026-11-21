#include "push_swap.h"

void	Selection(int *arr, int size)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
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

void	Radix(int *a, int *na, int *b, int *nb)
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
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((a[0] >> i) && 1)
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
