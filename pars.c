/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:08:55 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:09:18 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (*n > (long)INT_MAX + 1)
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
