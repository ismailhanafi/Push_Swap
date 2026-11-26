#include "push_swap.h"

double	disorder(int *a, int n)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0);
	return ((double)(mistakes / total_pairs));
}

int	is_sorted(int *a, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	antidup(int *a, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (a[i] == value)
			return (0);
		i++;
	}
	return (1);
}

static int	read_num(char **s, long *n)
{
	int	sign;
	int	digits;

	sign = 1;
	digits = 0;
	*n = 0;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	while (**s >= '0' && **s <= '9')
	{
		*n = *n * 10 + (**s - '0');
		if (sign == 1 && *n > INT_MAX)
			return (0);
		(*s)++;
		digits++;
	}
	*n *= sign;
	if (!digits || (**s && **s != ' '))
		return (0);
	return (*n >= INT_MIN && *n <= INT_MAX);
}

int	parsing(char *s, int *a, int *n)
{
	long	num;

	while (*s == ' ')
		s++;
	if (!read_num(&s, &num) || !antidup(a, *n, num))
		return (0);
	while (*s == ' ')
		s++;
	if (*s)
		return (0);
	a[(*n)++] = num;
	return (1);
}

void	rank(int *a, int *tmp, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		j = 0;
		while (j < n)
		{
			if (a[j] < a[i])
				tmp[i]++;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		a[i] = tmp[i];
		i++;
	}
}
