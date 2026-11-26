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
