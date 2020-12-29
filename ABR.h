struct noeud {
    MOT mot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE arbre);

void recupMot(DICO texte, MOT motActu, int position);

ARBRE creer_arbre(DICO dico, MOT mot, ARBRE filsG, ARBRE filsD, int position);

ARBRE ajoute_element(DICO dico, MOT mot, ARBRE arbre, int position);

void affiche_arbre(ARBRE arbre);

void liberer_arbre(ARBRE arbre);