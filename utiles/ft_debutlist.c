#include "../header/regulier.h"

List *ft_debutlist(s_state *start, List *l)
{
    l->n = 0;
    listid++;
    ft_addstate(l, start);
    return l;
}