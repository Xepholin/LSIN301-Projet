struct abr {
    char *mot;
    int *ligne;
    int taille;
    struct abr *filsG;
    struct abr *filsD;
};

typedef struct abr *ABR;

bool vide(ABR a);

void ajoute_element(ABR a, char x);

ABR creer_ARB(char *tab, int n);

void est_ABR(ABR a);

void affiche_ABR(ABR a);

void liberer_ABR(ABR a);

