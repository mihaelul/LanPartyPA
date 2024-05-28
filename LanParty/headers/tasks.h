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
void task2(Team**, int*);

/* --- */
void copiere(char nume[], float punctaj, Team* v, int* index);
void addAtBeginning(EightTeam** head, char* name, float points);
void initializeQueueTask3(Queue* queue, Team* teamlist);
void processMatchTask3(Queue* queue, Team** stack_win, Team** stack_lose,
                       FILE* file);
void updateTeamsQueueTask3(Queue* queue, Team** stack_win, Team** stack_lose,
                           Team** teamlist, FILE* file, int* nrr, int eight,
                           EightTeam** lasteight);
void freeQueue(Queue* q);
void freeTeams(Team* teamlist);
void freeMemoryTask3(Queue* queue, Team* stack_win, Team* stack_lose);
void task3(Team** teamlist, int* nrr, FILE* file, EightTeam** lasteight,
           int eight);


/* --- */

BST* newTeam(EightTeam data);
BST* createBST();
BST* insert(BST* team, EightTeam actual);
void task4(FILE* outt, EightTeam* lasteightteams, BST* bst, EightTeam**);
void afisareBST(FILE* out, BST* root, EightTeam**);
void addAtBeginning(EightTeam** head, char* name, float points);

/* --- */

int height(AVL* node);
int maxx(int a, int b);
AVL* newNode(EightTeam* actual);
AVL* rightRotate(AVL* y);
AVL* leftRotate(AVL* x);
int balance(AVL* N);
AVL* insertAVL(AVL* team, EightTeam* actual);
void afisarelevel2(AVL* root);
void task5(EightTeam* eight, FILE*);

// stiva
int isEmpty(Team* top);
void pop(Team** top);
void deleteStack(Team** top);
void push(Team** top, int nr_juc, char echipa[], float tot);
void freeStack(Team* top);

// cozi
Queue* createQueue();
void enQueue(Queue* q, int nr_juc, char echipa[], float tot);
void deQueue(Queue* q);
int isEmpty2(Queue* q);
void deleteQueue(Queue* q);