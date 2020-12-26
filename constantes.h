#define TAILLE_MAX 100000

struct mot
{
    char *mot;
    int taille;
    int position;
    int ligne;
};

typedef struct mot *MOT;

void transpo(char *lettre);