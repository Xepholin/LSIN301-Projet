struct noeud    {
    char *motArbre;
    int nbOcurrenceMot;
    int *ligne;
    int hauteurD;
    int hauteurG;
    struct noeud *droite;
    struct noeud *gauche;
    struct noeud *parent;
};

typedef struct noeud *ARBRE;

bool vide(ARBRE A);

int max(int a, int b);

int min(int a, int b);

ARBRE creer_arbre(char *mot, ARBRE droite, ARBRE gauche);

char *recup_mot(char *argv, int *position, char *mot);

int compare (ARBRE A, char *mot);

ARBRE ajoute_element(char *argv, int *position, char *mot, bool motSuivant, ARBRE A);

ARBRE creation_parent(ARBRE A);

int hauteur_sous_arbre(ARBRE A);

int hauteur_arbre(ARBRE A);

int desequilibre(ARBRE A);

ARBRE rotation_droite(ARBRE A);

ARBRE rotation_gauche(ARBRE A);

ARBRE equilibre(ARBRE A);

ARBRE requilibreD(ARBRE A);

ARBRE requilibreG(ARBRE A);

ARBRE requilibre(ARBRE A);

void affiche_arbre(ARBRE A);

void liberer_arbre(ARBRE A);

void liberer_mot(char *mot);