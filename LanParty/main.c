#include <math.h>

#include "./headers/tasks.h"

#define N 5
#define lasteight 8
int main(int argc, char *argv[]) {
    // citire fisiere
    // citirea cerintelor

    int cerinte[N];
    FILE *file = fopen(argv[1], "r");

    for (int i = 0; i < N; i++) fscanf(file, "%d", &cerinte[i]);

    if (file == NULL) {
        printf("Nu s-a putut deschide fisierul \n");
    }
    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        printf("Nu s-a putut deschide fisierul \n");
    }
    FILE *file3 = fopen(argv[3], "w+");

    if (file3 == NULL) {
        printf("Nu s-a putut deschide fisierul \n");
    }

    int nr_echipe;
    Team *TeamList = NULL;
    adaugare(&TeamList, file2, &nr_echipe);

    Team *currentTeam = TeamList;

    if (cerinte[0] && cerinte[1] == 0) {
        while (currentTeam->Next != NULL) {
            fprintf(file3, "%s\r\n", currentTeam->numele_echipei);
            currentTeam = currentTeam->Next;
        }
        fprintf(file3, "%s", currentTeam->numele_echipei);
    }

    if (cerinte[1]) {
        task2(&TeamList, &nr_echipe);
        currentTeam = TeamList;
        while (currentTeam->Next != NULL) {
            fprintf(file3, "%s\r\n", currentTeam->numele_echipei);
            currentTeam = currentTeam->Next;
        }
        fprintf(file3, "%s", currentTeam->numele_echipei);
    }
    
    
    fclose(file);
    fclose(file2);
    fclose(file3);

    return 0;

}