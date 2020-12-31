struct noeud {
    struct mot *mot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE arbre);

ARBRE creer_arbre(DICO dico, MOT mot, ARBRE filsG, ARBRE filsD);

ARBRE ajoute_element(DICO dico, MOT mot, ARBRE arbre);

MOT detecte_mot(DICO dico, MOT mot);

void affiche_noeud(ARBRE arbre);

void affiche_arbre(ARBRE arbre);

void liberer_arbre(ARBRE arbre);

void liberer_mot(MOT mot);