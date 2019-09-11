/*
 Name: Daniel Bacon
 Class: kSmall
 Assignment: Module 2 - Programming Problem #4.
 */

#include <algorithm>

using namespace std;


void medianOfThree(int anArray[], int first, int middle, int last) {
    if (anArray[first] > anArray[middle]) {
        swap(anArray[first], anArray[middle]);
    }
    
    if (anArray[middle] > anArray[last]) {
        swap(anArray[middle], anArray[last]);
    }
    
    if (anArray[first] > anArray[middle]) {
        swap(anArray[first], anArray[middle]);
    }
}






int partition(int anArray[], int first, int last) {
    int leftIndex = first;
    int rightIndex = last;
    
    for (int i = first; i < last; i++) {
        
        if (anArray[i] < anArray[rightIndex]) {
            swap(anArray[i], anArray[leftIndex]);
            leftIndex++;
        }
    }
    
    swap(anArray[rightIndex], anArray[leftIndex]);
    
    return leftIndex;
}






int kSmall(int k, int anArray[], int first, int last) {
    int middleIndex = first + (last - first) / 2;
    medianOfThree(anArray, first, middleIndex, last);
    
    int pivotIndex = partition(anArray, first, last);
    
    if (k < pivotIndex - first + 1) {
        return kSmall(k, anArray, first, pivotIndex - 1);
    }
    
    else if (k == pivotIndex - first + 1) {
        return anArray[pivotIndex];
    }
    
    else {
        return kSmall(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
    }
}
