#include "justine.h"


void	clc_ecart_type(t_parsing *parse)
{
	int i = 1;
	int j = 1;
	parse->ecart_type = malloc(sizeof(double) * parse->nb_groupe + 1);
	// clean_memory(parse, (int*)parse->ecart_type);
	while (i <= parse->nb_groupe)
	{
		parse->ecart_type[i] = 0;
		i++;
	}
	i = 1;
	if (parse->nb_groupe > 1)
	{
		while (i <= parse->nb_groupe)
		{
			parse->ecart_type[i-1] = sqrt((double)parse->variance[i-1]);
			printf("Ecart type groupe \033[1;31m%d\033[0m = \x1B[32m%lf\033[0m\n", i, parse->ecart_type[i-1]);

			i++;
		}
	}
	else if (parse->nb_groupe == 1)
	{
		parse->ecart_type[i-1] = sqrt((double)parse->variance[i-1]);
		printf("L'écart-type du groupe \033[1;31m%d\033[0m = \x1B[32m%lf\033[0m\n", i, parse->ecart_type[i-1]);
	}
}

void	clc_variance(t_parsing *parse)
{
	int i = 1;
	int j = 1;
	parse->pow_variance_val = malloc(sizeof(double) * parse->nb_groupe + 1);
	parse->variance = malloc(sizeof(double) * parse->nb_groupe + 1);
	// clean_memory(parse, (int*)parse->pow_variance_val);
	// clean_memory(parse, (int*)parse->variance);
	for(int k = 0; k <= parse->nb_groupe; k++)
	{
		parse->variance[k] = 0;
		parse->pow_variance_val[k] = 0;
	}

	if (parse->nb_groupe > 1)
	{
		while (i <= parse->nb_groupe)
		{
			j = 1;
			parse->variance[i-1] = ((double)1/((double)parse->nb_effectif[i-1] - 1));
			while (j <= parse->nb_effectif[i-1])
			{
				parse->pow_variance_val[i-1] = parse->pow_variance_val[i-1] + (pow((parse->groupe[i-1][j-1] - parse->moy[i-1]), 2));
				j++;
			}
			parse->variance[i-1] = parse->variance[i-1] * parse->pow_variance_val[i-1];
			printf("La variance du groupe \033[1;31m%d\033[0m = \x1B[32m%lf\033[0m\n", i, parse->variance[i-1]);
			i++;
		}
	}
	else if (parse->nb_groupe == 1)
	{
		parse->variance[i-1] = ((double)1/((double)parse->nb_effectif[i-1] - 1));
		while (j <= parse->nb_effectif[i-1])
		{
			parse->pow_variance_val[i-1] += pow((parse->groupe[i-1][j-1] - parse->moy[i-1]), 2);
			j++;
		}
		parse->variance[i-1] *= parse->pow_variance_val[i-1];
		printf("La variance du groupe \033[1;31m%d\033[0m = \x1B[32m%lf\033[0m\n", i, parse->variance[i-1]);
	}
}

void	clc_moy(t_parsing *parse)
{
	int i = 1;
	int j = 1;
	parse->moy = malloc(sizeof(double) * parse->nb_groupe + 1);
	// clean_memory(parse, (int*)parse->moy);
	for(int k = 0; k <= parse->nb_groupe ; k++)
	{
		parse->moy[k] = 0;
	}
	if (parse->nb_groupe > 1)
	{
		while (i <= parse->nb_groupe)
		{
			j = 1;
			while (j <= parse->nb_effectif[i-1])
			{
				parse->moy[i-1] = parse->moy[i-1] + (double)parse->groupe[i-1][j-1];
				j++;
			}
			parse->moy[i-1] = parse->moy[i-1] / (double)parse->nb_effectif[i-1];
			printf("La moyenne du groupe \033[1;31m%d\033[0m = \x1B[32m%lf\033[0m\n", i, parse->moy[i-1]);
			i++;
		}
	}
	else if (parse->nb_groupe == 1)
	{
		j = 1;
		while (j <= parse->nb_effectif[i-1])
		{
			parse->moy[i-1] += (double)parse->groupe[i-1][j-1];
			j++;
		}
		parse->moy[i-1] /= (double)parse->nb_effectif[i-1];
		printf("La moyenne du groupe \033[1;31m%d\033[0m = \x1B[32m%lf\033[0m\n", i, parse->moy[i-1]);
	}

}

void	get_nb_effectif(t_parsing *parse)
{
	int i = 1;

	parse->nb_effectif = malloc(sizeof(int) * parse->nb_groupe + 1);
	// clean_memory(parse, (int*)parse->nb_effectif);
	while (i <= parse->nb_groupe)
	{
		parse->nb_effectif[i] = 0;
		i++;
	}
	i = 1;
	if (parse->nb_groupe > 1)
	{
		while (i <= parse->nb_groupe)
		{
   			printf("Nombre d'effectif du groupe \033[1;31m%d\033[0m ?\n-> ", i);
   			green();
			scanf("%d", &parse->nb_effectif[i-1]);
			reset();
			i++;
		}

	}
	else if (parse->nb_groupe == 1)
	{
		printf("Nombre d'effectif du groupe \033[1;31m%d\033[0m ?\n-> ", i);
		green();
		scanf("%d", &parse->nb_effectif[i-1]);
		reset();
	}
}


void	get_val_effectif(t_parsing *parse)
{
	int i = 1;
	int j = 1;
	parse->groupe = malloc(sizeof(double **)* parse->nb_groupe + 1);
	if (parse->nb_groupe > 1)
	{
		while (i <= parse->nb_groupe)
		{
			j = 1;
			parse->groupe[i-1] = malloc(sizeof(double *) * parse->nb_effectif[i-1] + 1);
			while(j <= parse->nb_effectif[i-1])
			{
				parse->groupe[i-1][j-1] = 0;
				j++;
			}
			j = 1;
			while (j <= parse->nb_effectif[i-1])
			{
	   			printf("Valeur \033[1;31m%d\033[0m du groupe \033[1;31m%d\033[0m ?\n-> ", j, i);
	   			green();
				scanf("%lf", &parse->groupe[i-1][j-1]);
				reset();
				j++;
			}
			i++;
		}

	}
	else if (parse->nb_groupe == 1)
	{
		parse->groupe[i-1] = malloc(sizeof(double *) * parse->nb_effectif[i-1] + 1);
		while (j <= parse->nb_effectif[i-1])
		{
   			printf("Valeur \033[1;31m%d\033[0m du groupe \033[1;31m%d\033[0m ?\n-> ", j, i);
   			green();
			scanf("%lf", &parse->groupe[i-1][j-1]);
			reset();
			j++;
		}
	}

}
