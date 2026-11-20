#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* utils.c */
int		count_numbers(int argc, char **argv);
int		has_value(int *a, int n, int value);

/* parse.c */
int		parse_arg(char *s, int *a, int *n);
int		parse_all(int argc, char **argv, int *a);
void	set_index(int *a, int *tmp, int n);

/* ops_raw.c (move things, print nothing) */
void	swap(int *s, int n);
void	push(int *from, int *nfrom, int *to, int *nto);
void	rotate(int *s, int n);
void	rev_rotate(int *s, int n);

/* ops.c (move things and print the instruction) */
void	sa(int *a, int na);
void	pa(int *a, int *na, int *b, int *nb);
void	pb(int *a, int *na, int *b, int *nb);
void	ra(int *a, int na);
void	rra(int *a, int na);

/* sort_small.c */
void	sort_two_three(int *a, int n);
void	sort_four_five(int *a, int *na, int *b, int *nb);

/* sort.c */
int		is_sorted(int *a, int n);
void	sort(int *a, int *na, int *b, int *nb);

#endif
