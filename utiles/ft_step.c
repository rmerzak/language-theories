#include "../header/regulier.h"

void ft_step(List *clist, int c, List *nlist)
{
    int i;
    s_state *s;

    listid++;
    nlist->n = 0;
    for (i = 0; i < clist->n; i++)
    {
        s = clist->s[i];
        if (s->c == c)
            ft_addstate(nlist, s->out);
    }
}