/* 
 * Solution description: This program asks user for a string and converts it to uppercase
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    for(int i = 0; i < strlen(word); i++){
        if((i % 2) == 0){
            if(!isupper(*(word + i))){
                *(word + i) = toUpperCase(*(word + i));
            }
        }else if((i % 2) == 1){
            if(!islower(*(word + i))){
                *(word + i) = toLowerCase(*(word + i));
            }
        }
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char userInput[40];
    printf("Enter word: \n");
    scanf("%s", userInput);
    
    /*Call sticky*/
    sticky(userInput);
    
    /*Print the new word*/
    printf("\n\n%s\n\n", userInput);
    
    return 0;
}
