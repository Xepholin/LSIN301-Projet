#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

bool vide(ARBRE A) {
    if (A == NULL)  {
        return true;
    }
    else    {
        return false;
    }
}

int max(int a, int b)  {
    if (a < b)  {
        return b;
    }
    else if (a > b) {
        return a;
    }
    else    {
        return a;
    }
}

int min(int a, int b)  {
    if (a < b)  {
        return a;
    }
    else if (a > b) {
        return b;
    }
    else    {
        return a;
    }
}

ARBRE creer_arbre(char *mot, ARBRE droite, ARBRE gauche) {
    ARBRE A = malloc(sizeof(struct noeud));

    A->nbOcurrenceMot = 1;
    //A->ligne[0] = *ligne;

    A->motArbre = mot;
    A->droite = droite;
    A->gauche = gauche;
    
    //liberer_mot(mot)
    return A;
}

char *recup_mot(char *argv, int *position, char *mot)   {
    //mot = malloc(MOT_LE_PLUS_LONG * sizeof(char *));
    //mot = NULL;

    int i = 0;
    FILE *texte = NULL;
    texte = fopen(argv, "r");

    if (texte == NULL)  {
        printf("ERREUR : Le texte n'a pas pu être ouvert");
    }
    else    {
        for (int i = 0; i < *position; i++)  {
            fscanf(texte, "%s", mot);

            /*fscanf(texte, "%[0-9A-Za-z]s", mot);
            if (fgetc(texte) == '\n')   {
                *ligne = *ligne + 1;
            }*/

        }
	}

    *position = *position + 1;
    while (mot[i] != '\0')  {
        mot[i] = tolower(mot[i]);
        i++;
    }
    
    fclose(texte);
    return mot;
}

int compare(ARBRE A, char *mot) {
    if (strcoll(A->motArbre, mot) == 0)    {
        return 0;
    }
    else if ((strcoll(A->motArbre, mot) > 0))    {
        return 1;
    }
    else if (strcoll(A->motArbre, mot) < 0) {
        return 2;
    }
    else    {
        return 3;
    }
}

ARBRE ajoute_element(char *argv, int *position, char *mot, bool motSuivant, ARBRE A)  {
    if (motSuivant) {
        mot = recup_mot(argv, position, mot);
        motSuivant = false;
    }

    if (vide(A))    {
        return creer_arbre(mot, NULL, NULL);
    }
    else    {
        A = creation_parent(A);

        switch(compare(A, mot)) {
            case 0:
                //A->ligne[A->nbOcurrenceMot] = *ligne;
                A->nbOcurrenceMot++;
                motSuivant = true;
                break;
            case 1:
                //A = equilibre(A);
                A->gauche = ajoute_element(argv, position, mot, motSuivant, A->gauche);
                break;
            case 2:
                //A = equilibre(A);
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

ARBRE creation_parent(ARBRE A)  {
    if (vide(A->droite) && vide(A->gauche))    {
        return A;
    }
    else    {
        if (!vide(A->droite) && !vide(A->gauche)) {
            A->droite->parent = A;
            A->gauche->parent = A;
            A->droite = creation_parent(A->droite);
            A->gauche = creation_parent(A->gauche);
        }
        else if (!vide(A->droite) && vide(A->gauche))  {
            A->droite->parent = A;
            A->droite = creation_parent(A->droite);
        }
        else    {
            A->gauche->parent = A;
            A->gauche = creation_parent(A->gauche);
        }
        return A;
    }
}

int hauteur_sous_arbre(ARBRE A) {
    if (vide(A))    {
        return 0;
    }
    else    {
        A->hauteurD = hauteur_sous_arbre(A->droite);
        A->hauteurG = hauteur_sous_arbre(A->gauche);

        return (1 + max(A->hauteurD, A->hauteurG));
    }
}

int hauteur_arbre(ARBRE A)  {
    if (vide(A))    {
        return 0;
    }
    else    {
        return max(hauteur_sous_arbre(A->droite), hauteur_sous_arbre(A->gauche));
    }
}

int desequilibre(ARBRE A)   {
    if (vide(A->droite) && vide(A->gauche)) {
        return 0;
    }
    else    {
        return (hauteur_sous_arbre(A->gauche) - hauteur_sous_arbre(A->droite));
    }
}

ARBRE rotation_droite(ARBRE A) {

    ARBRE C = A;
    A = A->gauche;
    C->gauche = A->droite;
    A->droite = C;

    return A;
}

ARBRE rotation_gauche(ARBRE A) {
    ARBRE C = A;
    A = A->droite;
    C->droite = A->gauche;
    A->gauche = C;

    return A;
}

ARBRE equilibre(ARBRE A)    {
    if (desequilibre(A) > 1)   {
        if (desequilibre(A->gauche) == 1 || desequilibre(A->gauche) == 0) {
            A = rotation_droite(A);
            return A;
        }
        else    {
            A->gauche = rotation_gauche(A->gauche);
            A = rotation_droite(A);
            return A;
        }
    } 
    else if (desequilibre(A) < -1)   {
        if (desequilibre(A->droite) == 0 || desequilibre(A->droite) == -1)  {
            A = rotation_gauche(A);
            return A;
        }
        else    {
            A->droite = rotation_droite(A->droite);
            A = rotation_gauche(A);
            return A;
        }
    }
    return A;
}

ARBRE requilibreD(ARBRE A)   {
    if (desequilibre(A) == -2 || desequilibre(A) == 2)  {
        A = equilibre(A);
        return requilibreD(A->parent);
    }
    else if (vide(A->parent))   {
        return A;
    }
    return A;
}

ARBRE requilibreG(ARBRE A)   {
    if (desequilibre(A) == -2 || desequilibre(A) == 2)  {
        A = equilibre(A);
        return requilibreG(A->parent);
    }
    else if (vide(A->parent))   {
        return A;
    }
    return A;
}

ARBRE requilibre(ARBRE A)   {
    A = requilibreD(A);
    A = requilibreG(A);
    return A;
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

void liberer_mot(char *mot) {
    free(mot);
}