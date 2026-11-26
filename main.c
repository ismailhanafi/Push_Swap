/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:52:17 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:19:18 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	all_in_one(int count, char **argv, int *a, int *na)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!parsing(argv[i], a, na))
			return (0);
		i++;
	}
	return (1);
}

static int	fail(int *a, int *b)
{
	free(a);
	free(b);
	write(2, "Error\n", 6);
	return (1);
}

static void	choose(int algo, int *a, int *b, int n)
{
	int	nb;

	nb = 0;
	if (algo == 1)
		selection_sort(a, &n, b, &nb);
	else if (algo == 2)
		chunk_sort(a, &n, b, &nb);
	else if (algo == 3)
		radix_sort(a, &n, b, &nb);
	else
		sort(a, &n, b, &nb);
}

static int	run_it(int algo, char **args, int count)
{
	int	*a;
	int	*b;
	int	na;
	int	nb;

	a = malloc(count * sizeof(int));
	b = malloc(count * sizeof(int));
	nb = 0;
	na = 0;
	if (!a || !b || !all_in_one(count, args, a, &na))
		return (fail(a, b));
	rank(a, b, na);
	if (!is_sorted(a, na))
		choose(algo, a, b, na);
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	algo;

	if (argc < 2)
		return (0);
	algo = handle_flag(argv[1]);
	if (algo < 0)
		return (fail(NULL, NULL));
	if (algo > 0)
		return (run_it(algo, argv + 2, argc - 2));
	return (run_it(algo, argv + 1, argc - 1));
}
