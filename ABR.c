#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide(ARBRE arbre)    {

    if (arbre == NULL)  {
        return true;
    }
    else    {
        return false;
    }
}

void recupMot(DICO texte, MOT motActu, int position)  {
    motActu->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));

    while (position < texte->taille)   {
    
        if (texte->T[position] == ' ') {
            position++;
        }
        else    {
            motActu->mot[motActu->taille] = texte->T[position];
            position++;
            motActu->taille++;
        }
        
        if (texte->T[position] == ' ' && texte->T[position-1] >= 65)  {
            break;
        }
    }
}

ARBRE creer_arbre(DICO dico, MOT mot, ARBRE filsG, ARBRE filsD, int position)    {
    ARBRE arbre = malloc(sizeof(struct noeud));
    arbre->mot = malloc(sizeof(struct mot));
    arbre->mot->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));

    mot->taille = 0;

    arbre->mot->mot = mot->mot;
    arbre->filsG = filsG;
    arbre->filsD = filsD;

    for (int i = 0; i < dico->taille; i++)  {
        arbre = ajoute_element(dico, mot, arbre, position);
    }

    return arbre;
}

ARBRE ajoute_element(DICO dico, MOT mot, ARBRE arbre, int position)   {

    if (vide(arbre))    {
        return creer_arbre(dico, mot, NULL, NULL, position);
    }
    else    {
        for (int i = 0; i < mot->taille; i++)   {
            
            if (arbre->mot->mot[i] > mot->mot[i])   {
                arbre->filsG = ajoute_element(dico, mot, arbre->filsG, position);
            }
            else    {
                arbre->filsD = ajoute_element(dico, mot, arbre->filsD, position);
            }
        }
        return arbre;
    }
}

void affiche_arbre(ARBRE arbre) {
    if (!vide(arbre))   {
        affiche_arbre(arbre->filsG);
        if (!vide(arbre->filsG))    {
            printf("|");
        }
        for (int i = 0; i < arbre->mot->taille; i++)    {
            printf("%c", arbre->mot->mot[i]);
        }
        if (!vide(arbre->filsD))    {
            printf("|");
        }
        affiche_arbre(arbre->filsD);
    }
}

void liberer_arbre(ARBRE arbre) {
    if (vide(arbre))    {
        return;
    }
    liberer_arbre(arbre->filsD);
    liberer_arbre(arbre->filsG);
    free(arbre->mot->mot);
    free(arbre->mot);
    free(arbre);
}

