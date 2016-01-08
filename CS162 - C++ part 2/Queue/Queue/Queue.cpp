/****************************************************************
 ** Author: William Kim
 ** Date: 11/18/2015
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
    back  = NULL;
}

//******************************************************
// Destructor deallocates the memory used by the Queue.
//******************************************************
Queue::~Queue()
{
    QueueNode *nodePtr = front;
    while(nodePtr != NULL)
    {
        QueueNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

//*****************************************************
// addBack adds a new element to the back of the queue.
//*****************************************************
void Queue::addBack(int newData)
{
    //Sets up queue for the first time
    if(front == NULL){
        QueueNode *newNode = new QueueNode;
        newNode->data = newData;
        newNode->next = front;
        newNode->prev = back;
        back = front = newNode;
        back->prev = back->next = newNode;
        front->prev = front->next = newNode;
    //Adds data to front of queue if empty
    }else if (front->data == -1) {
        front->data = newData;
    //Adds data to empty node
    }else if(back->data == -1){
        QueueNode *nextPtr = new QueueNode();
        nextPtr = front;
        bool notInserted = true;                    //Is true when new data is added
        while(nextPtr != back && notInserted){
            nextPtr = nextPtr->next;
            //Finds empty nodes and inserts new data
            if (nextPtr->data == -1) {
                nextPtr->data = newData;
                notInserted = false;
            }
        }
    //Creates a new node and adds it to the back
    }else{
        QueueNode *newNode = new QueueNode;
        newNode->data = newData;
        newNode->next = front;
        newNode->prev = back;
        back->next=newNode;
        back = newNode;
    }
}

//*****************************************************
// Returns the front of the queue
//*****************************************************
int Queue::getFront()
{
    bool notEmpty = true;
    if(front == NULL){
        return -1;  //Sentinel
    }else{
        if(notEmpty) {
            if (front->data == -1) {
                front = front->next;
                back = front->prev;
                if(front->data == -1 && back->data == -1){
                    notEmpty = false;
                    return -1;  //Sentinel
                }
            }
        }else{
            return -1;  //Sentinel
        }
        int retrievedData = front->data;         //Gets the front data
        return retrievedData;                    //Return data
    }
}

//*****************************************************
// Returns the front of the queue and deletes it.
//*****************************************************
void Queue::removeFront()
{
    if(front != NULL)
    {
        front->data = -1;
        front = front->next;
        back = front->prev;
    }
}