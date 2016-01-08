/**************************************************************************
 * Author: William Kim
 * Date: 8/2/2015
 * Description: This method finds the mode of a set of numbers
 *************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<int> findMode(int array[], int size){
    
    int highestFrequency = 0;
    vector<int> mode;
    
    // First loop to determine highest frequency
    for(int i = 0; i < size; i++){
        int counter = 0;
        for(int j = 0; j < size; j++){
            if(array[i] == array[j])
                counter++;
        }
        if(counter > highestFrequency){
            highestFrequency = counter;
        }
    }
    
    // Second loop to find all numbers matching the highest frequency
    for(int i = 0; i < size; i++){
        int counter = 0;
        for(int j = 0; j < size; j++){
            if(array[i] == array[j])
                counter++;
        }
        if(counter == highestFrequency){
            bool isInMode = false;
            for(int m = 0; m < mode.size(); m++){
                if(array[i] == mode[m]){
                    isInMode = true;
                }
            }
            if(!isInMode){
                mode.push_back(array[i]);
            }
        }
    }
    
    sort(mode.begin(), mode.end());
    return mode;
}