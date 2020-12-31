#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "constantes.h"
#include "lectStock.h"

DICO creer_dico(char **argv, int n) {
    DICO dico = malloc(sizeof(struct dico));
    dico->T = malloc(n * sizeof(char *));
    dico->L = malloc(n * sizeof(int *));

    FILE * texte = NULL;
    texte = fopen(argv[1], "r");
    int j = 0;
    dico->taille = n;

    if (texte == NULL)  {
        printf("ERREUR : Le texte n'a pas pu être ouvert");
    }
    else    {
        for (int i = 0; i < n; i++) {
            fscanf(texte, "%c", &dico->T[i]);

            if (dico->T[i] == '\n') {
                dico->L[j] = j;
                j++;
            }
        }
    }

    fclose(texte);
    return dico;
}

void affiche_dico(DICO dico)    {
    
    for (int i = 0; i < dico->taille; i++)  {
        printf("%c", dico->T[i]);
    }

    printf("\n");
}

void liberer_fichier(DICO dico) {
    free(dico->T);
    free(dico->L);
    free(dico);
}