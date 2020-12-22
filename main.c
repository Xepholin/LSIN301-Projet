#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constantes.h"
#include "lectStock.h"



int main(int argc, char** argv) {

	int compt = 0;
	FILE * livre;
	char *tab = malloc(sizeof(char));

	livre = fopen("fichier.txt", "r");

	if ((livre = fopen("fichier.txt", "r")) == NULL) {
		printf("Erreur à l'ouverture du fichier");
	}
	else {
		while(fgetc(livre) != EOF)
			compt++;
	}

	for (int i = 0; i < compt; i++) {
		fscanf(livre, "%c", &tab[i]);
		
		printf("%c \n", tab[i]);
	}


	//DICO dico = creer_dico(argv, compt, livre);

	//affiche_dico(dico, compt);

	printf("\n %d \n", compt);
	fclose(livre);
	free(tab);
	return 0;
}
