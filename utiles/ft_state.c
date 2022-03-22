#include "../header/regular.h"

s_state *ft_state(int c, s_state *out, s_state *out1)
{
    s_state *s;
	
	nstate++;
	s = malloc(sizeof *s);
	s->finliste = 0;
	s->c = c;
	s->out = out;
	s->out1 = out1;
	return s;
}