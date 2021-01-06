struct noeud    {
    char * motArbre;
    int nbOcurrenceMot;
    struct noeud *droite;
    struct noeud *gauche;
};

typedef struct noeud *ARBRE;

bool vide (ARBRE A);

ARBRE creer_arbre(char *mot, ARBRE droite, ARBRE gauche);

char *recup_mot(char *argv, int *position, char *mot);

ARBRE ajoute_element(char *argv, int n, int *position, char *mot,  bool motSuivant, ARBRE A);

void affiche_arbre(ARBRE A);

void liberer_arbre(ARBRE A);

void liberer_mot(char *mot);