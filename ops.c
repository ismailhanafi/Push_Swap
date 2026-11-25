#include "push_swap.h"

void    sa(int *a, int na)
{
    swap(a, na);
    write(1, "sa\n", 3);
}

void    pa(int *a, int *na, int *b, int *nb)
{
    if (*nb == 0)
        return ;
    push(b, nb, a, na);
    write(1, "pa\n", 3);
}

void    pb(int *a, int *na, int *b, int *nb)
{
    if (*na == 0)
        return ;
    push(a, na, b, nb);
    write(1, "pb\n", 3);
}

void    ra(int *a, int na)
{
    rotate(a, na);
    write(1, "ra\n", 3);
}

void    rb(int *b, int nb)
{
    rotate(b, nb);
    write(1, "rb\n", 3);
}

void    rra(int *a, int na)
{
    rev_rotate(a, na);
    write(1, "rra\n", 4);
}

void    rrb(int *b, int nb)
{
    rev_rotate(b, nb);
    write(1, "rrb\n", 4);

}
