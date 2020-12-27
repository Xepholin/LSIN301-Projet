#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide(ABR a)    {

    if (a->mot == NULL)  {
        return true;
    }
    else    {
        return false;
    }
}

MOT estMot(DICO texte)  {
    MOT motActu = malloc(sizeof(struct mot));
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

void ajoute_element(ABR a, MOT mot, DICO dico)  {
    if (a->taille < TAILLE_MAX) {
        if (!vide(a))   {

            for (int i = 0; i < mot->taille; i++)   {
                transpo(a->mot[i]);

                if (mot->mot[i] < a->mot[i])    {

                    a->filsG = malloc(sizeof(struct abr));
                    a->filsG->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));

                    for (int i = 0; i < mot->taille; i++)   {
                        a->filsG->mot[i] = mot->mot[i];
                        a->taille++;
                    }
                    a->mot = a->filsG->mot;
                    break;
                }

                if (mot->mot[i] > a->mot[i])    {
                    a->filsD = malloc(sizeof(struct abr));
                    a->filsD->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));

                    for (int i = 0; i < mot->taille; i++)   {
                        a->filsD->mot[i] = mot->mot[i];
                        a->taille++;
                    }
                    a->mot = a->filsD->mot;
                    break;
                }
            }
        }
        else    {
            printf("L'arbre est vide \n");
        }
    }
}

ABR creer_ARB(DICO dico) {
    ABR a = malloc(sizeof(struct abr));
    a->mot = malloc(MOT_LE_PLUS_LONG * sizeof(char));
    a->taille = 0;
    
    for (int i = 0; i < TAILLE_MAX; i++) {
        MOT mot = estMot(dico);
        ajoute_element(a, mot, dico);
    }

    return a;
}

void affiche_ABR(ABR a) {

    for (int i = 0; i < a->taille; i++) {
        printf("%c", a->mot[i]);
    }

    printf("\n");
}

void liberer_mot(MOT mot)   {
    free(mot->mot);
    free(mot);
}

void liberer_ABR(ABR a) {
    free(a);
}
