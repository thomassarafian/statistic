#include "justine.h"
#include "get.c"
#include "parametric.c"
#include "non_parametric.c"
#include "get_new.c"
#include "color.c"
#include "functions.c"

int main()
{
	t_parsing parse;
	t_nparsing n_parse;
	parse.type_echantillon = malloc(sizeof(char) * 3);
	parse.compar = malloc(sizeof(char) * 3);
	int i;
	int j = 1;
	i = 1;
	system("clear");

	char *s = malloc(100);

	double test = 0.000000000000432;

	// int ooo = 12;
	// sprintf(s,"%.*lf", ooo, test);

	// printf("double : %s\n", s);

	// int count = count_zr(s) - 1;

	// printf("NB 0 : %d\n", count);
	printf("|%e|\n", test);
	// printf("𝓏 = 𝑛₁𝘧₁𝓂𝑛𝑠\n");
	// long double test = -123.456789123456789;
	// printf("\n test : %10.14Lf\n", test);
	yellow();
	printf("\n\n\t\tCOUCOU JUSTINE :)\n\n");
	reset();
	printf("Tape 1 pour \033[1;31mQUANTITATIVE\033[0m ou 2 pour \033[1;31mQUALITATIVE\033[0m\n-> ");
	green();
	scanf("%d", &parse.var_qu);
	reset();
	printf("Type d'échantillon : \033[1;31mA\033[0m ou \033[1;31mI\033[0m ? \n-> ");
	green();
	scanf("%s", &(*parse.type_echantillon));
	reset();
	printf("Nombre de groupe ?\n-> ");
	green();
	scanf("%d", &parse.nb_groupe);
	reset();
	//recuperer le nb d'effectif par groupe
	get_nb_effectif(&parse);
	//recuperer les valeurs des effectifs
	printf("Tape \033[1;31m1\033[0m pour rentrer les valeurs de l'échantillon ou \033[1;31m2\033[0m pour ne pas les rentrer\n-> ");
	green();
	scanf("%d", &parse.input_val);
	reset();
	if (parse.input_val == 1)
	{
		get_val_effectif(&parse);
		//->MOYENNE
		clc_moy(&parse);
		//->VARIANCE
		clc_variance(&parse);
		//->ECART TYPE
		clc_ecart_type(&parse);
	}
	printf("Est-ce que la \033[1;31mNORMALITÉ\033[0m est respectée ? Tape \033[1;31m1\033[0m pour oui et \033[1;31m2\033[0m pour non\n-> ");
	green();
	scanf("%d", &parse.normalite);
	reset();
	printf("Est-ce que \033[1;31ml'HOMOSCEDASTICITÉ\033[0m est respectée ? Tape \033[1;31m1\033[0m pour oui et \033[1;31m2\033[0m pour non\n-> ");
	green();
	scanf("%d", &parse.homo);
	reset();
	if (parse.normalite == 1 && parse.homo == 1)
	{
		printf("\nTu es dans \033[1;33mPARAMETRIQUE\033[0m\n\n");
		parametric(&parse, &n_parse);
	}
	else
	{
		non_parametric(&parse, &n_parse);
		printf("\nTu es dans \033[1;33mNON PARAMETRIQUE\033[0m\n");
	}




 // printf("\nvarqu : %d - compar : %c - type_echantill : %c\n", parse.var_qu, parse.compar, parse.type_echantillon);
 // i =0;

 // while (i < parse.nb_groupe)
 // {
 // 	j = 0;
 // 	printf("moyenne groupe %d = %lf\n", i, parse.moy[i]);
 // 	while (j < parse.nb_effectif[i])
 // 	{
	//  	// printf("groupe  : %d\n", parse.nb_effectif[i]);
	//  	printf("groupe[%d][%d] = %f\n", i, j, parse.groupe[i][j]);
	//  	j++;
 // 	}
 // 	i++;
 // }

   // int a, b, c;
   //  printf("Enter the first value:");
   //  scanf("%d", &a);
   //  printf("Enter the second value:");
   //  scanf("%d", &b);
   //  c = a + b;
   //  printf("%d + %d = %d\n", a, b, c);
    return 0;
}
