#include "../lanparty3.h"

void file_read(char* arg1, FILE** tasks, char* arg2, FILE** read, char* arg3,
               FILE** write);
// liste
void delete (Team** head, float v);
void print(Team* head);
// tasks
void adaugare(Team** teamlist, FILE* file2, int* nr);
/* --- */
float teamPoints(Team* teamlist, int nrOfPlayers);
int power(int nr);
float minimPoints(Team* teamlist);
void task2(Team** , int*);