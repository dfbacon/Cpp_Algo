/**
 * @file main.cpp
 * Provided by instructor.
 */

/*
 // Returns the kth smallest value in anArray[first..last].
 kSmall(k: integer, anArray: ArrayType,first: integer, last: integer): ValueType
 {
 //Choose a pivot value p from anArray[first..last] p = 0
 //Partition the values of anArray[first..last] about p
 if (k < pivotIndex - first + 1)
 return kSmall(k, anArray, first, pivotIndex - 1)
 else if (k == pivotIndex - first + 1)
 return p
 else
 return kSmall(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last)
 }
 //This pseudocode is not far from a C++ function. The only questions that remain are how to choose the pivot value p and how to partition the array about the chosen p. The choice of p is arbitrary. Any p in the array will work, although the sequence of choices will affect how soon you reach the base case. Chapter 11 gives an algorithm for partitioning the values about p. There you will see how to turn the function kSmall into a sorting algorithm.
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

