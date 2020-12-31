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

ARBRE creer_arbre(DICO dico, MOT mot, ARBRE filsG, ARBRE filsD)   {
    ARBRE arbre = malloc(sizeof(struct noeud));
    arbre->mot = malloc(mot->taille * sizeof(char *));

    arbre->nbOcurrenceMot = 0;
    arbre->mot = mot->mot;
    arbre->tailleMot = mot->taille;
    arbre->filsD = filsD;
    arbre->filsG = filsG;

    mot->motSuivant = true;
    
    mot->taille = 0;
    printf("%s\n", arbre->mot);

    mot->mot[0] = '\0';
    printf("%s\n", mot->mot);
    printf("%s\n", arbre->mot);

    return arbre;
}

ARBRE ajoute_element(DICO dico, MOT mot, ARBRE arbre) {
    if (mot->motSuivant)    {
        mot = detecte_mot(dico, mot);
        mot->motSuivant = false;
    }
    
    if (vide(arbre))    {
        return creer_arbre(dico, mot, NULL, NULL);
    }
    else    {
        

        if (strcoll(arbre->mot, mot->mot) < 0)    {
            ajoute_element(dico, mot, arbre->filsG);
        }

        else if (strcoll(arbre->mot, mot->mot) > 0)    {
            ajoute_element(dico, mot, arbre->filsD);
        }

        else if (strcoll(arbre->mot, mot->mot) == 0)    {
            arbre->nbOcurrenceMot++;
            printf("%d\n", arbre->nbOcurrenceMot);
        }
        return arbre;
    }
}

MOT detecte_mot(DICO dico, MOT mot) {
    while (mot->position_dico < dico->taille)	{
		if (dico->T[mot->position_dico] != ' ')	{
			mot->mot[mot->taille] = dico->T[mot->position_dico];
			mot->position_dico++;
			mot->taille++;

			if (dico->T[mot->position_dico] == ' ')	{
				mot->mot[mot->taille] = '\0';
				return mot;
			}
		}
		else	{
			mot->position_dico++;
		}
	}
    mot->motFin = true;
    return mot;
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

void liberer_mot(MOT mot)   {
    free(mot->mot);
    free(mot);
}