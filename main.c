#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "constantes.h"
#include "lectStock.h"
#include "ABR.h"

int nombre_caract(char **argv) {
	FILE * texte = NULL;
	texte = fopen(argv[1], "r");
	int compt = 0;

	while (fgetc(texte) != EOF) {
		compt++;
	}

	fclose(texte);
	return compt;
}

int main(int argc, char **argv) {
	int nbc = nombre_caract(argv);
	int position = 0;
	DICO dico = creer_dico(argv, nbc);

	MOT mot = estMot(dico, position);

	for (int i = 0; i < mot->taille; i++) {
		printf("%c", mot->mot[i]);
	}
	printf("\n");

	liberer_mot(mot);
	liberer_fichier(dico);
	return 0;
}
