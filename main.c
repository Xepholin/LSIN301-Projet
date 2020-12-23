#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constantes.h"
#include "lectStock.h"



int main(int argc, char** argv) {
	FILE * livre;
	int compt = 0;

	livre = fopen(argv[1], "r");

	while(fgetc(livre) != EOF) {
			compt++;
	}


	printf("%d \n", compt);

	return 0;
}
