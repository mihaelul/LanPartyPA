#include "../headers/tasks.h"
#include <limits.h>
#include<math.h>

//stive
void push(Team**top, int nr_juc, char echipa[], float tot) {
	Team* newTeam=(Team*)malloc(sizeof(Team));
	newTeam->nr_jucatori=nr_juc;
    strcpy(newTeam->numele_echipei,echipa);
	newTeam->total=tot;
    newTeam->Next=*top;
	*top=newTeam;
}

int isEmpty(Team*top){
	return (top==NULL)?1:0;
}



void deleteStack(Team**top){
	Team *temp;
	while ((*top)!=NULL){ 
		temp=*top;
		*top=(*top)->Next;
        free(temp->jucator);  
		free(temp);
	}
}	

void pop(Team** top) {
    if (isEmpty(*top)) return;  
    Team *temp = (*top);
    *top = (*top)->Next; 
}


//cozi

Queue* createQueue(){
	Queue *q;
	q=(Queue *)malloc(sizeof(Queue));
	if (q==NULL) return NULL;	
	q->front=q->rear=NULL;
	return q;	
}

 void enQueue(Queue*q,  int nr_juc, char echipa[], float tot){
	Team* newNode=(Team*)malloc(sizeof(Team));
	newNode->nr_jucatori=nr_juc;
	strcpy(newNode->numele_echipei,echipa);
	newNode->total=tot;
	newNode->Next=NULL;
	if (q->rear==NULL) q->rear=newNode; 
	else{
		(q->rear)->Next=newNode;
		(q->rear)=newNode;
	}
	if (q->front==NULL) q->front=q->rear; 
}
 
void deQueue(Queue*q) {  
	
	if(q->front == NULL) return ;
	
	q->front=q->front->Next;
} 

int isEmpty2(Queue*q){
	return (q->front==NULL)?1:0;
}

void deleteQueue(Queue*q){
	Team* aux;
	while (!isEmpty2(q)){
		aux=q->front;
		q->front=q->front->Next;
		free(aux);
	}
	free(q);
}


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

//task 3

void copiere(char nume[], float punctaj, Team* v, int *index)
{
          strcpy(v[*index].numele_echipei,nume);
          v[*index].total=punctaj;
          (*index)++;
          

}


void initializeQueueTask3(Queue* queue, Team* teamlist) {
    Team* current = teamlist;
    while (current != NULL) {
        enQueue(queue, current->nr_jucatori, current->numele_echipei, current->total);
        current = current->Next;
    }
}

void processMatchTask3(Queue* queue, Team** stack_win, Team** stack_lose, FILE* file) {
    Team *Team1, *Team2;
    while (!isEmpty2(queue)) {
        Team1 = queue->front;
        deQueue(queue);
        Team2 = queue->front;
        deQueue(queue);

        if (Team1->total > Team2->total) {
            Team1->total += 1;
            push(stack_win, Team1->nr_jucatori, Team1->numele_echipei, Team1->total);
            push(stack_lose, Team2->nr_jucatori, Team2->numele_echipei, Team2->total);
            fprintf(file, "%-33s-  %31s\r\n", Team1->numele_echipei, Team2->numele_echipei);
        } else {
            Team2->total += 1;
            push(stack_win, Team2->nr_jucatori, Team2->numele_echipei, Team2->total);
            push(stack_lose, Team1->nr_jucatori, Team1->numele_echipei, Team1->total);
            fprintf(file, "%-33s-  %31s\r\n", Team1->numele_echipei, Team2->numele_echipei);
        }
    }
}

void addAtBeginning(EightTeam** head, char* name, float points)
{ 
     EightTeam* newTeam=(EightTeam*)malloc(sizeof(EightTeam));
     newTeam->puncte=points;
     newTeam->nume=(char*)malloc(100*sizeof(char));
     strcpy(newTeam->nume,name);

     newTeam->Next=*head;
     *head=newTeam;

}

void updateTeamsQueueTask3(Queue* queue, Team** stack_win, Team** stack_lose, Team** teamlist, FILE* file, int* nrr, int eight, EightTeam** lasteight) {
    while (*stack_lose != NULL) {
        delete_name(teamlist, (*stack_lose)->numele_echipei);
        pop(stack_lose);
    }

    (*nrr) /= 2;

    while (*stack_win != NULL) {
        enQueue(queue, (*stack_win)->nr_jucatori, (*stack_win)->numele_echipei, (*stack_win)->total);
        if (*nrr == eight) {
            addAtBeginning(lasteight, (*stack_win)->numele_echipei, (*stack_win)->total);
        }
        fprintf(file, "%-34s-  %.2f\r\n", (*stack_win)->numele_echipei, (*stack_win)->total);
        pop(stack_win);
    }
}

void freeQueue(Queue* q) {
    while (!isEmpty2(q)) {
        deQueue(q);
    }
    free(q);
}
void freeTeams(Team* teamlist) {
    Team* current = teamlist;
    Team* next;
    while (current != NULL) {
        next = current->Next;
        free(current);
        current = next;
    }
}
void freeStack(Team* stack) {
    while (stack != NULL) {
        pop(&stack);
    }
}
void freeMemoryTask3(Queue* queue, Team* stack_win, Team* stack_lose) {
    freeQueue(queue);
    freeStack(stack_win);
    freeStack(stack_lose);
}

void task3(Team** teamlist, int* nrr, FILE* file, EightTeam** lasteight, int eight) {
    Team *stack_win = NULL, *stack_lose = NULL;
    Queue* queue = createQueue();

    initializeQueueTask3(queue, *teamlist);
    fprintf(file, "\r\n");

    int nr_meci = 1;
    while (*nrr != 1) {
        fprintf(file, "\r\n--- ROUND NO:%d\r\n", nr_meci);
        processMatchTask3(queue, &stack_win, &stack_lose, file);
        fprintf(file, "\r\nWINNERS OF ROUND NO:%d\r\n", nr_meci);
        updateTeamsQueueTask3(queue, &stack_win, &stack_lose, teamlist, file, nrr, eight, lasteight);
        nr_meci++;
    }
    freeMemoryTask3(queue, stack_win, stack_lose);
}

//task 4