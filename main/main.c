#include "../header/regular.h"

s_state matchstate = { Match };

int	main(int argc, char **argv)
{
	//int		i;
	char	*expresion_regulier;
	int		len;
	s_state	*debut;

	if (argc < 3)
		ft_erreur(0);
	len = ft_strlen(argv[1]);
	expresion_regulier = ft_est_regulier(argv[1] , len);
	if (expresion_regulier == NULL)
		ft_erreur(1);
	printf("expresion_regulier en Postfix: %s\n",expresion_regulier);
	debut = ft_postregulier_en_nfa(expresion_regulier);
	if (debut == NULL)
		ft_erreur(2);
	


	
}

