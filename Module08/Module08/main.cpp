//
//  Name: Daniel Bacon
//  Assignment: Module08 - Ch 10 Exercises #1, 3, 4, 5. Ch 11 Exercises #6
//

#include <iostream>
/**
 10 - 1. Using Big O notation, indicate the time requirement of each of the
    following tasks in the worst case. Describe any assumptions that you make.
 
 Q: After arriving at a party, you shake hands with each person there.
 A: O(n). Assume shaking each person's hand one time and n is the number of
    people.
 
 Q: Each person in a room shakes hands with everyone else in the room.
 A: O(n^2). Same assumptions described above.
 
 Q: You climb a flight of stairs.
 A: O(n). n is the number of stairs.
 
 Q: You slide down the banister.
 A: O(1)
 
 Q: After entering an elevator, you press a button to choose a floor.
 A: O(1). Assuming you are only pressing a button.
 
 Q: You ride the elevator from the ground floor up to the nth floor.
 A: O(n). Assuming the elevator stops at all floors. n is the number of floors.
 
 Q: You read a book twice.
 A: 2*O(n) or just O(n). n is the number of pages in the book.
 
 ##############################################################################
 
 10 - 3. Using Big O notation, indicate the time requirement of each of the
    following tasks in the worst case.
 
 Q: Computing the sum of the first n even integers by using a for loop.
 A: O(n)
 
 Q: Displaying all n integers in an array.
 A: O(n)
 
 Q: Displaying all n integers in a sorted linked chain
 A: O(n)
 
 Q: Displaying all n names in an array of linked chains
 A: O(n)
 
 Q: Displaying one array element
 A: O(1)
 
 Q: Displaying the last integer in a linked chain
 A: O(n)
 
 Q: Searching an array of n items for a particular value by using a sequential
    search
 A: O(n)
 
 Q: Searching an array of n items for a particular value by using a binary
    search
 A: O(n log n)
 
 Q: Adding an item to a stack of n items
 A: O(1)
 
 Q: Adding an item to a bag of n items
 A: O(1)
 
 ##############################################################################
 
 10 - 4. What is the Big O of the algorithm?
 
 O(n^2 * 10) or just O(n^2). The inner-most loop runs a constant 10 times for
 the n number of times that the middle loop runs, which in turn is running n
 times (the outer loop). For Big O you drop the constants so the constant 10 is
 dropped leaving the nested loops of O(n^2).
 
 ##############################################################################

 10 - 5. How many comparisons does f perform?
 
 Assuming n is a non-negative integer that is less-than-or-equal-to the size of
 the array. If this assumption is true, f performs n comparisons.
 
 ##############################################################################
 
 11 - 6. How many comparisons would be needed to sort an array containing 25
    entries using the bubble sort in:
        Q: The worst case? O(n^2)
        A: 625
 
        Q: The best case? O(n)
        A: 25
 */
int main(int argc, const char * argv[]) { return 0; }
