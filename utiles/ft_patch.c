#include "../header/regulier.h"

void ft_patch(Lpoiteur *l, s_state *s)
{
    Lpoiteur *next;

    for (; l; l = next)
    {
        next = l->next;
        l->s = s;
    }
}