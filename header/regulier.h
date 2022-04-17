#ifndef REGULIER_H
#define REGULIER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "regulier.h"

enum {
    Match = 256,
    Split = 257
};

typedef struct s_state s_state;
struct s_state {
    int c;
    s_state *out;
    s_state *out1;
    int finlist;
};

int nstate;

typedef struct fragment fragment;
typedef union Lpoiteur Lpoiteur;
struct fragment {
    s_state *start;
    Lpoiteur *out;
};

union Lpoiteur {
    Lpoiteur *next;
    s_state *s;
};

typedef struct List List;
struct List {
    s_state **s;
    int n;
};

int listid;
List l1, l2;
void addstate(List *, s_state *);
void step(List *, int, List *);

typedef struct DState DState;
struct DState {
    List l;
    DState *next[256];
    DState *left;
    DState *right;
};

DState *alldstates;


char *ft_est_regulier(char *str, int len);
s_state *ft_state(int c, s_state *out, s_state *out1);
s_state *post2nfa(char *postfix);
void ft_patch(Lpoiteur *l, s_state *s);
fragment ft_fragment(s_state *debut, Lpoiteur *sortie);
Lpoiteur *ft_append(Lpoiteur *l1, Lpoiteur *l2);
Lpoiteur *ft_aide_list(s_state **sortiepoiteur);
DState *ft_nextstate(DState *d, int c);
void ft_step(List *clist, int c, List *nlist);
void ft_addstate(List *l, s_state *s);
DState *ft_dstate(List *l);
List *ft_debutlist(s_state *start, List *l);
DState *ft_debutstate(s_state *start);
void ft_erreur(int a, char *str);
#endif