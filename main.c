#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
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
	ABR a = creer_arbre(dico, mot, NULL, NULL);
	mot->position = 0;

	for(int i = 0; i < dico->taille; i++)	{
		a = ajoute_element(a, mot, dico);
	}
	affiche_arbre(a);

	free(mot);
	liberer_ABR(a);
	liberer_fichier(dico);
	return 0;
}
