
//  Description: This program converts inches to cm and vice versa

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int menuSelection = 0;
    
    while (menuSelection != 3) {
        float inches = 0;
        float cm = 0;
        printf("Enter 1 to convert inches to cm\n");
        printf("Enter 2 to convert cm to inches\n");
        printf("Enter 3 to quit\n");
        scanf("%i", & menuSelection);
        if (menuSelection == 1) {
            printf("\nConverting inches to cm\n");
            printf("Enter length in inches: ");
            scanf("%f", & inches);
            cm = inches * 2.54;
            printf("cm = %.2f\n\n", cm);
            
        }else if(menuSelection == 2){
            printf("\nConverting cm to inches\n");
            printf("Enter length in cm: ");
            scanf("%f", & cm);
            inches = cm / 2.54;
            printf("inches = %.2f\n\n", inches);
        }
    }
    return 0;
}
