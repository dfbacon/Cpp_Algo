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
    int testArray[] = {6,4,1,2};
    int postioin = 1;
    cout << "TESTING\nanswer is: 1" << endl << "kSmall answer is: " << kSmall(postioin, testArray, 0, 3) << endl;
//    int testArray1[] = {6,3,1,2,4,5}; //1, 2, 3, 4, 5, 6
//    int position = 4;
//    cout << "answer is: 4" << endl << "kSmall answer is: " << kSmall(position, testArray1, 0, ARRAY_SIZE -1) << endl;
//    int testArray2[] = {20,11,12,-45,7,18}; //-45, 7, 11, 12, 18, 20
//    position = 3;
//    cout << "answer is: 11" << endl << "kSmall answer is: " << kSmall(position, testArray2, 0, ARRAY_SIZE -1) << endl;
//    int testArray3[] = {1, 2, 3, 4, 5, 6};
//    int position = 1;
//    cout << "answer is: 1" << endl << "kSmall answer is: " << kSmall(position, testArray3, 0, ARRAY_SIZE - 1) << endl;

}

