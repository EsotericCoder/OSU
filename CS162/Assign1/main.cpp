/**********************************************************************************
 * Author: William Kim
 * Description: Conway's Game of Life
 * Date: 10/2/2015
 *********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//Copies a temp array into the main array
void copyArray(int array1[50][100], int array2[50][100])
{
    for(int j = 0; j < 50; j++)
    {
        for(int i = 0; i < 100; i++)
            array2[j][i] = array1[j][i];
    }
}

//This function determines which cells live or die
void judgementDay(int array[50][100])
{
    //Initialize temp array so we can many change without effecting any other cells
    int tempArray[50][100];
    copyArray(array, tempArray);
    
    
    for(int j = 1; j < 50; j++)
    {
        for(int i = 1; i < 100; i++)
        {
            //Counts the number alive
            int count = 0;
            
            //Checks all 8 surrounding cells
            count = array[j-1][i] +
                    array[j-1][i-1] +
                    array[j-1][i+1] +
                    array[j][i-1] +
                    array[j][i+1] +
                    array[j+1][i] +
                    array[j+1][i-1] +
                    array[j+1][i+1];
            
            //if...else statment to determine if the cells live or die.
            if(count < 2 || count > 3){
                tempArray[j][i] = 0;
            }else if(count == 3){
                tempArray[j][i] = 1;
            }else{
                tempArray[j][i] = array[j][i];
            }
        }
    }
    //Copies the completed temp array back to the main array.
    copyArray(tempArray, array);
}

//Outputs the array
void output(int array[50][100])
{
    for(int j = 10; j < 30; j++)
    {
        for(int i = 10; i < 50; i++)
        {
            if(array[j][i] == 1)
                cout << 'x'; //alive
            else
                cout << ' '; //dead
        }
        cout << endl;
        
    }
    cout << "Conway's Game of Life by: Will Kim" << endl;
}

int main()
{
    int x, y;
    int const XCOORMAX = 20;
    int const XCOORMIN = 0;
    int const YCOORMAX = 40;
    int const YCOORMIN = 0;
    
    
    
    cout << "Please enter the X coordinate between 0-20: ";
    cin >> x;
    while( x < XCOORMIN || x > XCOORMAX ){
        cout << "Please enter a valid X coordinate: ";
        cin >> x;
    }
    cout << endl;
        
    cout << "Please enter the Y coordinate between 0-40: ";
    cin >> y;
    while( y < YCOORMIN || y > YCOORMAX ){
        cout << "Please enter a valid Y coordinate: ";
        cin >> y;
    }
    cout << endl;
    
    //Initialize variables and arrays
    int array[50][100] = {{0}}; //Initialize the whole array to 0

    //Glider
    array[x+24][y+46] = 1;
    array[x+25][y+47] = 1;
    array[x+26][y+45] = 1;
    array[x+26][y+46] = 1;
    array[x+26][y+47] = 1;
        
    //Blinker
    array[x+26][y+13] = 1;
    array[x+26][y+14] = 1;
    array[x+26][y+15] = 1;
        
    //Cannon
    array[x+16][y+12] = 1;
    array[x+16][y+13] = 1;
    array[x+17][y+12] = 1;
    array[x+17][y+13] = 1;
    array[x+14][y+48] = 1;
    array[x+14][y+49] = 1;
    array[x+15][y+48] = 1;
    array[x+15][y+49] = 1;
    array[x+14][y+24] = 1;
    array[x+14][y+25] = 1;
    array[x+15][y+23] = 1;
    array[x+15][y+27] = 1;
    array[x+16][y+22] = 1;
    array[x+16][y+28] = 1;
    array[x+17][y+22] = 1;
    array[x+17][y+26] = 1;
    array[x+17][y+28] = 1;
    array[x+17][y+29] = 1;
    array[x+18][y+22] = 1;
    array[x+18][y+28] = 1;
    array[x+19][y+23] = 1;
    array[x+19][y+27] = 1;
    array[x+20][y+24] = 1;
    array[x+20][y+25] = 1;
    array[x+12][y+36] = 1;
    array[x+13][y+34] = 1;
    array[x+13][y+36] = 1;
    array[x+14][y+32] = 1;
    array[x+14][y+33] = 1;
    array[x+15][y+32] = 1;
    array[x+15][y+33] = 1;
    array[x+16][y+32] = 1;
    array[x+16][y+33] = 1;
    array[x+17][y+34] = 1;
    array[x+17][y+36] = 1;
    array[x+18][y+36] = 1;

    //To loop forever
    while(1){
        output(array);
        judgementDay(array);
        
        //Allows image to refresh and clears screen
        system("sleep .5");
        system("clear");

    }
    return 0;
}
