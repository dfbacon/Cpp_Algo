/*
 Name: Daniel Bacon
 Class: kSmall
 Assignment: Module 2 - Programming Problem #4.
 */

#include <algorithm>

using namespace std;


void sortThreeEntries(int anArray[], int first, int middle, int last) {
    if (anArray[first] > anArray[middle])
        swap(anArray[first], anArray[middle]);
    
    if (anArray[middle] > anArray[last])
        swap(anArray[middle], anArray[last]);

    if (anArray[first] > anArray[middle])
        swap(anArray[first], anArray[middle]);
}






int partition(int anArray[], int first, int last) {
    int mid, pivot, pivotIndex, leftIndex, rightIndex;
    bool finished = false;


    mid = first + (last - first) / 2;
    sortThreeEntries(anArray, first, mid, last);
    swap(anArray[mid], anArray[last - 1]);

    pivotIndex = last - 1;
    pivot = anArray[pivotIndex];

    leftIndex = first + 1;
    rightIndex = last - 2;

    while (!finished) {

        while (anArray[leftIndex] < pivot)
            leftIndex += 1;

        while (anArray[rightIndex] > pivot)
            rightIndex -= 1;

        if (leftIndex < rightIndex) {
            //Move anArray[firstUnknown] into S1
            swap(anArray[leftIndex], anArray[rightIndex]);
            leftIndex += 1;
            rightIndex -= 1;
        } else {
            finished = true;
        }
    }

    swap(anArray[pivotIndex], anArray[leftIndex]);
    pivotIndex = leftIndex;

    return pivotIndex;
}






int kSmall(int k, int anArray[], int first, int last) {
    // Choose a pivot value p from anArray[first..last] p = 0
    // Partition the values of anArray[first..last] about p
    int pivotIndex = partition(anArray, first, last);
    
    if (k < pivotIndex - first + 1)
        return kSmall(k, anArray, first, pivotIndex - 1);
    
    else if (k == pivotIndex - first + 1) {
        cout << "pivotIndex is " << pivotIndex << endl;
        return anArray[pivotIndex];
    }
    
    else
        return kSmall(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
}
