struct abr {
    char *mot;
    int *ligne;
    int taille;
    struct abr *filsG;
    struct abr *filsD;
};

typedef struct abr *ABR;

struct motActuel
{
    char *mot;
    int pos;
};

typedef struct motActuel *motAct;

bool vide(ABR a);

void ajoute_element(ABR a, char x);

ABR creer_ARB(char *tab, int n);

void double_espace(ABR a);

motAct estMot(ABR a, int pos);

void est_ABR(ABR a);

void affiche_ABR(ABR a);

void liberer_ABR(ABR a);

