#include "push_swap.h"

void	SelectionSort(int *arr, int size)
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

static void	radix_sort(int *a, int *na, int *b, int *nb)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = *na;
	bits = 0;
	while (((size - 1) >> bits) != 0)
	{
		j = 0;
		while (j < size)
		{
			if ((a[0] >> i))
				ra(a, na, b, nb);
			else
				pb(a, na, b, nb);
			j++;
		}
		while (*nb > 0)
			pa(a, na, b, nb);
	}
}

int main()
{
    int arr[] = {1, 5, 0, 8};
    SelectionSort(arr, 4);
    int o=0;
    while (arr[o])
    {   
        printf("%d\n", arr[o]);
        o++;   
    }
}
