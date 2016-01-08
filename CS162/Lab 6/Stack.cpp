/*****************************************************
 ** Author: William Kim
 ** Date: 11/5/2015
 ** Description: Stack Class
 *****************************************************/

#include "Stack.hpp"
#include <iostream>

using namespace std;

//*****************************************************
// Initializes Stack to Null.
//*****************************************************
Stack::Stack()
{
    top = NULL;
}
//******************************************************
// Destructor deallocates the memory used by the list.
//******************************************************
Stack::~Stack()
{
    
    ListNode *nodePtr = top;
    while(nodePtr != NULL)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

//*****************************************************
// add adds a new element to the top of the stack.
//*****************************************************
void Stack::add(int newData)
{
    ListNode *nodePtr;
    nodePtr = new ListNode;
    nodePtr->data = newData;
    nodePtr->next = top;
    top = nodePtr;
}

//*****************************************************
// Returns the top element of the stack and deletes it.
//*****************************************************
int Stack::remove()
{
    if(top == NULL)
    {
        return NULL;
    }else{
        int removedData;
        ListNode *nodePtr;
        nodePtr = top;
        removedData = nodePtr->data;
        top = top->next;
        delete nodePtr;
        return removedData;
    }
}