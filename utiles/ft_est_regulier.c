#include "../header/regular.h"

char	*ft_est_regulier(char *str,int len)
{
	char		*ret;
	static char	*buff[8000];
	int			n;
	int			m;
	struct
	{
		int	n;
		int	m;
	} parent[100], *p;

	(void)len;
	p = parent;
	ret = buff;
	n = 0;
	m = 0;
	if (len >= sizeof(buff) / 2)
		return (NULL);
	for (; *str; str++)
	{
		switch (*str)
		{
		case '(':
			if (m > 1)
			{
				--m;
				*ret++ = '.';
			}
			if (p >= parent+100)
				return (NULL);
			p->n = n;
			p->m = m;
			p++;
			n = 0;
			m = 0;
			break;
		case '|':
			if(m == 0)
				return (NULL);
			while (--m)
				*ret++ = '.';
			n++;
			break ;
		case ')':
			if (p == parent)
				return (NULL);
			if (m == 0)
				return (NULL);
			while (--m > 0)
				*ret++ = '.';
			for (; n > 0; n--)
				*ret++ = '|';
			--p;
			n = p->n;
			m = p->m;
			m++;
			break ;
			case '*':
			case '+':
			case '?':
				if(m == 0)
					return NULL;
				*ret++ = *str;
			break;
		default:
			if(m > 1){
				--m;
				*ret++ = '.';
			}
			*ret++ = *str;
			m++;
			break;
		}
	}
	if (p != parent)
		return (NULL);
	while (--m > 0)
		*ret++ = '.';
	for (; n > 0; n--)
		*ret++ = '|';
	*ret = 0;
	return buff;
}