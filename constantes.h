#define TAILLE_MAX 100000
#define MOT_LE_PLUS_LONG 50

struct mot  {
    char *mot;
    int taille;
    int position;
    int ligne;
};

typedef struct mot *MOT;

void transpo(char lettre);