#ifndef HEADER_FILE
# define HEADER_FILE
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct s_parsing
{
	int var_qu; //Quantitative ou qualitative
	char *compar; // M, V ou P
	char *type_echantillon; //App ou Ind
	int nb_groupe; //nb de groupe
	int *nb_effectif; //nb d'effecif par groupe
	double *val_eff; //les valeurs des effectifs
	double **groupe; //groupe[nb_groupe][nb_effectif] = val_eff

	int input_val;

	//clc all data
	double *moy;
	double *variance;
	double *pow_variance_val;
	double *ecart_type;

	int param; //parametrique ou non
	int normalite; //normalite ou hosmo
	int homo; //normalite ou hosmo
	//new echantillon if param
	int new_echantillon;



	double f1; //proportion g1
	double f2; //proportion g2
	double f; //f_commun

	/*
	FORMULE MATHEMATIQUE
	*/
	double binomial;


};
typedef struct s_parsing t_parsing;

struct s_nparsing
{
	//new echantillon if param
	int new_echantillon;


	int new_echtn_n; //nb du new
	int *n_nb_effectif; //nb d'effecif par groupe new

	double **n_groupe; //groupe[nb_groupe][nb_effectif] = val_eff new

	int n_input_val;
	double *n_moy;
	double *n_variance; //variance new
	double *n_pow_variance_val; // tmp variance new
	double *n_ecart_type; //ecart type new groupe
};
typedef struct s_nparsing t_nparsing;


void	clc_ecart_type(t_parsing *parse);
void	clc_variance(t_parsing *parse);
void	clc_moy(t_parsing *parse);
void	get_nb_effectif(t_parsing *parse);
void	get_val_effectif(t_parsing *parse);

void	n_clc_ecart_type(t_nparsing *n_parse);
void	n_clc_variance(t_nparsing *n_parse);
void	n_clc_moy(t_nparsing *n_parse);
void	n_get_nb_effectif(t_nparsing *n_parse);
void	n_get_val_effectif(t_nparsing *n_parse);

void	clean_memory(t_parsing *parse, int *tab);
void	n_clean_memory(t_nparsing *n_parse, int *tab);


void reset();
void yellow();
void red();
void green();
void blue();
void magenta();
void cyan();

#endif
