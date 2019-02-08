#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Alonso Narro    -    A01650552
//Juan Soberanis  -   A01336831
//Alfredo Prado   -   A01652169

struct node {
    int age;
    char * name;
    struct node *next;
};
typedef struct node node_t;


void add(int age, char * name, node_t **theList) {
  node_t *newS = (node_t *) malloc(sizeof(node_t));
  newS->age = age;
  newS->name = name;
  newS->next = NULL;

  if(*theList == NULL){
    *theList = newS;
  }else{
    node_t *temp = *theList;
    while(temp->next!=NULL){
      temp = temp->next;
    }
    temp->next = newS;
  }
}

void addBeginning(int age, char * name, node_t **theList){
  node_t *newS = (node_t *) malloc(sizeof(node_t));
  newS->age = age;
  newS->name = name;
  newS->next = NULL;

  if(*theList == NULL){
    *theList = newS;
  }else{
    node_t *temp = *theList;
    newS->next = temp;
    *theList = newS;
  }
}

void removeFirst(node_t **theList){
  if(*theList == NULL){
    printf("Nothing to remove\n");
  }else{
    node_t *temp = *theList;
    *theList = temp->next;
    free(temp);
  }
}

void removeLast(node_t **theList){
  if(*theList == NULL){
    printf("Nothing to remove\n");
  }else{
    node_t *temp = *theList;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    node_t *erase = temp->next;
    temp->next=NULL;
    free(erase);
  }
}

void removeSpecific(int position, node_t **theList){
  if(*theList == NULL){
    printf("Nothing to remove\n");
  }else{
    int i = 0;
    node_t *temp = *theList;

    if(position == 0){
      *theList = temp->next;
      free(temp);
    }else{
      while(i != position-1){
          temp = temp->next;
          i++;
      }

      if(temp->next !=NULL){
        node_t *erase = temp->next;
        temp->next=erase->next;
        free(erase);
      }else{
        printf("Nothing to remove\n");
      }
    }
    
  }
}

void getElement(int position, node_t **theList){
  if(*theList == NULL){
    printf("Nothing to look for\n");
  }else{
    int i = 0;
    node_t *temp = *theList;

    while(i != position){
      temp = temp->next;
      i++;
    }
    
    printf("%d %s \n", temp->age, temp->name);
  }
}

void getOldest(node_t **theList){
  int *ageOldest = (int*) malloc(sizeof(int));
  char *nameOldest = (char *) malloc(10 * sizeof(char));

  *ageOldest = 0;
  
  if(*theList == NULL){
    printf("Nothing to look for\n");
  }else{
    node_t *temp = *theList;

    while(temp!=NULL){
      if(temp->age > *ageOldest){
        *ageOldest = temp->age;
        strcpy(nameOldest, temp->name);
      }
      temp = temp->next;
    }
    
    printf("%d %s \n", *ageOldest, nameOldest);
  }
  free(ageOldest);
  free(nameOldest);
}

void getYoungest(node_t **theList){
  int *ageYoungest = (int*) malloc(sizeof(int));
  char *nameYoungest = (char *) malloc(10 * sizeof(char));

  *ageYoungest = 1000;
  
  if(*theList == NULL){
    printf("Nothing to look for\n");
  }else{
    node_t *temp = *theList;

    while(temp!=NULL){
      if(temp->age < *ageYoungest){
        strcpy(nameYoungest, temp->name);
        *ageYoungest = temp->age;
        //*nameYoungest = temp->name;
      }
      temp = temp->next;
    }
    
    printf("%d %s \n", *ageYoungest, nameYoungest);
  }
}

void getAverageAges(node_t **theList){
   double *ageAverage = (double*) malloc(sizeof(double));
   *ageAverage = 0;
    int *age = (int*) malloc(sizeof(int));
   *age = 0;
    int *cont = (int*) malloc(sizeof(int));
   *cont = 0;

  if(*theList == NULL){
      printf("Nothing to look for\n");
  }else{
    node_t *temp = *theList;
    while(temp!=NULL){
      *age = temp->age;
      *ageAverage = *ageAverage + *age;
      *cont = *cont + 1;
      temp = temp->next;
    }
    *ageAverage = *ageAverage/ *cont;
    printf("%f \n", *ageAverage);
  }
  
}

void getStartLetter(char letter, node_t **theList){
  if(*theList == NULL){
    printf("Nothing to look for\n");
  }else{
    node_t *temp = *theList;

    while(temp!=NULL){
      if(temp->name[0] == letter){
        printf("%s \n", temp->name);
      }
      temp = temp->next;
    }
  }
}

void clear(node_t **theList){
  if(*theList == NULL){
    printf("Nothing to remove\n");
  }else{
    node_t *temp = *theList;
    node_t *erase = *theList;

    while(temp->next!=NULL){
      erase = temp->next;
      free(temp);
      temp = erase;
    }
    *theList = temp->next;
    free(temp);
  }
  printf("List cleared\n");
}

void print(node_t *pointerToList) {
  node_t *temp = pointerToList;
  printf("[");
  while(temp!=NULL){
    printf(" %d-%s \n", temp->age, temp->name);
    temp = temp->next;
  }
  printf("] \n");
  
}

void size(node_t *theList){
  int * counter = (int *)malloc(sizeof(int));
  *counter = 0;
  node_t *temp = theList;
  while(temp!=NULL){
    temp = temp->next;
    *counter = *counter + 1;
  }
  printf("The size of the list is: %d", *counter);
  free(temp);
  free(counter);
}

void loadList(node_t **theList) {

  FILE* stream = fopen("dataC.csv", "r");
  char line[1024];
  while(fgets(line, 1024, stream)){
    //printf("%s \n", line);
    char *name = (char *) malloc(10 * sizeof(char));
    strcpy(name, strtok(line, ","));
    int age = 0;
    age = atoi(strtok(NULL,""));
    //printf("%s %d \n", name, age);
    add(age, name, theList);
  } 

  free(stream); 


}