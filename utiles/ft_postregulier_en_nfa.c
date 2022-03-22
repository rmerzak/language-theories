#include "../header/regular.h"


s_state *ft_postregulier_en_nfa(char *postregulier)
{
    char        *p;
    f_fragment  stack[8000], *stackp, e1, e2, e;
    s_state     *s;
    if (postregulier == NULL)
        return (NULL);
    #define push(s)	*stackp++ = s
    #define pop()	*--stackp

    stackp = stack;
    p = postregulier;
    while (*p)
    {
        if (*p == '.')
        {
            e2 = pop();
			e1 = pop();
			ft_patch(e1.out, e2.start);
			push(ft_fragment(e1.start, e2.out));
			break;
        }
        else if (*p == '|')
        {
            e2 = pop();
			e1 = pop();
			s = ft_state(Split, e1.start, e2.start);
			push(ft_fragment(s, ft_append(e1.out, e2.out)));
        }
        else if (*p == '?')
        {
            e = pop();
			s = ft_state(Split, e.start, NULL);
			push(ft_fragment(s, ft_append(e.out, ft_list1(&s->out1))));
        }
        else if (*p == '*')
        {
            e = pop();
			s = ft_state(Split, e.start, NULL);
			ft_patch(e.out, s);
			push(ft_fragment(s, ft_list1(&s->out1)));
        }
        else if (*p == '+')
        {
            e = pop();
			s = ft_state(Split, e.start, NULL);
			ft_patch(e.out, s);
			push(ft_fragment(e.start, ft_list1(&s->out1)));
        }
        else
        {
            s = ft_state(*p, NULL, NULL);
			push(ft_fragment(s, ft_list1(&s->out)));
        }
        p++;
    }
    e = pop();
    if(stackp != stack)
		return NULL;
    	
   
	ft_patch(e.out, &matchstate);
	return e.start;
    #undef pop
    #undef push
}