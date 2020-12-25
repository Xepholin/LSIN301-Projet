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

            if ((int)a->mot[a->taille] == '\n') {
                a->mot[a->taille] = ' ';
            }
            
            a->taille++;
        }
    }
}

ABR creer_ARB(char *tab, int n) {
    ABR a = malloc(sizeof(struct abr));
    a->mot = malloc(TAILLE_MAX * sizeof(char));
    a->taille = 0;
    
    for (int i = 0; i < n; i++) {
        ajoute_element(a, tab[i]);
    }

    return a;
}

/*void double_espace(ABR a) {
	for (int i = 0; i < a->taille; i++) {

        if ((int)a->mot[i] == '\n') {
            a->mot[i] = ' ';
            double_espace(a);
        }
        
		if ((int)a->mot[i] == ' ' && (int)a->mot[i+1] == ' ') {
			for (int j = i; j < a->taille; j++) {
				a->mot[j] = a->mot[j+1];
			}
		}
	}
}*/

motAct estMot(ABR a, int pos) {
    
    int motLePlusLong = 50;
    motAct motActu = malloc(sizeof(struct motActuel));
    motActu->mot = malloc(motLePlusLong * sizeof(char));

    while (pos <= motLePlusLong) {
    
        if ((int)a->mot[pos] == ' ') {
            pos++;
        }
        else {
            motActu->mot[pos] = a->mot[pos];
            pos++;
        }
        
        if ((int)a->mot[pos] == ' ' && motActu->mot[pos-1] >= 65) {
            break;
        }
    }

    return motActu;

    free(motActu);
}

void est_ABR(ABR a) {
    //int pos = 0;
    //motAct motActu = estMot(a, pos);
    
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
