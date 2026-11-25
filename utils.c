/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:03:07 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/25 14:09:32 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	counter(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (argv[i][j])
				count++;
			else
				return (0);
			while (argv[i][j] && argv[i][j] != ' ')
				j++;
		}
		i++;
	}
	return (count);
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
