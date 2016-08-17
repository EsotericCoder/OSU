/* 
 * Solution description: The program defines the foo function and the main initalizes
 * the three variables and passes them to the foo function.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("Value of x: %d\n", x);
    printf("Value of y: %d\n", y);
    printf("Value of z: %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int fooResult = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("Value returned by foo: %d\n", fooResult);
    
    /*Print the values of x, y and z again*/
    printf("Value of x: %d\n", x);
    printf("Value of y: %d\n", y);
    printf("Value of z: %d\n", z);
 
    /*Is the return value different than the value of z?  Why?
     *Yes the return value is different than z because z is not passed by address.
     */
    return 0;
}
    
    
