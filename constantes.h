#define TAILLE_MAX 100000
#define MOT_LE_PLUS_LONG 195

struct mot  {
    char *mot;
    int taille;
    int position;
    int nbOcurrence;
};

typedef struct mot *MOT;

void transpo(char lettre);