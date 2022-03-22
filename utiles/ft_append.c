#include "../header/regular.h"

list *ft_append(list *l1,list *l2)
{
    list *oldl1;
	
	oldl1 = l1;
	while(l1->next)
		l1 = l1->next;
	l1->next = l2;
	return oldl1;
}