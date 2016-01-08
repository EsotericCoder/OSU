/*****************************************************
 ** Author: William Kim
 ** Date: 11/5/2015
 ** Description: main Class
 *****************************************************/

#include <stdio.h>
#include "Queue.hpp"
#include "Stack.hpp"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    //Initialize
    Queue *q = new Queue();
    Stack *s = new Stack();
    
    //Add 1,2,3,4,5 to the Queue and remove and then output them.
    cout << "Queue: " << endl;
    q->add(1);
    q->add(2);
    q->add(3);
    q->add(4);
    q->add(5);
    
    cout << q->remove() << endl;
    cout << q->remove() << endl;
    cout << q->remove() << endl;
    cout << q->remove() << endl;
    cout << q->remove() << endl;
    
    //Add 1,2,3,4,5 to the Stack and remove and then output them.
    cout << "Stack: " << endl;
    s->add(1);
    s->add(2);
    s->add(3);
    s->add(4);
    s->add(5);
    
    cout << s->remove() << endl;
    cout << s->remove() << endl;
    cout << s->remove() << endl;
    cout << s->remove() << endl;
    cout << s->remove() << endl;
    
    return 0;
    
}