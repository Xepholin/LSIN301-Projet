/*struct mot  {
    char *mot;
    int taille;
    int nbOcurrence;
    int position_dico;
    bool motFin;
    bool motSuivant;
};

typedef struct mot *MOT;*/

struct noeud {
    char *mot;
    int nbOcurrenceMot;
    struct noeud *filsG;
    struct noeud *filsD;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE arbre);

ARBRE creer_arbre(char *mot, ARBRE filsG, ARBRE filsD);

ARBRE ajoute_element(DICO dico, char *mot, bool motSuivant, int position, ARBRE arbre);

void detecte_mot(DICO dico, char *mot, int position, int tailleMot);

void affiche_noeud(ARBRE arbre);

void affiche_arbre(ARBRE arbre);

void liberer_arbre(ARBRE arbre);

void liberer_mot(char *mot);