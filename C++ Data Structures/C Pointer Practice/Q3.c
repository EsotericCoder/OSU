/* 
 * Solution description: This program creates and fills an array with random integers,prints the array
 * then sorts it and prints the sorted array.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int selected;
    for(int i = 0; i < n; i++){
        selected = *(number + i);
        
        for(int k = (i + 1); k < n; k++){
            if(*(number + k) < selected){
                *(number + i) = *(number + k);
                *(number + k) = selected;
                selected = *(number + i);
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = (int *)malloc(sizeof(int)*n);
    
    /*Fill this array with random numbers, using rand().*/
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        *(array + i) = rand() % 100;
    }
    /*Print the contents of the array.*/
    for(int i = 0; i < n; i++){
        printf("%d ", *(array + i));
    }
    printf("\n\n");
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    
    /*Print the contents of the array.*/    
    for(int i = 0; i < n; i++){
        printf("%d ", *(array + i));
    }
    printf("\n\n");
    
    return 0;
}
