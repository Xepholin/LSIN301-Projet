#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide (ARBRE A) {
    if (A == NULL)  {
        return true;
    }
    else    {
        return false;
    }
}

ARBRE creer_arbre(char *mot, ARBRE droite, ARBRE gauche) {
    ARBRE A = malloc(sizeof(struct noeud));

    A->nbOcurrenceMot = 1;
    A->motArbre = mot;
    A->droite = droite;
    A->gauche = gauche;

    return A;
}

char *recup_mot(char *argv, int *position, char *mot)   {
    
    FILE *texte = NULL;
    texte = fopen(argv, "r");

    if (texte == NULL)  {
        printf("ERREUR : Le texte n'a pas pu être ouvert");
    }
    else    {
        for (int i = 0; i < *position; i++)  {
            fscanf(texte, "%s", mot);
        }
	}
    fclose(texte);
    return mot;
}

int compare(ARBRE A, char *mot) {
    if (strcoll(A->motArbre, mot) == 0)    {
        return 0;
    }
    else if ((strcoll(A->motArbre, mot) < 0))    {
        return 1;
    }
    else if (strcoll(A->motArbre, mot) > 0) {
        return 2;
    }
    else    {
        return 3;
    }
}

ARBRE ajoute_element(char *argv, int *position, char *mot, bool motSuivant, ARBRE A)  {
    if (motSuivant) {
        
        FILE *texte = NULL;
        texte = fopen(argv, "r");

        if (texte == NULL)  {
            printf("ERREUR : Le texte n'a pas pu être ouvert");
        }
        else    {
            for (int i = 0; i < *position; i++)  {
                fscanf(texte, "%s", mot);
            }
        }
        fclose(texte);

        int i = 0;
        *position = *position + 1;
        while (mot[i] != '\0')  {
            mot[i] = tolower(mot[i]);
            i++;
        }
        
        motSuivant = false;
    }

    if (vide(A))    {
        return creer_arbre(mot, NULL, NULL);
    }
    else    {
        printf("%s\n", A->motArbre);
        printf("%s\n", mot);
        switch(compare(A, mot)) {
            case 0:
                A->nbOcurrenceMot++;
                motSuivant = true;
                break;
            case 1:
                A->gauche = ajoute_element(argv, position, mot, motSuivant, A->gauche);
                break;
            case 2:
                A->droite = ajoute_element(argv, position, mot, motSuivant, A->droite);
                break;
            case 3:
                printf("Erreur comparaison mot\n");
                break;
            default:
                printf("Erreur comparaison mot\n");
                break;
        }
        return A;
    }
}

void affiche_noeud(ARBRE A) {
    if (!vide(A))   {
        affiche_noeud(A->gauche);
        if(!vide(A->gauche)) {
            printf(" <- ");
        }

        printf("%s", A->motArbre);

        if (!vide(A->droite)) {
            printf(" -> ");
        }
        affiche_noeud(A->droite);
    }
}

void affiche_arbre(ARBRE A)   {
    affiche_noeud(A);
    printf("\n");
}

void liberer_arbre(ARBRE A) {
    if (vide(A))    {
        return;
    }
    liberer_arbre(A->droite);
    liberer_arbre(A->gauche);
    free(A);
}