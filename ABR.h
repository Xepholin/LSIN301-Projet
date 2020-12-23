struct abr {
    char *mot;
    int taille;
};

typedef struct abr *ABR;

ABR creer_ARB(char *tab, int n);

void affiche_ABR(ABR abr);

void ajoute_element(ABR abr, char *tab);