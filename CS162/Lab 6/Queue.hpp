/****************************************************************
 ** Author: William Kim
 ** Date: 11/5/2015
 ** Description: Queue Header
 ***************************************************************/

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

class Queue
{
    //Struct node that holds an int data and a pointer
    struct ListNode
    {
        int data;
        ListNode *next;
    };
    
public:
    Queue();
    ~Queue();
    void add(int newData);
    int remove();
private:
    ListNode *front,*rear;
};

#endif /* Queue_hpp */
