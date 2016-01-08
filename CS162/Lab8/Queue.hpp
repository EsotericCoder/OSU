/****************************************************************
 ** Author: William Kim
 ** Date: 11/18/2015
 ** Description: Queue Header
 ***************************************************************/

#ifndef Queue_hpp
#define Queue_hpp
#include <string>
#include <stdio.h>

class Queue
{
    //Struct node that holds an int data and a pointer
    struct QueueNode
    {
        int data;
        QueueNode *next;
        QueueNode *prev;
    };
    
public:
    Queue();
    ~Queue();
    void addBack(int newData);
    int getFront();
    void removeFront();
private:
    QueueNode *front,*back;
};

#endif /* Queue_hpp */
