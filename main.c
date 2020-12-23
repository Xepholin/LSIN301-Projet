#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constantes.h"
#include "lectStock.h"

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
	FILE * livre = NULL;
	int compt = nombre_caract(argv);

	livre = fopen(argv[1], "r");

	DICO dico = creer_dico(argv, compt, livre);
	affiche_dico(dico, compt);

	printf("%d \n", compt);

	return 0;
}
