#ifndef REGULAR_H
#define REGULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct state
{
	int				c;
	struct state	*out;
	struct state	*out1;
	int				finliste;
} s_state;

int		ft_strlen(char *str);


#endif