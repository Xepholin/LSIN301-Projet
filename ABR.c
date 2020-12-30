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

ARBRE creer_arbre(MOT mot, ARBRE filsG, ARBRE filsD)    {
    ARBRE arbre = malloc(sizeof(struct noeud));

    arbre->mot = mot;
    arbre->filsD = filsD;
    arbre->filsG = filsG;
}

ARBRE ajoute_element(DICO dico, MOT mot, int position, ARBRE arbre) {
    if (vide(arbre))    {
        return creer_arbre(mot, NULL, NULL);
    }
    else    {
        if (strcoll(arbre->mot->mot, mot->mot) < 0)    {
            ajoute_element(dico, mot, position, arbre->filsG);
        }

        else if (strcoll(arbre->mot->mot, mot->mot) > 0)    {
            ajoute_element(dico, mot, position, arbre->filsD);
        }

        else if (strcoll(arbre->mot->mot, mot->mot) == 0)    {
            arbre->mot->nbOcurrence++;
        }
        return arbre;
    }
}

void detecte_mot(DICO texte, MOT mot, int position) {
    while (position < texte->taille)    {

        if (texte->T[position] != ' ')  {
            mot->mot[mot->taille] = texte->T[position];
            position++;
            mot->taille++;

            if (texte->T[position] == ' ')    {
                break;
            }
            
        }
        else    {
            position++;
        }
    }
}