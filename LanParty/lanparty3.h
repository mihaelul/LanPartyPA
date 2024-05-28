#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Play {
    char *firstName;
    char *secondName;
    int points;
};

typedef struct Play Player;

struct myTEAM {
    int nr_jucatori;
    char numele_echipei[100];
    Player *jucator;
    float total;
    struct myTEAM *Next;
};
typedef struct myTEAM Team;

