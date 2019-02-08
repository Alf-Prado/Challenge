#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedList.h"


int main()
{
  node_t * list = NULL;
  loadList(&list);
  //print(list);
  int *option = (int*)malloc(sizeof(int));

  printf("Select an option: \n");
  printf("1.- Print the list. \n");
  printf("2.- Print the oldest person. \n");
  printf("3.- Print the youngest person.\n");
  printf("4.- Print the average of ages.\n");
  printf("5.- Print all names that start with a given letter.");
  scanf("%d", option);
  
  switch(*option){
    case 1:
      print(list);
      break;

    case 2:
      getOldest(&list);
      break;

    case 3:
      getYoungest(&list);
      break;

    case 4:
      getAverageAges(&list);
      break;

    case 5:
      printf("Choose a capital letter:");
  
      char letter;
      scanf("%c",&letter);
      scanf("%c", &letter);
      getStartLetter(letter, &list);
      break;
  }
}