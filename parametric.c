#include "justine.h"

void	display_error(t_parsing *parse, t_nparsing *n_parse)
{
	// if (!(parse->nb_effectif[0] >= 30))
		printf("\033[1;31mn1 >= 30 ?\033[0m Resultat : n1 = \x1B[32m%d\033[0m\n", parse->nb_effectif[0]);
	// if (!(parse->nb_effectif[1] >= 30))
		printf("\033[1;31mn2 >= 30 ?\033[0m Resultat : n2 = \x1B[32m%d\033[0m\n", parse->nb_effectif[1]);
	// if (!((parse->nb_effectif[0] * parse->f) >= 5))
		printf("\033[1;31mn1 x f >= 5 ?\033[0m Resultat : %d x %lf = \x1B[32m%lf\033[0m\n", parse->nb_effectif[0],parse->f,(parse->nb_effectif[0] * parse->f));
	// if (!((parse->nb_effectif[1] * parse->f) >= 5))
		printf("\033[1;31mn2 x f >= 5 ?\033[0m Resultat : %d x %lf = \x1B[32m%lf\033[0m\n", parse->nb_effectif[1],parse->f,(parse->nb_effectif[1] * parse->f));
	// if (!((parse->nb_effectif[0] * (1 - parse->f)) >= 5))
		printf("\033[1;31mn1 x (1 - f) >= 5 ?\033[0m Resultat : %d x (1 - %lf) = \x1B[32m%lf\033[0m\n", parse->nb_effectif[0],parse->f,(parse->nb_effectif[0] * (1 - parse->f)));
	// if (!((parse->nb_effectif[1] * (1 - parse->f)) >= 5))
		printf("\033[1;31mn2 x (1 - f) >= 5 ?\033[0m Resultat : %d x (1 - %lf) = \x1B[32m%lf\033[0m\n", parse->nb_effectif[1],parse->f,(parse->nb_effectif[1] * (1 - parse->f)));
}

void	n_display_error(t_parsing *parse, t_nparsing *n_parse)
{
	// if (!(parse->nb_effectif[0] >= 30))
		printf("\033[1;31mn1 >= 30 ?\033[0m Resultat : n1 = \x1B[32m%d\033[0m\n", parse->nb_effectif[0]);
	// if (!(n_parse->n_nb_effectif[0] >= 30))
		printf("\033[1;31mn2 >= 30 ?\033[0m Resultat : n2 = \x1B[32m%d\033[0m\n", n_parse->n_nb_effectif[0]);
	// if (!((parse->nb_effectif[0] * parse->f) >= 5))
		printf("\033[1;31mn1 x f >= 5 ?\033[0m Resultat : %d x %lf = \x1B[32m%lf\033[0m\n", parse->nb_effectif[0],parse->f,(parse->nb_effectif[0] * parse->f));
	// if (!((n_parse->n_nb_effectif[0] * parse->f) >= 5))
		printf("\033[1;31mn2 x f >= 5 ?\033[0m Resultat : %d x %lf = \x1B[32m%lf\033[0m\n", n_parse->n_nb_effectif[0],parse->f,(n_parse->n_nb_effectif[0] * parse->f));
	// if (!((parse->nb_effectif[0] * (1 - parse->f)) >= 5))
		printf("\033[1;31mn1 x (1 - f) >= 5 ?\033[0m Resultat : %d x (1 - %lf) = \x1B[32m%lf\033[0m\n", parse->nb_effectif[0],parse->f,(parse->nb_effectif[0] * (1 - parse->f)));
	// if (!((n_parse->n_nb_effectif[0] * (1 - parse->f)) >= 5))
		printf("\033[1;31mn2 x (1 - f) >= 5 ?\033[0m Resultat : %d x (1 - %lf) = \x1B[32m%lf\033[0m\n", n_parse->n_nb_effectif[0],parse->f,(n_parse->n_nb_effectif[0] * (1 - parse->f)));
}

void	parametric(t_parsing *parse, t_nparsing *n_parse)
{
	int i;
	int j;
	int groupe;
	int n_groupe;

	groupe = 0;
	n_groupe = 0;
	i = 0;
	j = 0;
	printf("Tu veux \033[1;31mrajouter\033[0m des échantillons ? Tape \033[1;31m1\033[0m pour oui et \033[1;31m2\033[0m pour non\n-> ");
	green();
	scanf("%d", &n_parse->new_echantillon);
	reset();
	if (n_parse->new_echantillon == 1)
	{
		printf("Combien ?\n-> ");
		scanf("%d", &n_parse->new_echtn_n);
		//recuperer le nb d'effectif par groupe
		n_get_nb_effectif(n_parse);
		printf("Tape \033[1;31m1\033[0m pour rentrer les valeurs de l'échantillon ou \033[1;31m2\033[0m pour ne pas les rentrer\n-> ");
		green();
		scanf("%d", &n_parse->n_input_val);
		reset();
		if (n_parse->n_input_val == 1)
		{
			//recuperer les valeurs des effectifs
			n_get_val_effectif(n_parse);
			//->MOYENNE
			n_clc_moy(n_parse);
			//->VARIANCE
			n_clc_variance(n_parse);
			//->ECART TYPE
			n_clc_ecart_type(n_parse);
		}
			parse->nb_groupe = parse->nb_groupe + n_parse->new_echtn_n;
	}

	// printf("NB GROUPE FINAL : %d NB ECHTN NV : %d\n", parse->nb_groupe, n_parse->new_echtn_n);
	if (parse->nb_groupe <= 2)
	{
		printf("Choisis la comparaison : M, V ou P ?\n-> ");
   		scanf("%s", &(*parse->compar));
   		if (parse->compar[0] == 'M' || parse->compar[0] == 'P')
   		{
   			while (parse->nb_groupe >= 1 && parse->nb_effectif[i] >= 30)
   			{
   				i++;
   				groupe++;
   			}
   			if (i == 1)
   			{
   				while (n_parse->new_echtn_n >= 1 && n_parse->n_nb_effectif[i-1] >= 30)
   				{
   					i++;
   					n_groupe++;
   				}
   			}
   			if ((i == 0 || i == 1) && parse->compar[0] == 'M')
   			{
				if (parse->type_echantillon[0] == 'I')
				{
					printf("FORMULE I\n");
				}
				else if (parse->type_echantillon[0] == 'A')
				{
					printf("FORMULE A\n");
				}
   			}
   			if (i >= 2 && parse->compar[0] == 'M')
   			{
				printf("Tous les echantillons sont >= 30 donc FORMULE TCL LN\n");
   			}
   			if (i >= 2 && parse->compar[0] == 'P')
   			{
   				printf("Quel est la valeur de f1 ?\n-> ");
   				green();
   				scanf("%lf", &parse->f1);
   				reset();
   				printf("Quel est la valeur de f2 ?\n-> ");
   				green();
   				scanf("%lf", &parse->f2);
   				reset();
   				if (groupe == 2)
   				{
   					parse->f = (((double)parse->nb_effectif[0] * parse->f1) + ((double)parse->nb_effectif[1] * parse->f2))
   						/ ((double)parse->nb_effectif[0] + (double)parse->nb_effectif[1]);
   					printf("Resultat de \033[1;31mf commun\033[0m = \x1B[32m%lf\033[0m\n", parse->f);
   					if (((parse->nb_effectif[0] * parse->f) >= 5)
   						&& ((parse->nb_effectif[1] * parse->f) >= 5)
   						&& ((parse->nb_effectif[0] * (1 - parse->f)) >= 5)
   						&& ((parse->nb_effectif[1] * (1 - parse->f)) >= 5))
   					{
   						display_error(parse, n_parse);
   						parse->binomial = ((parse->f1 - parse->f2)
   						/ sqrt(parse->f * ((double)1-parse->f) * (((double)1/(double)parse->nb_effectif[0]) + (double)1/(double)parse->nb_effectif[1])));
   						printf("Resultat Formule Binomial = \x1B[32m%lf\033[0m\n", parse->binomial);
   					}
   					else
   					{
   						printf("NON PARAMETRIQUE car :\n");
   						display_error(parse, n_parse);
   					}
   				}
   				else if (groupe == 1 && n_groupe == 1)
   				{
   					parse->f = (((double)parse->nb_effectif[0] * parse->f1) + ((double)n_parse->n_nb_effectif[0] * parse->f2))
   						/ ((double)parse->nb_effectif[0] + (double)n_parse->n_nb_effectif[0]);
   					printf("Resultat de \033[1;31mf commun\033[0m = \x1B[32m%lf\033[0m\n", parse->f);
					if (((parse->nb_effectif[0] * parse->f) >= 5)
					&& ((n_parse->n_nb_effectif[0] * parse->f) >= 5)
					&& ((parse->nb_effectif[0] * (1 - parse->f)) >= 5)
					&& ((n_parse->n_nb_effectif[0] * (1 - parse->f)) >= 5))
   					{
   						n_display_error(parse, n_parse);
						parse->binomial = ((parse->f1 - parse->f2)
						/ sqrt(parse->f * ((double)1-parse->f) * (((double)1/(double)parse->nb_effectif[0]) + (double)1/(double)n_parse->n_nb_effectif[0])));
   						printf("Resultat Formule Binomial = \x1B[32m%lf\033[0m\n", parse->binomial);
   					}
   					else
   					{
   						printf("NON PARAMETRIQUE car :\n");
   						n_display_error(parse, n_parse);

   					}
   				}
   				// if (parse->binomial = 1)
   				// {
   				// 	parse->binomial = 0;
   				// 	parse->binomial = (parse->f1 - parse->f2)
   				// 	/ sqrt(parse->f * ((double)1-parse->f) * (((double)1/(double)parse->nb_effectif[0]) + (double)1/(double)parse->nb_effectif[1]));
   				// }
   				// printf("F1 : %lf et F2 : %lf \n RESULTAT DE F_COMMUN : %lf\n ", parse->f1, parse->f2, parse->f);
   			}
   		}
   		else if (parse->compar[0] == 'V')
   		{
   			printf("FISHER\n");
   		}
   		else if (parse->compar[0] == 'P')
   		{

   		}
	}
	else if (parse->nb_groupe > 2)
	{

	}
}
