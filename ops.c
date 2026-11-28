/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:04:40 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:01:47 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *a, int *na, int *b, int *nb)
{
	if (*na == 0)
		return ;
	push(a, na, b, nb);
	write(1, "pb\n", 3);
	benchmark_record(op_pb);
}

void	ra(int *a, int na)
{
	if (na < 2)
		return ;
	rotate(a, na);
	write(1, "ra\n", 3);
	benchmark_record(op_ra);
}

void	rb(int *b, int nb)
{
	if (nb < 2)
		return ;
	rotate(b, nb);
	write(1, "rb\n", 3);
	benchmark_record(op_rb);
}

void	rra(int *a, int na)
{
	if (na < 2)
		return ;
	rev_rotate(a, na);
	write(1, "rra\n", 4);
	benchmark_record(op_rra);
}

void	rrb(int *b, int nb)
{
	if (nb < 2)
		return ;
	rev_rotate(b, nb);
	write(1, "rrb\n", 4);
	benchmark_record(op_rrb);
}
