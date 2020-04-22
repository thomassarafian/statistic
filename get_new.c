#include "justine.h"

//REMPLACER le NEW 1 par nb_groupe + ou plus
void	n_clc_ecart_type(t_nparsing *n_parse)
{
	int i = 1;
	int j = 1;
	n_parse->n_ecart_type = malloc(sizeof(double) * n_parse->new_echtn_n + 1);
	// n_clean_memory(n_parse, (int *)n_parse->n_ecart_type);
	while (i <= n_parse->new_echtn_n)
	{
		n_parse->n_ecart_type[i] = 0;
		i++;
	}
	i = 1;
	if (n_parse->new_echtn_n > 1)
	{
		while (i <= n_parse->new_echtn_n)
		{
			n_parse->n_ecart_type[i-1] = sqrt((double)n_parse->n_variance[i-1]);
			printf("Ecart type du \033[1;31mnouveau\033[0m groupe \t\033[1;31m%d\033[0m = \x1B[32m%lf\033[0m <=> \x1B[32m%.2e\033[0m\n\n", i, n_parse->n_ecart_type[i-1],  n_parse->n_ecart_type[i-1]);
			i++;
		}
	}
	else if (n_parse->new_echtn_n == 1)
	{
		n_parse->n_ecart_type[i-1] = sqrt((double)n_parse->n_variance[i-1]);
		printf("Ecart type du \033[1;31mnouveau\033[0m groupe \t\033[1;31m%d\033[0m = \x1B[32m%lf\033[0m <=> \x1B[32m%.2e\033[0m\n\n", i, n_parse->n_ecart_type[i-1], n_parse->n_ecart_type[i-1]);
	}
}

void	n_clc_variance(t_nparsing *n_parse)
{
	int i = 1;
	int j = 1;
	n_parse->n_pow_variance_val = malloc(sizeof(double) * n_parse->new_echtn_n + 1);
	n_parse->n_variance = malloc(sizeof(double) * n_parse->new_echtn_n + 1);
	while (i <= n_parse->new_echtn_n)
	{
		n_parse->n_pow_variance_val[i] = 0;
		n_parse->n_variance[i] = 0;
		i++;
	}
	i = 1;
	// n_clean_memory(n_parse, (int *)n_parse->n_pow_variance_val);
	// n_clean_memory(n_parse, (int *)n_parse->n_variance);
	if (n_parse->new_echtn_n > 1)
	{
		while (i <= n_parse->new_echtn_n)
		{
			j = 1;
			n_parse->n_variance[i-1] = ((double)1/((double)n_parse->n_nb_effectif[i-1] - 1));
			while (j <= n_parse->n_nb_effectif[i-1])
			{
				n_parse->n_pow_variance_val[i-1] = n_parse->n_pow_variance_val[i-1] + (pow((n_parse->n_groupe[i-1][j-1] - n_parse->n_moy[i-1]), 2));
				j++;
			}
			n_parse->n_variance[i-1] = n_parse->n_variance[i-1] * n_parse->n_pow_variance_val[i-1];
			printf("Variance du \033[1;31mnouveau\033[0m groupe \t\033[1;31m%d\033[0m = \x1B[32m%lf\033[0m <=> \x1B[32m%.2e\033[0m\n", i, n_parse->n_variance[i-1], n_parse->n_variance[i-1]);
			i++;
		}
	}
	else if (n_parse->new_echtn_n == 1)
	{
		n_parse->n_variance[i-1] = ((double)1/((double)n_parse->n_nb_effectif[i-1] - 1));
		while (j <= n_parse->n_nb_effectif[i-1])
		{
			n_parse->n_pow_variance_val[i-1] += pow((n_parse->n_groupe[i-1][j-1] - n_parse->n_moy[i-1]), 2);
			j++;
		}
		n_parse->n_variance[i-1] *= n_parse->n_pow_variance_val[i-1];
		printf("Variance du \033[1;31mnouveau\033[0m groupe \t\033[1;31m%d\033[0m = \x1B[32m%lf\033[0m <=> \x1B[32m%.2e\033[0m\n", i, n_parse->n_variance[i-1], n_parse->n_variance[i-1]);
	}
}

void	n_clc_moy(t_nparsing *n_parse)
{
	int i = 1;
	int j = 1;
	n_parse->n_moy = malloc(sizeof(double) * n_parse->new_echtn_n + 1);
	// n_clean_memory(n_parse, (int *)n_parse->n_moy);
	while (i <= n_parse->new_echtn_n + 1)
	{
		n_parse->n_moy[i] = (double)0;
		i++;
	}
	i = 1;
	if (n_parse->new_echtn_n > 1)
	{
		while (i <= n_parse->new_echtn_n)
		{
			j = 1;
			while (j <= n_parse->n_nb_effectif[i-1])
			{
				n_parse->n_moy[i-1] = n_parse->n_moy[i-1] + (double)n_parse->n_groupe[i-1][j-1];
				// printf("n_parse->n_groupe[i-1][j-1] : %lf\n", n_parse->n_groupe[i-1][j-1]);
				// printf("n_parse->n_moy[i-1] : %lf\n", n_parse->n_moy[i-1]);
				j++;
			}
			n_parse->n_moy[i-1] = n_parse->n_moy[i-1] / (double)n_parse->n_nb_effectif[i-1];
			// printf("n_parse->n_nb_effectif[i-1] : %d\n", n_parse->n_nb_effectif[i-1]);
			printf("\nLa moyenne du \033[1;31mnouveau\033[0m groupe \t\033[1;31m%d\033[0m est : \x1B[32m%lf\033[0m <=> \x1B[32m%.2e\033[0m\n", i, n_parse->n_moy[i-1], n_parse->n_moy[i-1]);
			i++;
		}
	}
	else if (n_parse->new_echtn_n == 1)
	{
		j = 1;
		while (j <= n_parse->n_nb_effectif[i-1])
		{
			n_parse->n_moy[i-1] = n_parse->n_moy[i-1] + (double)n_parse->n_groupe[i-1][j-1];
			j++;
		}
		n_parse->n_moy[i-1] = n_parse->n_moy[i-1] / (double)n_parse->n_nb_effectif[i-1];
		printf("\nLa moyenne du \033[1;31mnouveau\033[0m groupe \t\033[1;31m%d\033[0m est : \x1B[32m%lf\033[0m <=> \x1B[32m%.2e\033[0m\n", i, n_parse->n_moy[i-1], n_parse->n_moy[i-1]);
	}
}

void	n_get_nb_effectif(t_nparsing *n_parse)
{
	int i = 1;

	n_parse->n_nb_effectif = malloc(sizeof(int) * n_parse->new_echtn_n + 1);
	// n_clean_memory(n_parse, (int *)n_parse->n_nb_effectif);
	while (i <= n_parse->new_echtn_n)
	{
		n_parse->n_nb_effectif[i] = 0;
		i++;
	}
	i = 1;
	if (n_parse->new_echtn_n > 1)
	{
		while (i <= n_parse->new_echtn_n)
		{
   			printf("Nombre d'effectif du \033[1;31mnouveau\033[0m groupe \033[1;31m%d\033[0m ?\n-> ", i);
   			green();
			scanf("%d", &n_parse->n_nb_effectif[i-1]);
			reset();
			i++;
		}
	}
	else if (n_parse->new_echtn_n == 1)
	{
		printf("Nombre d'effectif du \033[1;31mnouveau\033[0m groupe \033[1;31m%d\033[0m ?\n-> ", i);
		green();
		scanf("%d", &n_parse->n_nb_effectif[i-1]);
		reset();
	}
}


void	n_get_val_effectif(t_nparsing *n_parse)
{
	int i = 1;
	int j = 1;
	n_parse->n_groupe = malloc(sizeof(double **)* n_parse->new_echtn_n + 1);
	if (n_parse->new_echtn_n > 1)
	{
		while (i <= n_parse->new_echtn_n)
		{
			j = 1;
			n_parse->n_groupe[i-1] = malloc(sizeof(double *) * n_parse->n_nb_effectif[i-1] + 1);
			while(j <= n_parse->n_nb_effectif[i-1])
			{
				n_parse->n_groupe[i-1][j-1] = 0;
				j++;
			}
			j = 1;
			while (j <= n_parse->n_nb_effectif[i-1])
			{
	   			printf("Valeur \033[1;31m%d\033[0m du \033[1;31mnouveau\033[0m groupe \033[1;31m%d\033[0m ?\n-> ", j, i);
	   			green();
				scanf("%lf", &n_parse->n_groupe[i-1][j-1]);
				reset();
				j++;
			}
			i++;
		}
	}
	else if (n_parse->new_echtn_n == 1)
	{
		n_parse->n_groupe[i-1] = malloc(sizeof(double *) * n_parse->n_nb_effectif[i-1] + 1);
		while (j <= n_parse->n_nb_effectif[i-1])
		{
   			printf("Valeur \033[1;31m%d\033[0m du \033[1;31mnouveau\033[0m groupe \033[1;31m%d\033[0m ?\n-> ", j, i);
   			green();
			scanf("%lf", &n_parse->n_groupe[i-1][j-1]);
			reset();
			j++;
		}
	}

}

