/****************************************************************
 ** Author: William Kim
 ** Date: 11/25/2015
 ** Description: main class
 ***************************************************************/

#include <iostream>
#include <queue>
#include <ctime>
#include <stdlib.h>

using namespace std;

//Random number of extra people function
int randomNum(int servers){
    int randomN = (rand() % servers) + 1;
    return randomN;
};

//Single Queue
int singleQueue(int servers, int people, int random){
    
    int click = 0;                          //Number of clicks counter
    int userInput = 0;
    int totalPeople = 0;                    //Total number of people
    totalPeople = people;
  
    queue<int> singleQueue;
    
    cout << "Single Queue\n" << endl;
    
    //Load initial arrival of people
    for (int i = 1; i <= people; i++) {
        cout << "Person: " << i << " in queue." << endl;
        singleQueue.push(i);
    }
    
    while (!singleQueue.empty()) {
        
        cout << "\nEnter 1 to click" << endl;
        cin >> userInput;
        if (userInput == 1) {
            for (int i = 0; i < servers; i++) {
                if (!singleQueue.empty()) {
                    cout << "Person: " << singleQueue.front() << " out of queue" << endl;
                    singleQueue.pop();
                }
            }
            click++;
        }
        //Gradually increases and decreases people arriving to queue
        if (click == 1) {
            cout << "\nMore people added to queue" << endl;
            for (int i = totalPeople + 1; i <= (2 * people + random + totalPeople); i++) {
                cout << "Person: " << i << " in queue." << endl;
                singleQueue.push(i);
                
            }
            totalPeople += (2 * people + random); //Updates the total amount of people
        }else if (click == 2){
            cout << "\nMore people added to queue" << endl;
            for (int i = totalPeople + 1; i <= (3 * people + random + totalPeople); i++) {
                cout << "Person: " << i << " in queue." << endl;
                singleQueue.push(i);
                
            }
            totalPeople += (3 * people + random); //Updates the total amount of people
        }else if (click == 5){
            cout << "\nMore people added to queue" << endl;
            for (int i = totalPeople + 1; i <= (2 * people + random + totalPeople); i++) {
                cout << "Person: " << i << " in queue." << endl;
                singleQueue.push(i);
                
            }
            totalPeople += (2 * people + random); //Updates the total amount of people
        }else if (click == 7){
            cout << "\nMore people added to queue" << endl;
            for (int i = totalPeople + 1; i <= (people + random + totalPeople); i++) {
                cout << "Person: " << i << " in queue." << endl;
                singleQueue.push(i);
                
            }
            totalPeople += (people + random); //Updates the total amount of people
        }else if(click == 9){
            cout << "\nMore people added to queue" << endl;
            for (int i = totalPeople +1 ; i <= (people + totalPeople); i++) {
                cout << "Person: " << i << " in queue." << endl;
                singleQueue.push(i);
                
            }
            totalPeople += (people); //Updates the total amount of people
        }
    }
    
    return click;
    
};

//Multiple queues function
int multiQueue(int servers, int people, int random){
    int click = 0;                          //Number of clicks counter
    int userInput = 0;                      //Holds user menu selection
    int qPtr = 0;                           //Queue pointer
    int peopleCounter = 0;                  //Keep count of people in the queue
    bool queueEmpty = false;                //Boolean to determine if all queues are empty
    int totalPeople = 0;                    //Total number of people
    
    cout << "\n\nMultiple Queues\n"<<endl;
    
    //Create a vector of queues
    vector< queue<int> > multiQueue;
    
    //Loop to add queues
    for (int i = 0; i < servers; i++) {
        multiQueue.push_back(queue<int>());         //push queues to vector
    }
    //Load initial arrival of people
    for (int i = 1; i <= people ; i++) {
        //Fills a queue and adds one to the queue pointer
        if (qPtr < servers) {
            cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
            multiQueue[qPtr].push(i);
            qPtr++;
        }else{                                     //Reached the last queue
            qPtr = 0;                              //reset qPtr when it reaches the last queue
            cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
            multiQueue[qPtr].push(i);
            qPtr++;
        }
        totalPeople++;                              //Inc total people
    }
    click++;                                        //Adds one to click when filling queue
    
    while (!queueEmpty) {
        
        cout << "\nEnter 1 to click: ";
        cin >> userInput;
        
        //Takes out of queue
        if (userInput == 1) {
            for (int i = 0; i < servers; i++) {
                if (peopleCounter < totalPeople) {
                    cout << "Person: " << multiQueue[i].front() << " out of queue " << i+1 << endl;
                    multiQueue[i].pop();
                    peopleCounter++;
                }
            }
            click++;
        }
        //Gradually increases and decreases people arriving to queue
        if (click == 2) {
            cout << "\nMore people added to queue" << endl;
            //Load new arrival of people
            for (int i = totalPeople + 1; i <= (2 * people + random + totalPeople); i++){
                //Fills a queue and adds one to the queue pointer
                if (qPtr < servers) {
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }else{                                     //Reached the last queue
                    qPtr = 0;                              //reset qPtr when it reaches the last queue
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }
            }
            totalPeople += (2 * people + random); //Updates the total amount of people
            click++;
        }else if (click == 5){
            cout << "\nMore people added to queue" << endl;
            //Load new arrival of people
            for (int i = totalPeople + 1; i <= (3 * people + random + totalPeople); i++){
                //Fills a queue and adds one to the queue pointer
                if (qPtr < servers) {
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }else{                                     //Reached the last queue
                    qPtr = 0;                              //reset qPtr when it reaches the last queue
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }
            }
            totalPeople += (3 * people + random); //Updates the total amount of people
            click++;
        }else if (click == 9){
            cout << "\nMore people added to queue" << endl;
            //Load new arrival of people
            for (int i = totalPeople + 1; i <= (2 * people + random + totalPeople); i++){
                //Fills a queue and adds one to the queue pointer
                if (qPtr < servers) {
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }else{                                     //Reached the last queue
                    qPtr = 0;                              //reset qPtr when it reaches the last queue
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }
            }
            totalPeople += (2 * people + random); //Updates the total amount of people
            click++;
        }else if (click == 12){
            cout << "\nMore people added to queue" << endl;
            //Load new arrival of people
            for (int i = totalPeople + 1; i <= (people + random + totalPeople); i++){
                //Fills a queue and adds one to the queue pointer
                if (qPtr < servers) {
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }else{                                     //Reached the last queue
                    qPtr = 0;                              //reset qPtr when it reaches the last queue
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }
            }
            totalPeople += (people + random); //Updates the total amount of people
            click++;
        }else if(click == 15){
            cout << "\nMore people added to queue" << endl;
            //Load new arrival of people
            for (int i = totalPeople + 1; i <= (people + totalPeople); i++){
                //Fills a queue and adds one to the queue pointer
                if (qPtr < servers) {
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }else{                                     //Reached the last queue
                    qPtr = 0;                              //reset qPtr when it reaches the last queue
                    cout << "Person: " << i << " in queue " << qPtr + 1 << endl;
                    multiQueue[qPtr].push(i);
                    qPtr++;
                }
            }
            totalPeople += (people); //Updates the total amount of people
            click++;
        }
        //Trips boolean when queues are empty
        if (peopleCounter >= totalPeople) {
            queueEmpty = true;
        }
    }
    
    return click;
    
};


int main() {
    
    srand((int)time(NULL));
    
    int servers = 0;                        //Number of servers
    int randomPeople = 0;                   //Random number of people
    int people = 0;                         //Number of people
    int singleClick = 0;
    int multiClick = 0;
    cout << "Enter the number of servers: ";
    cin >> servers;
    cout << "\n" << endl;
    
    people = servers;
    randomPeople = randomNum(servers);      //Gets a random number of extra people

    singleClick = singleQueue(servers, people, randomPeople);
    multiClick = multiQueue(servers, people, randomPeople);
    
    cout << "\n\nSingle queue took " << singleClick << " clicks." << endl;
    cout << "Multiple queues took " << multiClick << " clicks." << endl;
    
    return 0;
}
