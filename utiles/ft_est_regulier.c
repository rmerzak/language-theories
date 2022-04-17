#include "../header/regulier.h"

char *ft_est_regulier(char *str, int len)
{
    char *ret;
    static char buff[8000];
    int n;
    int m;
    struct
    {
        int n;
        int m;
    } parent[100], *p;

    (void)len;
    p = parent;
    ret = buff;
    n = 0;
    m = 0;
    if (strlen(str) >= sizeof(buff) / 2)
        return (NULL);
    while (*str)
    {
        if (*str == '(')
        {
            if (m > 1)
            {
                --m;
                *ret++ = '.';
            }
            if (p >= parent + 100)
                return (NULL);
            p->n = n;
            p->m = m;
            p++;
            n = 0;
            m = 0;
        }
        else if (*str == '|')
        {
            if (m == 0)
                return (NULL);
            while (--m)
                *ret++ = '.';
            n++;
        }
        else if (*str == ')')
        {
            if (p == parent)
                return (NULL);
            if (m == 0)
                return (NULL);
            while (--m > 0)
                *ret++ = '.';
            while (n > 0)
            {
                *ret++ = '|';
                n--;
            }
            --p;
            n = p->n;
            m = p->m;
            m++;
        }
        else if (*str == '*' || *str == '?' || *str == '+')
        {
            if (m == 0)
                return NULL;
            *ret++ = *str;
        }
        else
        {
            if (m > 1)
            {
                --m;
                *ret++ = '.';
            }
            *ret++ = *str;
            m++;
        }
        str++;
    }
    if (p != parent)
        return (NULL);
    while (--m > 0)
        *ret++ = '.';
    while (n > 0)
    {
        *ret++ = '|';
        n--;
    }
    *ret = 0;
    return buff;
}