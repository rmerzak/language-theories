#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../header/regulier.h"

s_state matchstate = {Match};


s_state *ft_postregulier_en_nfa(char *postregulier)
{
    char *p;
    fragment stack[1000], *stackbackup, e1, e2, e;
    s_state *s;

    if (postregulier == NULL)
        return NULL;

#define ft_push(s) *stackbackup++ = s
#define ft_pop() *--stackbackup

    stackbackup = stack;
    p = postregulier;
    while (*p)
    {
        if (*p == '.')
        {
            e2 = ft_pop();
            e1 = ft_pop();
            ft_patch(e1.out, e2.start);
            ft_push(ft_fragment(e1.start, e2.out));
        }
        else if (*p == '|')
        {
            e2 = ft_pop();
            e1 = ft_pop();
            s = ft_state(Split, e1.start, e2.start);
            ft_push(ft_fragment(s, ft_append(e1.out, e2.out)));
        }
        else if (*p == '?')
        {
            e = ft_pop();
            s = ft_state(Split, e.start, NULL);
            ft_push(ft_fragment(s, ft_append(e.out, ft_aide_list(&s->out1))));
        }
        else if (*p == '*')
        {
            e = ft_pop();
            s = ft_state(Split, e.start, NULL);
            ft_patch(e.out, s);
            ft_push(ft_fragment(s, ft_aide_list(&s->out1)));
        }
        else if (*p == '+')
        {
            e = ft_pop();
            s = ft_state(Split, e.start, NULL);
            ft_patch(e.out, s);
            ft_push(ft_fragment(e.start, ft_aide_list(&s->out1)));
        }
        else
        {
            s = ft_state(*p, NULL, NULL);
            ft_push(ft_fragment(s, ft_aide_list(&s->out)));
        }
        p++;
    }
    e = ft_pop();
    if (stackbackup != stack)
        return NULL;
    ft_patch(e.out, &matchstate);
    return e.start;
#undef pop
#undef push
}

int ismatch(List *l)
{
    int i;

    for (i = 0; i < l->n; i++)
        if (l->s[i] == &matchstate)
            return 1;
    return 0;
}


int ft_match(DState *start, char *s)
{
    DState *d, *next;
    int c, i;

    d = start;
    for (; *s; s++)
    {
        c = *s & 0xFF;
        if ((next = d->next[c]) == NULL)
            next = ft_nextstate(d, c);
        d = next;
    }
    return ismatch(&d->l);
}

int main(int argc, char **argv)
{
    int i;
    char *post;
    s_state *start;

    if (argc < 3)
        ft_erreur(1,NULL);
    post = ft_est_regulier(argv[1], strlen(argv[1]));
    if (post == NULL)
        ft_erreur(2, argv[1]);

    start = ft_postregulier_en_nfa(post);
    if (start == NULL)
        ft_erreur(3, post);
    l1.s = malloc(nstate * sizeof l1.s[0]);
    l2.s = malloc(nstate * sizeof l2.s[0]);
    for (i = 2; i < argc; i++) {
        if (ft_match(ft_debutstate(start), argv[i]))
            printf("ce mot \"%s\" appartient a expression regulier: %s\n", argv[i],argv[1]);
        else
            printf("ce mot \"%s\" n'appartient pas a expression regulier: %s\n", argv[i], argv[1]);
    }
    return 0;
}