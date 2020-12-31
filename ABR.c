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

ARBRE creer_arbre(char *mot, ARBRE filsG, ARBRE filsD)   {
    ARBRE arbre = malloc(sizeof(struct noeud));
    arbre->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char *));

    arbre->nbOcurrenceMot = 0;
    arbre->mot = mot;
    arbre->filsD = filsD;
    arbre->filsG = filsG;

    return arbre;
}

ARBRE ajoute_element(DICO dico, char *mot, bool motSuivant, int position, ARBRE arbre) {
    if (motSuivant)    {
        int tailleMot = 0;
        detecte_mot(dico, mot, position, tailleMot);
        motSuivant = false;
    }
    
    if (vide(arbre))    {
        return creer_arbre(mot, NULL, NULL);
    }
    else    {
        printf("%s\n", arbre->mot);
        printf("%s\n", mot);

        if (strcoll(arbre->mot, mot) < 0)    {
            ajoute_element(dico, mot, motSuivant, position, arbre->filsG);
        }

        else if (strcoll(arbre->mot, mot) > 0)    {
            ajoute_element(dico, mot, motSuivant, position, arbre->filsD);
        }

        else if (strcoll(arbre->mot, mot) == 0)    {
            arbre->nbOcurrenceMot++;
            printf("%d\n", arbre->nbOcurrenceMot);
        }
        return arbre;
    }
}

void detecte_mot(DICO dico, char *mot, int position, int tailleMot) {
    while (position < dico->taille)	{
		if (dico->T[position] != ' ')	{
			mot[tailleMot] = dico->T[position];
			position++;
			tailleMot++;

			if (dico->T[position] == ' ')	{
				mot[tailleMot] = '\0';
                break;
			}
		}
		else	{
			position++;
		}
	}
}

void affiche_noeud(ARBRE arbre) {
    if (!vide(arbre))   {
        affiche_noeud(arbre->filsG);
        if(!vide(arbre->filsG)) {
            printf("|");
        }

        printf("%s", arbre->mot);

        if (!vide(arbre->filsD)) {
            printf("|");
        }
        affiche_noeud(arbre->filsD);
    }
}

void affiche_arbre(ARBRE arbre)   {
    affiche_noeud(arbre);
    printf("\n");
}

void liberer_arbre(ARBRE arbre) {
    if (vide(arbre))    {
        return;
    }
    liberer_arbre(arbre->filsD);
    liberer_arbre(arbre->filsG);
    free(arbre);
}

void liberer_mot(char *mot)   {
    free(mot);
}