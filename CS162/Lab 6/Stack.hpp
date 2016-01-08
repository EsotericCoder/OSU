/****************************************************************
 ** Author: William Kim
 ** Date: 11/5/2015
 ** Description: Stack Header
 ***************************************************************/

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
class Stack
{
    //Struct node that holds an int data and a pointer
    struct ListNode
    {
        int data;
        ListNode *next;
    };
    
    public:
        Stack();
        ~Stack();
        void add(int newData);
        int remove();
    private:
        ListNode* top;
};

#endif /* Stack_hpp */
