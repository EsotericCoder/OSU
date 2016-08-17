/* 
 * Solution description: This program randomly creates 10 student ids and scores and computes the min, max, and avg
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *Students = (struct student*) malloc(sizeof(struct student)*10);
     /*return the pointer*/
    return Students;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++){
        (students + i)->id = rand() % 11;
        (students + i)->score = rand() % 101;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for(int i = 0; i < 10; i++){
        printf("%d %d\n", (students + i)->id, (students + i)->score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = 0;
    int max = 0;
    int total = 0;
    float average = 0.00;
    
    for(int i = 0; i < 10; i++){
        if(i == 0){
            min = (students + i)->score;
            max = (students + i)->score;
        }else{
            if(min > (students + i)->score){
                min = (students + i)->score;
            }
            if(max < (students + i)->score){
                max = (students + i)->score;
            }
        }
        total += (students + i)->score;
    }
    
    average = total / 10.00;
    
    printf("Maximum Score: %d\n", max);
    printf("Minimum Score: %d\n", min);
    printf("Average Score: %.2f\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if(stud != NULL){
        free(stud);
    }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);
    
    return 0;
}
