#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constantes.h"
#include "lectStock.h"

DICO creer_dico(char **argv, int n, FILE *texte) {
    int j = 1;
    DICO dico = malloc(sizeof(struct dico));
    dico->T = malloc(n * sizeof(char));
    dico->L = malloc(n * sizeof(int));

    dico->L[j] = j;

    for (int i = 0; i < n; i++) {
        fscanf(texte, "%c", &dico->T[i]);
        if (dico->T[i] == '\n') {
            dico->L[j] = j;
            j++;
        }
    }
    
    return dico;
}

void affiche_dico(DICO dico, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", dico->T[i]);
    }
    printf("\n");
}

void liberer_fichier(DICO dico) {
    free(dico->L);
    free(dico->T);
    free(dico);
}