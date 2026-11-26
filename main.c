#include "push_swap.h"

static int  handle_flag(char *s)   /* 0 none, 1-4 algo, -1 unknown */
{
	if (!ft_strcmp(s, "--simple"))
		return (1);
	if (!ft_strcmp(s, "--medium"))
		return (2);
	if (!ft_strcmp(s, "--complex"))
		return (3);
	if (!ft_strcmp(s, "--adaptive"))
		return (4);
	if (s[0] == '-' && s[1] == '-')
		return (-1);
	return (0);
}

static int	all_in_one(int argc, char **argv, int *a, int start)
{
	int	i;
	int	n;

	n = 0;
	i = start;
	while (i < argc)
	{
		if (!parsing(argv[i], a, &n))
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
	int	start;

	if (argc < 2)
		return (0);
	start = 1;
	if (argv[1][0] == '-')
	start = 2;
	na = argc - start;
	a = malloc(na * sizeof(int));
	b = malloc(na * sizeof(int));
	nb = 0; 
	if (na == 0 || !a || !b || !all_in_one(argc, argv, a, start))
	{
		free(a);
		free(b);
		write(2, "Error\n", 6);
		return (1);
	}
	rank(a, b, na);
	if (!is_sorted(a, na))
	{
		if (argc > 1 && argv[1][0] == '-')
		{
			if (!handle_flag(argv[1]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
		}
		else
			sort(a, &na, b, &nb);
	}
	free(a);
	free(b);
	return (0);
}
