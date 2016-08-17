/* William Kim
   Kimw@OregonState.Edu
   CS261
   Assign 5
   2/27/16
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  struct Task* newTask;
  struct Task* firstTask;
  char desc[TASK_DESC_SIZE], filename[50], *nlptr;
  FILE* filePtr;
  int priority;
  char cmd = ' ';
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      cmd = getchar();
      /* clear the trailing newline character */
      while (getchar() != '\n');

      /* Fixme:  Your logic goes here! */
      switch (cmd)
      {
        case 'l':
          printf("Enter filename: ");
          if (fgets(filename, sizeof(filename), stdin) != NULL){
            nlptr = strchr(filename, '\n');
            if (nlptr) 
              *nlptr = '\0';
          }
          filePtr = fopen(filename, "r"); 
          if (filePtr == NULL) {
            fprintf(stderr, "Cannot open %s\n\n", filename);
            break;
          }
          loadList(mainList, filePtr);
          printf("The list has been loaded from file successfully.\n\n");
          fclose(filePtr);     
          break;

        case 's':
          if (sizeDynArr(mainList) > 0){ 
            printf("Please enter the filename: ");
            if (fgets(filename, sizeof(filename), stdin) != NULL){
              nlptr = strchr(filename, '\n');
              if (nlptr) 
                *nlptr = '\0';
            }
            filePtr = fopen(filename, "w"); 
            if (filePtr == NULL) {
              fprintf(stderr, "Cannot open %s\n\n", filename);
              break;
            }
            saveList(mainList, filePtr);
            fclose(filePtr);
            printf("The list has been saved into the file successfully.\n\n");      
          }else{
            printf("Your to-do list is empty!\n\n");
          }
          break;

        case 'a':
          printf("Please enter the task description: ");
          if (fgets(desc, sizeof(desc), stdin) != NULL){
            nlptr = strchr(desc, '\n');
            if (nlptr){ 
              *nlptr = '\0';
            }
          }
      
          do {
            printf("Please enter the task priority (0-999): ");
            scanf("%d", &priority);
          } while(!(priority >= 0 && priority <= 999));
      
          while (getchar() != '\n');
          newTask = createTask(priority, desc);
          addHeap(mainList, newTask, compare);
          printf("The task '%s' has been added to your to-do list.\n\n", desc);
          break;
    
        case 'g':
          if (sizeDynArr(mainList) > 0){
            firstTask = (struct Task*)getMinHeap(mainList);
            printf("Your first task is: %s\n\n", firstTask->description);
          }else{
            printf("Your to-do list is empty!\n\n");
          }    
          break;

        case 'r':
          if (sizeDynArr(mainList) > 0){
            firstTask = (struct Task*)getMinHeap(mainList);
            removeMinHeap(mainList, compare);
            printf("Your first task '%s' has been removed from the list.\n\n", firstTask->description);
          }else{
            printf("Your to-do list is empty!\n\n");
          }
          break;

        case 'p':
          if(sizeDynArr(mainList) > 0){
            printList(mainList);        
          }else{
            printf("Your to-do list is empty!\n\n");
          }
          break;
    
        case 'e':
          printf("Bye!\n\n");
          break;
      }
      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
  while(cmd != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
