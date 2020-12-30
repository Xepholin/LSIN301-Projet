#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

int nombre_caract(char **argv)	{
	FILE * texte = NULL;
	texte = fopen(argv[1], "r");
	int compt = 0;

	while (fgetc(texte) != EOF)	{
		compt++;
	}

	fclose(texte);
	return compt;
}

int main(int argc, char **argv)	{
	int nbc = nombre_caract(argv);
	DICO dico = creer_dico(argv, nbc);
	MOT mot = malloc(sizeof(struct mot));
	mot->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));
	mot->mot = "";
	mot->taille = 0;
	int pos = 0;

	detecte_mot(dico, mot, pos);

	MOT A = malloc(sizeof(struct mot));

	A->mot = "Salut f g  nul";

	if (strcoll(A->mot, mot->mot) < 0)	{
		printf("A < B");
	}
	else if (strcoll(A->mot, mot->mot) > 0)	{
		printf("A > B");
	}
	else if (strcoll(A->mot, mot->mot) == 0)	{
		printf("A = B");
	}

	printf("\n");

	printf("%s\n", mot->mot);

	

	free(mot);
	liberer_fichier(dico);
	return 0;
}
