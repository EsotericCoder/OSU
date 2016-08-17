/* 
 * Solution description: This program creates and fills an array with random integers,prints the array
 * then sorts it and prints the sorted array.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int currentID, currentScore;
    for(int j = 0; j < n; j++){
        currentID = (students + j)->score;
        currentScore = (students + j)->score;

        for(int k = (j + 1); k < n; k++){
            if((students + k)->score < currentID){
                (students + j)->id = (students + k)->id;
                (students + j)->score = (students + k)->score;
                (students + k)->id = currentID;
                (students + k)->score = currentScore;
                currentID = (students + j)->id;
                currentScore = (students + j)->score;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    struct student *students = (struct student*) malloc(sizeof(struct student)*n);
    
    /*Generate random IDs and scores for the n students, using rand().*/
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        (students + i)->id = rand() % 11;
        (students + i)->score = rand() % 101;
    }
    
    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++){
        printf("%d %d\n", (students + i)->id, (students + i)->score);
    }
    printf("\n");
    
    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++){
        printf("%d %d\n", (students + i)->id, (students + i)->score);
    }
    printf("\n");
    
    return 0;
}
