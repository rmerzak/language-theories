#include "../header/regular.h"

void    ft_erreur(int d)
{
    if (d == 0)
    {
		fprintf(stderr,"Problem: nomber argument");
	}
    if (d == 1)
    {
        fprintf(stderr,"Problem: l expression donnes n est pas regulier");
    }
    if (d == 2)
    {
        fprintf(stderr,"Problem: l expression regulier ne peut pas se converter en NFA");
    }
    exit(-1);
}
