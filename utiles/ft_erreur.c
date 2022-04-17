#include "../header/regulier.h"

void ft_erreur(int a,char *str)
{
    if (a == 1)
        fprintf(stderr, "Problem: nomber argument\n");
    else if (a == 2)
        fprintf(stderr, "Problem: l expression donnes n est pas regulier %s\n", str);
    else if(a == 3)
        fprintf(stderr, "Problem: l expression regulier ne peut pas se converter en NFA %s\n", str);
    exit(0);
}