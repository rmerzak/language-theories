#include "../header/regular.h"

int	main(int argc, char **argv)
{
	//int		i;
	char	*expresion_regulier;
	int		len;
	//s_state	*debut;

	if (argc < 3)
	{
		fprintf(stderr,"Problem: nomber argument");
		return (1);
	}
	len = ft_strlen(argv[1]);
	expresion_regulier = ft_est_regulier(argv[1] , len);
	if (expresion_regulier == NULL)
		fprintf(stderr,"Problem: l expression donnes n est pas regulier");
	printf("%s\n",expresion_regulier);

	
}

