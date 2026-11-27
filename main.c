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

static int	run_it(int algo, int bench, char **args, int count)
{
	int	*a;
	int	*b;
	int	na;

	a = malloc(count * sizeof(int));
	b = malloc(count * sizeof(int));
	na = 0;
	if (!a || !b || !all_in_one(count, args, a, &na))
		return (fail(a, b));
	benchmark_init(a, na, algo - 1);
	rank(a, b, na);
	if (!is_sorted(a, na))
		choose(algo, a, b, na);
	if (bench)
		benchmark_report();
	free(a);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	algo;
	int	i;
	int	bench;
	int	flag;

	if (argc < 2)
		return (0);
	algo = 4;
	bench = 0;
	i = 1;
	while (i < argc && i < 3)
	{
		flag = handle_flag(argv[i]);
		if (flag == 0)
			break ;
		if (flag < 0 || (i == 2 && (flag == 9) == bench))
			return (fail(NULL, NULL));
		if (flag == 9)
			bench = 1;
		else
			algo = flag;
		i++;
	}
	return (run_it(algo, bench, argv + i, argc - i));
}
