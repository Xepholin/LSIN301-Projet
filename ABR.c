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

    double_espace(a, n);

    return a;
}

void double_espace(ABR a, int n) {
	for (int i = 0; i < n; i++) {

        if ((int)a->mot[i] == '\n') {
            a->mot[i] = ' ';
            double_espace(a, n);
        }
        
		if ((int)a->mot[i] == ' ' && (int)a->mot[i+1] == ' ') {
			for (int j = i; j < n; j++) {
				a->mot[j] = a->mot[j+1];
			}
		}
	}
}

void est_ABR(ABR a) {
    int motLePlusLong = 195;
    //char motActu[motLePlusLong];

    for (int i = 0; i < motLePlusLong; i++) {
        if ((int)a->mot[i] == ' ') {
            printf(".");
        }
    }

    /*for (int i = 0; i < motLePlusLong; i++) {
        printf("%c", motActu[i]);
    }*/
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
