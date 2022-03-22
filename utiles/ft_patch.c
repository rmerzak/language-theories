#include "../header/regular.h"

void    ft_patch(list *l, s_state *s)
{
    list    *next;
    for(; l; l=next){
		next = l->next;
		l->s = s;
	}
}