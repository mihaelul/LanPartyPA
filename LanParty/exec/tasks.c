#include "../headers/tasks.h"
#include <limits.h>
#include<math.h>


//liste

void delete(Team **head, float v){
     Team* copy=(*head);
     if(copy->total == v){
          (*head)=(*head)->Next;
          free(copy);
          return ;
     }
     while(copy->Next && copy->Next->total != v){
          copy=copy->Next;
     }
     if(copy->Next->total == v)
     {
          if(copy->Next->Next){
               Team* aux=copy->Next;
               copy->Next=copy->Next->Next;
               free(aux);
          }else {
               Team* aux=copy->Next;
               copy->Next= NULL;
               free(aux);
          }
     }

}


void delete_name(Team **head, char name[]){

     Team* copy=(*head);
     if(strcmp(copy->numele_echipei,name)==0){
          (*head)=(*head)->Next;
          free(copy);
          return ;
     }
     while(copy->Next && strcmp(copy->Next->numele_echipei,name)!=0){
          copy=copy->Next;
     }
     if(strcmp(copy->Next->numele_echipei,name)==0)
     {
          if(copy->Next->Next){
               Team* aux=copy->Next;
               copy->Next=copy->Next->Next;
               free(aux);
          }else {
               Team* aux=copy->Next;
               copy->Next= NULL;
               free(aux);
          }
     }
}


void print(Team *head)
{  
      while(head!=NULL)
    {
        printf("%s \n", head->numele_echipei);
        head=head->Next;

    }
}

void file_read(char *arg1, FILE **tasks, char *arg2, FILE **read, char *arg3, FILE **write)
{ 
     *tasks=fopen(arg1, "r"); 
        if(tasks==NULL)
        {
             printf("Eroare de deschidere fisier 1 \n");
        }
    *read=fopen(arg2, "r"); 
        if(tasks==NULL)
        {
             printf("Eroare de deschidere fisier 2 \n");
        }
    *write=fopen(arg3, "w"); 
        if(tasks==NULL)
        {
             printf("Eroare de deschidere fisier 3 \n");
        }        
}

void adaugare(Team** teamlist, FILE* file2, int* nr)
{ 
     fscanf(file2,"%d", nr); 
     int i;

     for(i=0;i<(*nr);i++)
     {
          Team* addTeam=(Team*)malloc(sizeof(Team));        
          if (fscanf(file2, "%d", &(addTeam->nr_jucatori)) != 1) {
            printf("Eroare la citirea numarului de jucatori pentru echipa %d\n", i + 1);
            free(addTeam);
        }
        fgetc(file2);
        fgets(addTeam->numele_echipei,100,file2); 
        addTeam->numele_echipei[strlen(addTeam->numele_echipei)-2]='\0';
        while(addTeam->numele_echipei[strlen(addTeam->numele_echipei)-1]==' ' ||
        addTeam->numele_echipei[strlen(addTeam->numele_echipei)-1]=='\n' ||
        addTeam->numele_echipei[strlen(addTeam->numele_echipei)-1]=='\r'){
          addTeam->numele_echipei[strlen(addTeam->numele_echipei)-1]='\0';
        }

        addTeam->jucator=(Player*)malloc(addTeam->nr_jucatori*sizeof(Player));  
        int j;
        for(j=0;j<addTeam->nr_jucatori;j++)
          {
               addTeam->jucator[j].firstName = (char*)malloc(100 * sizeof(char));
               addTeam->jucator[j].secondName = (char*)malloc(100 * sizeof(char));
               if (addTeam->jucator[j].firstName == NULL || addTeam->jucator[j].secondName == NULL) {
               printf("Eroare la alocarea memoriei pentru nume si prenume\n");
                }

               fscanf(file2, "%s", addTeam->jucator[j].firstName); 
               fscanf(file2, "%s", addTeam->jucator[j].secondName); 
               fscanf(file2, "%d", &(addTeam->jucator[j].points)); 
          }
          addTeam->Next = *teamlist; 
          (*teamlist) = addTeam;
     }
}
 //task 2

 float teamPoints(Team *teamlist, int nrOfPlayers)
{
    float suma = 0;
    for(int i=0; i<nrOfPlayers; i++) {
            suma = suma + teamlist->jucator[i].points;
    }
    return suma/nrOfPlayers;
}
int power(int nr)
{
    int i=1;
    while(i<nr) {
        i = i*2;
    }
    if(i == nr)
        return i;
    return i/2;
}

float minimPoints(Team *teamlist)
{
    float minim = teamlist->total;
    while(teamlist != NULL) {
        if(teamlist->total < minim)
            minim = teamlist->total;
        teamlist = teamlist->Next;
    }
    return minim;
}
void task2(Team **teamlist, int *nr)
{
    Team *current = *teamlist;
    float minim;
    int win;
    for(int i=0; i<*nr; i++) {
        current->total = teamPoints(current,current->nr_jucatori);  
        current = current->Next;  
    }
    win = power(*nr);
    if(win == *nr)
        return;
    while(*nr > win) {
        minim = minimPoints(*teamlist);
        delete(teamlist,minim);
        *nr = *nr - 1;
    }
}