#include "../header/regular.h"

list*    ft_list1(s_state **outp)
{
	list *l;
	
	l = (list*)outp;
	l->next = NULL;
	return l;
}