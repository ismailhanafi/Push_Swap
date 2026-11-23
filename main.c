#include "push_swap.h"

static int	parse_all(int argc, char **argv, int *a)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (i < argc)
	{
		if (!parse_arg(argv[i], a, &n))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	na;
	int	nb;

	if (argc < 2)
		return (0);
	na = count_numbers(argc, argv);
	a = malloc(na * sizeof(int));
	b = malloc(na * sizeof(int));
	nb = 0;
	if (na == 0 || !a || !b || !parse_all(argc, argv, a))
	{
		free(a);
		free(b);
		write(2, "Error\n", 6);
		return (1);
	}
	set_index(a, b, na); //⚠️
	if (!is_sorted(a, na))
		sort(a, &na, b, &nb);
	free(a);
	free(b);
	return (0);
}
