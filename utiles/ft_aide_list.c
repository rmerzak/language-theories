#include "../header/regulier.h"

Lpoiteur *ft_aide_list(s_state **sortiepoiteur)
{
    Lpoiteur *l;

    l = (Lpoiteur *)sortiepoiteur;
    l->next = NULL;
    return l;
}