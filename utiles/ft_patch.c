#include "../header/regulier.h"

void ft_patch(Lpoiteur *l, s_state *s)
{
    Lpoiteur *next;

    while(l)
    {
        next = l->next;
        l->s = s;
        l = next;
    }
    
}