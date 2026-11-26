/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:08:01 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:19:07 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return ((double)mistakes / total_pairs);
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

int	handle_flag(char *s)
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
