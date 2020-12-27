#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide(ABR a) {

    if (a->mot == NULL) {
        return true;
    }
    else {
        return false;
    }
}

MOT estMot(DICO texte, int position) {
    MOT motActu = malloc(sizeof(struct mot));
    int motLePlusLong = 50;
    motActu->mot = malloc(motLePlusLong * sizeof(char));
    motActu->position = position;
    motActu->taille = 0;

    while (motActu->position < texte->taille) {
    
        if (texte->T[motActu->position] == ' ') {
            motActu->position++;
        }
        else {
            motActu->mot[motActu->taille] = texte->T[motActu->position];
            motActu->position++;
            motActu->taille++;
        }
        
        if (texte->T[motActu->position] == ' ' && texte->T[motActu->position-1] >= 65) {
            break;
        }
    }

    return motActu;
}

void ajoute_element(ABR a, MOT mot, DICO dico) {
    mot = estMot(dico, mot->position);
    int pos;
    if (a->taille < TAILLE_MAX) {
        if (!vide(a)) {
            for (int i = 0; i < mot->taille; i++) {
                a->mot[a->taille] = mot->mot[i];
                pos = a->taille;
                a->taille++;
            }
            
            a->mot[a->taille+1] = ' ';

            while (pos > 0 && a->mot[pos] )
        }
    }
}

void affiche_ABR(ABR a) {

    for (int i = 0; i < a->taille; i++) {
        printf("%c", a->mot[i]);
    }

    printf("\n");
}

void liberer_mot(MOT mot) {
    free(mot->mot);
    free(mot);
}

void liberer_ABR(ABR a) {
    free(a->mot);
    free(a);
}
