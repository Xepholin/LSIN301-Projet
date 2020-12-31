#define TAILLE_MAX 100000
#define MOT_LE_PLUS_LONG 195

struct mot  {
    char *mot;
    int taille;
    int nbOcurrence;
    int position_dico;
    bool motFin;
    bool motSuivant;
};

typedef struct mot *MOT;