#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide(ABR a)    {

    if (a == NULL)  {
        return true;
    }
    else    {
        return false;
    }
}

MOT estMot(DICO texte, MOT motActu)  {
    motActu->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));
    motActu->taille = 0;

    while (motActu->position < texte->taille)   {
    
        if (texte->T[motActu->position] == ' ') {
            motActu->position++;
        }
        else    {
            motActu->mot[motActu->taille] = texte->T[motActu->position];
            motActu->position++;
            motActu->taille++;
        }
        
        if (texte->T[motActu->position] == ' ' && texte->T[motActu->position-1] >= 65)  {
            break;
        }
    }

    return motActu;
}

ABR creer_arbre(DICO texte, MOT mot, ABR filsG, ABR filsD)    {
    ABR a = malloc(sizeof(struct noeud));
    a->mot = malloc(mot->taille * sizeof(char));
    a->filsD = filsD;
    a->filsG = filsG;
    a->mot->mot = mot->mot;
    free(mot->mot);
    return a;
}

void affiche_noeud(ABR a) {
    if (!vide(a))   {
        affiche_noeud(a->filsG);
        if(!vide(a->filsG)) {
            printf("|");
        }

        printf("%s", a->mot->mot);

        if (!vide(a->filsD)) {
            printf("|");
        }
        affiche_noeud(a->filsD);
    }
}

void affiche_arbre(ABR a)   {
    affiche_noeud(a);
    printf("\n");
}

ABR ajoute_element(ABR a, MOT mot, DICO texte)    {
    if (vide(a))    {
        return creer_arbre(texte, mot, NULL, NULL);
    }
    else    {
        mot = estMot(texte, mot);

        for (int i = 0; i < mot->taille; i++)  {
            mot->mot[i] = tolower(mot->mot[i]);
        }

        if (mot->mot == a->mot->mot)    {
            a->mot->nbOcurrence++;
        }

        if (mot->mot < a->mot->mot) {
            a->filsG = ajoute_element(a->filsG, mot, texte);
        }
        else    {
            a->filsD = ajoute_element(a->filsD, mot, texte);
        }
        return a;
    }
}

void liberer_ABR(ABR a) {
    if (vide(a))    {
        return;
    }
    liberer_ABR(a->filsD);
    liberer_ABR(a->filsG);
    free(a);
}
