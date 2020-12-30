#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide(ARBRE arbre)  {
    if (arbre == NULL)  {
        return true;
    }
    else    {
        return false;
    }
}

ARBRE creer_arbre(DICO dico, MOT mot, int position, ARBRE filsG, ARBRE filsD)   {
    ARBRE arbre = malloc(sizeof(struct noeud));
    arbre->mot = malloc(sizeof(struct mot));
    mot = detecte_mot(dico, mot, position);

    arbre->mot = mot;
    arbre->filsD = filsD;
    arbre->filsG = filsG;
    free(mot->mot);
}

ARBRE ajoute_element(DICO dico, MOT mot, int position, ARBRE arbre) {
    if (vide(arbre))    {
        arbre->mot->nbOcurrence = 0;
        return creer_arbre(dico, mot, position, NULL, NULL);
    }
    else    {
        /*if (strcoll(arbre->mot->mot, mot->mot) < 0)    {
            ajoute_element(dico, mot, position, arbre->filsG);
        }

        else if (strcoll(arbre->mot->mot, mot->mot) > 0)    {
            ajoute_element(dico, mot, position, arbre->filsD);
        }

        else if (strcoll(arbre->mot->mot, mot->mot) == 0)    {
            arbre->mot->nbOcurrence++;
        }*/
        printf("non\n");
        return arbre;
    }
}

MOT detecte_mot(DICO dico, MOT mot, int position) {
    mot->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char *));

    while (position < dico->taille)	{
		if (dico->T[position] != ' ')	{
			mot->mot[mot->taille] = dico->T[position];
			position++;
			mot->taille++;

			if (dico->T[position] == ' ')	{
				mot->mot[mot->taille] = '\0';
				return mot;
			}
		}
		else	{
			position++;
		}
	}
    return mot;
}

void liberer_arbre(ARBRE arbre) {
    if (vide(arbre))    {
        return;
    }
    liberer_arbre(arbre->filsD);
    liberer_arbre(arbre->filsG);
    free(arbre);
}