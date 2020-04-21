#include "justine.h"

void	clean_memory(t_parsing *parse, int *tab)
{
	int i;

	i = 0;
	while (i < parse->nb_groupe)
	{
		tab[i] = 0;
		i++;
	}
}

void	n_clean_memory(t_nparsing *n_parse, int *tab)
{
	int i;

	i = 0;
	while (i < n_parse->new_echtn_n)
	{
		tab[i] = 0;
		i++;
	}
}
