#include "../header/regulier.h"

s_state matchstate = {Match};

Frag frag(s_state *start, Ptrlist *out)
{
    Frag n = {start, out};
    return n;
}
s_state *post2nfa(char *postfix)
{
    char *p;
    Frag stack[1000], *stackp, e1, e2, e;
    s_state *s;

    if (postfix == NULL)
        return NULL;

#define push(s) *stackp++ = s
#define pop() *--stackp

    stackp = stack;
    for (p = postfix; *p; p++)
    {
        switch (*p)
        {
        default:
            s = state(*p, NULL, NULL);
            push(frag(s, list1(&s->out)));
            break;
        case '.':
            e2 = pop();
            e1 = pop();
            patch(e1.out, e2.start);
            push(frag(e1.start, e2.out));
            break;
        case '|':
            e2 = pop();
            e1 = pop();
            s = state(Split, e1.start, e2.start);
            push(frag(s, append(e1.out, e2.out)));
            break;
        case '?':
            e = pop();
            s = state(Split, e.start, NULL);
            push(frag(s, append(e.out, list1(&s->out1))));
            break;
        case '*':
            e = pop();
            s = state(Split, e.start, NULL);
            patch(e.out, s);
            push(frag(s, list1(&s->out1)));
            break;
        case '+':
            e = pop();
            s = state(Split, e.start, NULL);
            patch(e.out, s);
            push(frag(e.start, list1(&s->out1)));
            break;
        }
    }

    e = pop();
    if (stackp != stack)
        return NULL;

    patch(e.out, &matchstate);
    return e.start;
#undef pop
#undef push
}