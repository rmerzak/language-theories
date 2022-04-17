#include "../header/regulier.h"

void ft_addstate(List *l, s_state *s)
{
    if (s == NULL || s->finlist == listid)
        return;
    s->finlist = listid;
    if (s->c == Split)
    {
        ft_addstate(l, s->out);
        ft_addstate(l, s->out1);
        return;
    }
    l->s[l->n++] = s;
}