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
    int mid, pivot, pivotIndex, leftIndex, rightIndex;
    bool finished = false;
    
    if (first >= last) {
        return first;
    }
    
    mid = first + (last - first) / 2;
    medianOfThree(anArray, first, mid, last);
    swap(anArray[mid], anArray[last - 1]);
    
    pivotIndex = last - 1;
    pivot = anArray[pivotIndex];
    leftIndex = first + 1;
    rightIndex = last - 2;
    
    while (!finished) {
        while (anArray[leftIndex] <= pivot) {
            leftIndex += 1;
        }
        
        while (anArray[rightIndex] > pivot) {
            rightIndex -= 1;
        }
        
        if (leftIndex < rightIndex) {
            swap(anArray[leftIndex], anArray[rightIndex]);
            leftIndex += 1;
            rightIndex -= 1;
        }
        else {
            finished = true;
        }
    }
    
    if (leftIndex < pivotIndex) {
        swap(anArray[pivotIndex], anArray[leftIndex]);
    }
  
    pivotIndex = leftIndex;
    
    return pivotIndex;
}






int kSmall(int k, int anArray[], int first, int last) {
    if (k > last || k < 0 || first < 0 || first > last || last < 0) {
        return -1;
    }
    
    int pivotIndex = partition(anArray, first, last);
    
    if (k < pivotIndex) {
        return kSmall(k, anArray, first, pivotIndex - 1);
    }
    
    else if (k == pivotIndex) {
        return anArray[pivotIndex - 1];
    }
    
    else {
        return kSmall(k, anArray, pivotIndex + 1, last);
    }
}
