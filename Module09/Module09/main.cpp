//
//  Name: Daniel Bacon
//  Assignment: Module09 - Ch 12 Programming Problem #3
//

/*
 Complete the implementation of the class SortedListHasA.
 
 For this assignment, implement a high score system using a SortedListHasA to
 sort scores from highest to lowest.
 
 Seed the high score list with a few dummy scores, ala vintage arcade games,
 (e.g. 555,444,333,222,111).
 
 Your program should print out a list of scores
 
 Ask the user for a new score, insert the new score in the correct position,
 print out the new score list
 
 let the user keep entering scores and displaying the sorted list until the user
 quits. (the user indicates a quit state by entering a sentinel - a negative
 value for a high score).
 
 In rough pseudo-code, we are looking at:
 
 insertSorted(111); ... insertSorted(555)
 displayList displays 555, 444, 333, 222, 111
 insertSorted(300)
 displayList displays 555, 444, 333, 300, 222, 111
 Loop for new scores until newScore < 0
 insertSorted(newScore)
 displayList
 
 Unlike vintage arcade games, we are just storing the scores and not associated
 names or initials of who got the score.
 */

#include <iostream>

int main(int argc, const char * argv[]) {
    return 0;
}
