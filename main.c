#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

int nombre_caract(char *argv)	{
	FILE * texte = NULL;
	texte = fopen(argv, "r");
	int compt = 0;

	if (texte == NULL)  {
        printf("ERREUR : Le texte n'a pas pu être ouvert");
    }
    else    {
		while (fgetc(texte) != EOF)	{
			compt++;
		}
	}

	fclose(texte);
	return compt;
}

int main(int argc, char **argv)	{
	int nbc = nombre_caract(argv[1]);
	DICO dico = creer_dico(argv[1], nbc);
	int position = 1;
	bool motSuivant = true;
	char *mot = NULL;
	ARBRE A = NULL;

	for (int i = 0; i < nbc; i++)	{
		A = ajoute_element(argv[1], nbc, &position, mot, motSuivant, A);
	}

	/*char *test1 = "a";
	char *test2 = "b";

	if (strcoll(test1, test2) < 0)	{
		printf("1 > 2\n");
	}
	else if (strcoll(test1, test2) > 0)	{
		printf("1 < 2\n");
	}
	else	{
		printf("1 = 2\n");
	}*/

	affiche_arbre(A);

	liberer_arbre(A);
	liberer_mot(mot);
	liberer_fichier(dico);

	return 0;
}