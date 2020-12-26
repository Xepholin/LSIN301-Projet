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
            //printf("%c\n", motActu->mot[motActu->taille]);
            motActu->position++;
            motActu->taille++;
        }
        
        if (texte->T[motActu->position] == ' ' && texte->T[motActu->position-1] >= 65) {
            printf("break à %d\nlettre = %c\n", motActu->position, texte->T[motActu->position-1]);
            break;
        }
    }

    return motActu;
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
