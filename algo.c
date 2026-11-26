/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:54:19 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:43:41 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*=================selection_sort=================================*/
void	selection_sort(int *a, int *na, int *b, int *nb)
{
	int	i;
	int	min;

	while (*na > 0)
	{
		i = 0;
		min = 0;
		while (i < *na)
		{
			if (a[i] < a[min])
				min = i;
			i++;
		}
		if (min <= *na / 2)
			while (min-- > 0)
				ra(a, *na);
		else
			while (min++ < *na)
				rra(a, *na);
		pb(a, na, b, nb);
	}
	while (*nb > 0)
		pa(a, na, b, nb);
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
				rb(b, *nb);
			pushed++;
		}
	}
	push_back(a, na, b, nb);
}

/*=================radix_sort=====================================*/
void	radix_sort(int *a, int *na, int *b, int *nb)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = *na;
	bits = 0;
	while ((size - 1) >> bits)
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

/*=================main===========================================*/
void	sort(int *a, int *na, int *b, int *nb)
{
	double	order;

	order = disorder(a, *na);
	if (order < 0.2)
		selection_sort(a, na, b, nb);
	else if (order < 0.5)
		chunk_sort(a, na, b, nb);
	else
		radix_sort(a, na, b, nb);
}
