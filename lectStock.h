struct dico {
    int taille;
    char *T;
    int *L;
};

typedef struct dico *DICO;

DICO creer_dico(char **argv, int n);

void affiche_dico(DICO dico);

void liberer_fichier(DICO dico);