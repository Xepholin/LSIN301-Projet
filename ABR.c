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

ARBRE creer_arbre(MOT mot, DICO dico, ARBRE filsG, ARBRE filsD)   {
    ARBRE arbre = malloc(sizeof(struct noeud));
    arbre->mot = malloc(sizeof(struct mot));

    arbre->mot->nbOcurrence = 0;
    arbre->mot = mot;
    arbre->filsD = filsD;
    arbre->filsG = filsG;

    mot->motSuivant = true;

    //for (; mot->position_dico < dico->taille;)  {
        arbre = ajoute_element(dico, mot, arbre);
    //}

    return arbre;
}

ARBRE ajoute_element(DICO dico, MOT mot, ARBRE arbre) {
    if (mot->motSuivant)    {
        mot->taille = 0;
        //printf("1/%s\n", arbre->mot->mot);
        mot = detecte_mot(dico, mot, arbre);
        for (int i = 0; i < mot->taille; i++)   {
            mot->mot[i] = tolower(mot->mot[i]);
        }
        mot->motSuivant = false;
        //printf("2/%s\n", mot->mot);
        //printf("3/%s\n", arbre->mot->mot);
    }

    if (vide(arbre))    {
        return creer_arbre(mot, dico, NULL, NULL);
    }
    else    {
        
        if (strcoll(arbre->mot->mot, mot->mot) < 0)    {
            arbre->filsG = ajoute_element(dico, mot, arbre->filsG);
        }

        else if (strcoll(arbre->mot->mot, mot->mot) > 0)    {
            arbre->filsD = ajoute_element(dico, mot, arbre->filsD);
        }

        else if (strcoll(arbre->mot->mot, mot->mot) == 0)    {
            arbre->mot->nbOcurrence++;
            mot->motSuivant = true;
        }
        return arbre;
    }
}

MOT detecte_mot(DICO dico, MOT mot, ARBRE arbre) {
    while (mot->position_dico < dico->taille)	{
		if (dico->T[mot->position_dico] != ' ')	{
            printf("1/%c\n", arbre->mot->mot[mot->taille]);
			mot->mot[mot->taille] = dico->T[mot->position_dico];
            printf("2/%c\n", mot->mot[mot->taille]);
            printf("3/%c\n", arbre->mot->mot[mot->taille]);
			mot->position_dico++;
			mot->taille++;

			if (dico->T[mot->position_dico] == ' ')	{
				mot->mot[mot->taille] = '\0';
                break;
			}
		}
		else	{
			mot->position_dico++;
		}
	}
    return mot;
}

void affiche_noeud(ARBRE arbre) {
    if (!vide(arbre))   {
        affiche_noeud(arbre->filsG);
        if(!vide(arbre->filsG)) {
            printf("|");
        }

        printf("%s", arbre->mot->mot);

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