#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"
#include "recherche.h"

void recherche(char *argv, ARBRE A) {
    if (vide(A))    {
        return;
    }
    else    {
        if (strcoll(argv, A->motArbre) == 0) {
        printf("Nombre d'ocurrence = %d\n", A->nbOcurrenceMot);
            return;
        }
        else if (strcoll(argv, A->motArbre) > 0)   {
            recherche(argv, A->droite);
        }
        else    {
            recherche(argv, A->gauche);
        }
    }
}

void affiche_ligne(DICO dico, ARBRE A)  {
    return;
}