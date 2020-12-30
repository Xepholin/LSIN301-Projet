struct noeud {
    MOT mot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE arbre);

ARBRE creer_arbre(DICO dico, MOT mot, int position, ARBRE filsG, ARBRE filsD);

ARBRE ajoute_element(DICO dico, MOT mot, int position, ARBRE arbre);

MOT detecte_mot(DICO dico, MOT mot, int position);

void liberer_arbre(ARBRE arbre);