#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ============Utils============= */
int		count_numbers(int argc, char **argv);
int		has_value(int *a, int n, int value);
int		parse_arg(char *s, int *a, int *n);
void	set_index(int *a, int *tmp, int n);

/* ============Operation============= */
void	swap(int *s, int n);
void	push(int *from, int *nfrom, int *to, int *nto);
void	rotate(int *s, int n);
void	rev_rotate(int *s, int n);

void    sa(int *a, int na);
void    pa(int *a, int *na, int *b, int *nb);
void    pb(int *a, int *na, int *b, int *nb);
void    ra(int *a, int na);
void    rb(int *b, int nb);
void    rra(int *a, int na);
void    rrb(int *b, int nb);

/* ============Algorithems============= */
void	selection_sort(int *a, int *na, int *b, int *nb);
void	chunk_sort(int *a, int *na, int *b, int *nb);
int		is_sorted(int *a, int n);

void	sort(int *a, int *na, int *b, int *nb);

#endif
