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
    int position = 4;
    cout << "answer is: 4" << endl << "kSmall answer is: " << kSmall(position, testArray1, 0, ARRAY_SIZE -1) << endl;

    int testArray2[] = {20,11,12,-45,7,18}; //-45, 7, 11, 12, 18, 20
    position = 12;
    cout << "answer is: 11" << endl << "kSmall answer is: " << kSmall(position, testArray2, 0, ARRAY_SIZE -1) << endl;

    int testArray[] = {4,3,1,2};
    position = 2;
    cout << "answer is: 2" << endl << "kSmall answer is: " << kSmall(position, testArray, 0, 3) << endl;

    int sortedArray[] = {1,2,3,4,5,6};
    position = 4;
    cout << "answer is: 4" << endl << "kSmall answer is: " << kSmall(position, sortedArray, 0, ARRAY_SIZE - 1) << endl;

    int largeArray[] = {6, 2, 15, 13, 4, 5, 9, 7, 8, 1, 3, 12, 11, 14, 10};
    position = 10;
    cout << "answer is: 10" << endl << "kSmall answer is: " << kSmall(position, largeArray, 0, 14) << endl;

}
