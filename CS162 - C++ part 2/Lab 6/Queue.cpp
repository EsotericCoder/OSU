/****************************************************************
 ** Author: William Kim
 ** Date: 11/5/2015
 ** Description: Queue class
 ***************************************************************/

#include "Queue.hpp"

#include <iostream>

using namespace std;

//*****************************************************
// Initializes Queue to Null.
//*****************************************************
Queue::Queue()
{
    front = NULL;
    rear  = NULL;
}

//******************************************************
// Destructor deallocates the memory used by the Queue.
//******************************************************
Queue::~Queue()
{
    ListNode *nodePtr = front;
    while(nodePtr != NULL)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

//*****************************************************
// add adds a new element to the back of the queue.
//*****************************************************
void Queue::add(int newData)
{
    ListNode *nodePtr;
    nodePtr=new ListNode;
    nodePtr->data=newData;
    nodePtr->next=NULL;
    if(front==NULL)
    {
        rear=front=nodePtr;
    }else{
        rear->next=nodePtr;
        rear=rear->next;
    }
}

//*****************************************************
// Returns the front of the queue and deletes it.
//*****************************************************
int Queue::remove()
{
    if(front==NULL)
    {
        return NULL;
    }else{
        ListNode *nodePtr;
        int removedData;
        removedData=front->data;
        nodePtr=front;
        front=front->next;
        delete nodePtr;
        return removedData;
    }
}