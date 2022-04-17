#include "../header/regulier.h"

DState *ft_nextstate(DState *d, int c)
{
    ft_step(&d->l, c, &l1);
    return d->next[c] = ft_dstate(&l1);
}