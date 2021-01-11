#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"
#include "recherche.h"
#include "chrono.h"

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

int nombre_mot(DICO dico, int n)	{
	int compt = 0;
	char *tab = dico->T;

	if (dico == NULL)	{
		return 0;
	}
	else	{
		if (tab[0] != ' ')	{
			compt++;
		}
		for (int i = 0; i < n; i++) {
			if (tab[i] == '\n')	{
				tab[i] = ' ';
			}
			if (tab[i] == ' ' && tab[i+1] == ' ')	{
				for (int j = i; j < n-1; j++)	{
					tab[j] = tab[j+1];
				}
			}
			if (tab[i] == ' ' && tab[i+1] != ' ')	{
				compt++;
			}
		}
	}
	return compt;
}

int main(int argc, char **argv)	{
	chrono_reset();

	//for (int i = 2; i <= argc; i++)	{
	char *motRecherche = argv[2];
	int nbc = nombre_caract(argv[1]);
	DICO dico = creer_dico(argv[1], nbc);
	int nbm = nombre_mot(dico, nbc);

	int position = 1;
	//int ligne = 1;
	bool motSuivant = true;
	char *mot;

	//mot = NULL;
	ARBRE A = NULL;

	for (int i = 0; motRecherche[i] != '\0'; i++)  {
		motRecherche[i] = tolower(motRecherche[i]);
	}

	for (int i = 0; i < nbm; i++)	{
		mot = malloc(MOT_LE_PLUS_LONG * sizeof(char *));
		A = ajoute_element(argv[1], &position, mot, motSuivant, A);
		//liberer_mot(mot);
	}

	recherche(motRecherche, A);

	liberer_mot(mot);
	liberer_arbre(A);
	liberer_fichier(dico);
	//}

	printf("Temps d'exécution du programme = %f\n", chrono_lap());
	return 0;
}