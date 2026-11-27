/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-hana <iel-hana@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:08:25 by iel-hana          #+#    #+#             */
/*   Updated: 2026/11/26 14:20:10 by iel-hana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef enum e_strategy
{
	str_simple,
	str_medium,
	str_complex,
	str_adaptive
}	t_strategy;

typedef enum e_operation
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr,
	op_count
}	t_operation;

typedef struct s_bench
{
	double		disorder;
	t_strategy	requested;
	t_strategy	strategy;
	int			operations[11];
	int			total;
}	t_bench;

/* ============Bench============= */
t_bench	*bench_get(void);
void	benchmark_init(int *a, int n, t_strategy requested);
void	benchmark_record(t_operation op);
void	benchmark_report(void);

/* ============Utils============= */
int		parsing(char *s, int *a, int *n);
void	rank(int *a, int *tmp, int n);
int		is_sorted(int *a, int n);
int		ft_strcmp(const char *s1, const char *s2);
int		handle_flag(char *s);
double	disorder(int *a, int n);

/* ============Operation============= */
void	swap(int *s, int n);
void	push(int *from, int *nfrom, int *to, int *nto);
void	rotate(int *s, int n);
void	rev_rotate(int *s, int n);

void	sa(int *a, int na);
void	pa(int *a, int *na, int *b, int *nb);
void	pb(int *a, int *na, int *b, int *nb);
void	ra(int *a, int na);
void	rb(int *b, int nb);
void	rra(int *a, int na);
void	rrb(int *b, int nb);

/* ============Algorithems============= */
void	selection_sort(int *a, int *na, int *b, int *nb);
void	chunk_sort(int *a, int *na, int *b, int *nb);
void	radix_sort(int *a, int *na, int *b, int *nb);

void	sort(int *a, int *na, int *b, int *nb);

#endif
