#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constantes.h"
#include "lectStock.h"

DICO creer_dico(char **argv, int n, FILE *texte) {
    DICO dico = malloc(sizeof(struct dico));
    dico->T = malloc(n * sizeof(char));
    dico->L = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(texte, "%c", &dico->T[i]);
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