/*
 Name: Daniel Bacon
 Class: kSmall
 Assignment: Module 2 - Programming Problem #4.
 */

#include <algorithm>
using namespace std;

int partition(int anArray[], int first, int last);


/** Finds the kth smallest integer in an array of integers.
 
 @pre anArray[first..last] is an array of integers.
 @post anArray[first..last] is at least partially sorted.
 @param k The element to find.
 @param anArray The given array.
 @param first The first element to consider in anArray.
 @param last The last element to consider in anArray.
 @return The kth smallest element in @anArray; -1 if not found.
 */
int kSmall(int k, int anArray[], int first, int last) {
    
    if (k > 0 && k <= last - first + 1) {
        int pivotIndex = partition(anArray, first, last);
        
        if (k - 1 < pivotIndex - first) {
            return kSmall(k, anArray, first, pivotIndex - 1);
        }
        else if (k == pivotIndex - first + 1) {
            return anArray[pivotIndex];
        }
        else {
            return kSmall(k - (pivotIndex - first + 1), anArray, pivotIndex + 1, last);
        }
    }
    
    return -1;
}






/** Partitions an array of integers around a pivot. The pivot is the first
    element to consider in the given array.
 
 @pre anArray[first..last] is an array of integers.
 @post anArray[first..last] is partitioned around the pivot value.
 @param anArray The given array.
 @param first The first element to consider in anArray.
 @param last The last element to consider in anArray.
 @return The index of the pivot value.
 */
int partition(int anArray[], int first, int last) {
    
    int pivot = anArray[first], rightIndex = last;
    
    for (int searchIndex = last; searchIndex >= first + 1; searchIndex--) {
        if (anArray[searchIndex] > pivot) {
            swap(anArray[rightIndex], anArray[searchIndex]);
            rightIndex--;
        }
    }
    
    swap(anArray[rightIndex], anArray[first]);
    
    return rightIndex;
}
