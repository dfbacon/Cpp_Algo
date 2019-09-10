/**
 * @file main.cpp
 * Provided by instructor.
 */

#include <iomanip>
#include <iostream>
#include <string>
#include "pp04.cpp"

using namespace std;
int const ARRAY_SIZE = 6;

int main()
{
    int testArray1[] = {6,3,1,2,4,5}; //1, 2, 3, 4, 5, 6
    int position = 1;
    cout << "answer is: 1" << endl << "kSmall answer is: " << kSmall(position, testArray1, 0, ARRAY_SIZE -1) << endl;
    
    int testArray2[] = {20,11,12,-45,7,18}; //-45, 7, 11, 12, 18, 20
    position = 3;
    cout << "answer is: 11" << endl << "kSmall answer is: " << kSmall(position, testArray2, 0, ARRAY_SIZE -1) << endl;
    
    int testArray[] = {4,3,1,2};
    position = 2;
    cout << "answer is: 2" << endl << "kSmall answer is: " << kSmall(position, testArray, 0, 3) << endl;
    
    int sortedArray[] = {1, 2, 3, 4, 5};
    position = 3;
    cout << "answer is: 3" << endl << "kSmall answer is: " << kSmall(position, sortedArray, 0, 4) << endl;

}

