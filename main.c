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
	
	int pos = 0;

	mot->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));
	mot->taille = 0;

    while (pos < dico->taille)   {
    
        if (dico->T[pos] == ' ') {
            pos++;
        }
        else    {
            mot->mot[mot->taille] = dico->T[pos];
            pos++;
            mot->taille++;
        }
        
        if (dico->T[pos] == ' ' && dico->T[pos-1] >= 65)  {
            break;
        }
    }

	for (int i = 0; i < mot->taille; i++)	{
		printf("%c", mot->mot[i]);
	}
	printf("\n");
	
	//ARBRE a = creer_arbre(dico, mot, NULL, NULL, pos);

	//affiche_arbre(a);

	free(mot->mot);
	free(mot);
	//liberer_arbre(a);
	liberer_fichier(dico);
	return 0;
}
