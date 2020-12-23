#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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

/*int nombre_ligne(char **argv) {
	FILE * texte = NULL;
	texte = fopen(argv[1], "r");
	int compt = 0;

	while (fgetc(texte) != EOF) {
		if (fgetc(texte) == '\n') {
			compt++;
		}
	}
	fclose(texte);
	return compt;
}*/


int main(int argc, char **argv) {
	int nbc = nombre_caract(argv);

	DICO dico = creer_dico(argv, nbc);
	affiche_dico(dico, nbc);
	printf("%d \n", nbc);

	liberer_fichier(dico);
	return 0;
}
