struct noeud {
    MOT mot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE arbre);

ARBRE creer_arbre(MOT mot, ARBRE filsG, ARBRE filsD);

ARBRE ajoute_element(DICO dico, MOT mot, int position, ARBRE arbre);

void detecte_mot(DICO dico, MOT mot, int position);