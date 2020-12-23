#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constantes.h"
#include "lectStock.h"

DICO creer_dico(char **argv, int n) {
    FILE * texte = NULL;
    texte = fopen(argv[1], "r");
    int j = 0;

    DICO dico = malloc(sizeof(struct dico));
    dico->T = malloc(n * sizeof(char));
    dico->L = malloc(n * sizeof(int));

    if (texte != NULL) {
        for (int i = 0; i < n; i++) {
            fscanf(texte, "%c", &dico->T[i]);

            if (dico->T[i] == '\n') {
                dico->L[j] = j+1;
                j++;
            }
        }
    }


    fclose(texte);
    return dico;
}

void affiche_dico(DICO dico, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", dico->T[i]);
    }
    
    printf("\n");
}

void liberer_fichier(DICO dico) {
    free(dico->T);
    free(dico->L);
    free(dico);
}