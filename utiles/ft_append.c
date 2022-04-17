#include "../header/regulier.h"

Lpoiteur *ft_append(Lpoiteur *l1, Lpoiteur *l2)
{
    Lpoiteur *oldl1;

    oldl1 = l1;
    while (l1->next)
        l1 = l1->next;
    l1->next = l2;
    return oldl1;
}