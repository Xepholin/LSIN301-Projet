#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "constantes.h"
#include "ABR.h"

bool vide(ABR a) {
    if (a->mot == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void ajoute_element(ABR a, char x) {
    if (a->taille < TAILLE_MAX) {
        if (!vide(a)) {
            a->mot[a->taille] = x;
            a->taille++;
        }
    }
}

ABR creer_ARB(char *tab, int n) {
    ABR a = malloc(sizeof(struct abr));
    a->taille = 0;
    a->mot = malloc(TAILLE_MAX * sizeof(char));

    for (int i = 0; i < n; i++) {
        ajoute_element(a, tab[i]);
    }

	for (int i = 0; i < n; i++) {
		if ((int)a->mot[i] == ' ' && (int)a->mot[i+1] == ' ') {
			for (int j = i; j < n; j++) {
				a->mot[j] = a->mot[j+1];
			}
		}
	}

    return a;
}

void est_ABR(ABR a) {
    
}

void affiche_ABR(ABR a) {
    for (int i = 0; i < a->taille; i++) {
        printf("%c", a->mot[i]);
    }
    printf("\n");
}

void liberer_ABR(ABR a) {
    free(a->mot);
    free(a);
}
