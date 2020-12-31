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
	int nbc = nombre_caract(argv);
	DICO dico = creer_dico(argv, nbc);
	
	ARBRE arbre = malloc(sizeof(struct noeud));
	char *mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));

	arbre = NULL;
	bool motSuivant = true;

	int position = 0;


	arbre = ajoute_element(dico, mot, motSuivant, position, arbre);
	printf("%s\n", arbre->mot);
	arbre = ajoute_element(dico, mot, motSuivant, position, arbre);

	


	liberer_arbre(arbre);
	liberer_mot(mot);
	liberer_fichier(dico);

	return 0;
}
