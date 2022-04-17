#include "../header/regulier.h"

static int listcmp(List *l1, List *l2)
{
    int i;

    if (l1->n < l2->n)
        return -1;
    if (l1->n > l2->n)
        return 1;
    for (i = 0; i < l1->n; i++)
        if (l1->s[i] < l2->s[i])
            return -1;
        else if (l1->s[i] > l2->s[i])
            return 1;
    return 0;
}

static int ptrcmp(const void *a, const void *b)
{
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}
DState *ft_dstate(List *l)
{
    int i;
    DState **dp, *d;

    qsort(l->s, l->n, sizeof l->s[0], ptrcmp);
    dp = &alldstates;
    while ((d = *dp) != NULL)
    {
        i = listcmp(l, &d->l);
        if (i < 0)
            dp = &d->left;
        else if (i > 0)
            dp = &d->right;
        else
            return d;
    }
    d = malloc(sizeof *d + l->n * sizeof l->s[0]);
    memset(d, 0, sizeof *d);
    d->l.s = (s_state **)(d + 1);
    memmove(d->l.s, l->s, l->n * sizeof l->s[0]);
    d->l.n = l->n;
    *dp = d;
    return d;
}
