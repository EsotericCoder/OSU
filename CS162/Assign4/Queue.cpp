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
    while(front != NULL)
    {
        fighter *garbage = front;
        front = front->next;
        delete garbage;
    }
}

//*****************************************************
// add adds a new element to the back of the queue.
//*****************************************************
void Queue::add(string n, std::string t, Creature *c)
{
    fighter *newFighter = new fighter();
    newFighter->name = n;
    newFighter->creatureType = t;
    newFighter->creature = c;
    newFighter->next = NULL;
    if(front == NULL)
    {
        rear=front=newFighter;
    }else{
        rear->next=newFighter;
        rear=newFighter;
    }
}

//*****************************************************
// add adds a new element to the back of the queue.
//*****************************************************
void Queue::addBack(fighter *f)
{
    if (front == NULL) {
        rear = front = f;
    }else{
        rear->next = f;
        rear=f;
    }
}

//*****************************************************
// Returns the front of the queue and deletes it.
//*****************************************************
void Queue::remove()
{
    if (front != NULL) {
        front = front->next;
    }
}