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
	
	MOT mot = malloc(sizeof(struct mot));
	mot->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char *));
	ARBRE arbre = malloc(sizeof(struct noeud));

	arbre = NULL;
	mot->taille = 0;
	mot->position_dico = 0;
	mot->motFin = false;
	mot->motSuivant = true;

	arbre = ajoute_element(dico, mot, arbre);
	arbre = ajoute_element(dico, mot, arbre);

	liberer_arbre(arbre);
	liberer_mot(mot);
	liberer_fichier(dico);
	return 0;
}
