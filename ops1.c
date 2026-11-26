/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:01:26 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:01:28 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int na)
{
	swap(a, na);
	write(1, "sa\n", 3);
}

void	pa(int *a, int *na, int *b, int *nb)
{
	if (*nb == 0)
		return ;
	push(b, nb, a, na);
	write(1, "pa\n", 3);
}
