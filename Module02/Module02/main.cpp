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
    int testArray1[] = {6,3,1,2,4,5};
    int position = 4;
    cout << "answer is: 4" << endl << "kSmall answer is: " << kSmall(position, testArray1, 0, ARRAY_SIZE -1) << endl;
    int testArray2[] = {20,11,12,-45,7,18};
    position = 3;
    cout << "answer is: 11" << endl << "kSmall answer is: " << kSmall(position, testArray2, 0, ARRAY_SIZE -1) << endl;
}

