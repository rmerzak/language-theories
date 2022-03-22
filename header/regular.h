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

int nstate;
typedef union list list;

typedef struct fragment
{
	s_state *start;
	list *out;
} f_fragment;

union list
{
	list *next;
	s_state *s;
};

enum
{
	Match = 256,
	Split = 257
};


extern s_state matchstate;


int			ft_strlen(char *str);
char		*ft_est_regulier(char *str,int len);
void		ft_erreur(int d);
f_fragment	ft_fragment(s_state *debut, list *sortie);
void		ft_patch(list *l, s_state *s);
s_state		*ft_state(int c, s_state *out, s_state *out1);
list		*ft_append(list *l1,list *l2);
list*		ft_list1(s_state **outp);
s_state		*ft_postregulier_en_nfa(char *postregulier);



#endif