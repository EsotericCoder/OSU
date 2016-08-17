/*
 * Solution description: This program outputs the address of x and then calls fooA function
 *                       which then prints the value pointed to by iptr, address pointed to
 *                       by iptr, and the adress of iptr itself. Lastly it prints the value
 *                       of x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("The Value pointed to by iptr: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr: %p\n", iptr);
     /*Print the address of iptr itself*/
    printf("The address of iptr itself: %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 0;
    /*print the address of x*/
    printf("The address of x: %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of X: %d\n", x);
    
    return 0;
}
