#include "../header/regulier.h"

DState *ft_debutstate(s_state *start)
{
    return ft_dstate(ft_debutlist(start, &l1));
}