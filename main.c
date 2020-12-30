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
	ARBRE arbre = malloc(sizeof(struct noeud));
	arbre = NULL;
	int position = 0;
	mot->taille = 0;

	arbre = ajoute_element(dico, mot, position, arbre);

	//printf("%s\n", arbre->mot->mot);
	
	liberer_arbre(arbre);
	free(mot);
	liberer_fichier(dico);
	return 0;
}
