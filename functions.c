#include "justine.h"

int 	count_zr(char *str)
{
	int i;
	int j;

	j = 1;
	i = 0;
	// printf("str ---> %s\n", str);
	while (str[i] != '.')
	{
		i++;
	}
	i++;
	while (str[i] == '0')
	{
		j++;
		i++;
	}
	while (str[i] != '0')
	{
		j++;
		i++;
	}
	return (j);
}

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
