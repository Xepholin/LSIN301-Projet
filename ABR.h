struct mot  {
    char *mot;
    int taille;
    int nbOcurrence;
    int position_dico;
    bool motSuivant;
};

typedef struct mot *MOT;

struct noeud {
    struct mot *mot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE arbre);

ARBRE creer_arbre(MOT mot, DICO dico, ARBRE filsG, ARBRE filsD);

ARBRE ajoute_element(DICO dico, MOT mot, ARBRE arbre);

MOT detecte_mot(DICO dico, MOT mot, ARBRE arbre);

void affiche_noeud(ARBRE arbre);

void affiche_arbre(ARBRE arbre);

void liberer_arbre(ARBRE arbre);

void liberer_mot(MOT mot);