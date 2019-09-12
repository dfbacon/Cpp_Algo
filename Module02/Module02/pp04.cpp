/*
 Name: Daniel Bacon
 Class: kSmall
 Assignment: Module 2 - Programming Problem #4.
 
 The function accepts the arguments outlined in Section 2.4.4
 The function uses the first element of the array as the pivot
 
 The function is recursive.
 The function differentiates between the three states.
 
 The function returns the appropriate base case when the base case conditions are met.
 The function divides the problem up into smaller problems that move to the base case.
 The function returns the correct value based on inputs.
 
 */

#include <algorithm>
using namespace std;

int partition(int anArray[], int first, int last);


int partition(int anArray[], int first, int last) {
    
    int pivot = anArray[last], leftIndex = first;
    
    for (int searchIndex = first; searchIndex <= last - 1; searchIndex++) {
        if (anArray[searchIndex] <= pivot) {
            
            swap(anArray[leftIndex], anArray[searchIndex]);
            leftIndex++;
        }
    }
    
    swap(anArray[leftIndex], anArray[last]);
    return leftIndex;
}






int kSmall(int k, int anArray[], int first, int last) {

    if (k > 0 && k <= last - first + 1) {
        int pivotIndex = partition(anArray, first, last);
        
        if (k - 1 < pivotIndex - first) {
            return kSmall(k, anArray, first, pivotIndex - 1);
        }
        else if (k - 1 == pivotIndex - first) {
            return anArray[pivotIndex];
        }
        else {
            return kSmall(k - (pivotIndex + first - 1), anArray, pivotIndex + 1, last);
        }
    }
    
    return -1;
}
