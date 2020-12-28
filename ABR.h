struct noeud {
    MOT mot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ABR;

bool vide(ABR a);

ABR creer_arbre(DICO texte, MOT mot, ABR filsG, ABR filsD);

void affiche_noeud(ABR a);

void affiche_arbre(ABR a);

ABR ajoute_element(ABR a, MOT mot, DICO texte);

void liberer_ABR(ABR a);