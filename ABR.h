struct abr {
    char *mot;
    int *ligne;
    int taille;
    struct abr *filsG;
    struct abr *filsD;
};

typedef struct abr *ABR;

bool vide(ABR a);

MOT estMot(DICO texte, int position);

void ajoute_element(ABR a, MOT mot, DICO dico);

ABR creer_ARB(char *tab, int n);

void double_espace(ABR a);

void est_ABR(ABR a, MOT motActu);

void affiche_ABR(ABR a);

void liberer_mot(MOT mot);

void liberer_ABR(ABR a);

