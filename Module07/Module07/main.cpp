//
//  main.cpp
//  Module07
//
//  Created by Daniel Bacon on 10/13/19.
//  Copyright © 2019 Daniel Bacon. All rights reserved.
//

/*
 Programming Problem #2 and 3
 Data Abstraction and Problem Solving with C++ 6th ed page 287
    Write an array-based implementation of the ADT list that expands the size of
    the array of list entries as needed so that the list can always accommodate a
    new entry.
 
 Also reduce the size of the array as needed to accommodate several removals.
    When the size of the array is greater than 20 and the number of entries in
    the list is less than half the size of the array, reduce the size of the
    array so that it is three quarters of its current size.
 
 Note: In expanding the array - when an element is added to a full array, double
    the size of the array.
 
 Key Topics
 Input
    List detects and responds to a need for expansion
    List detects and responds to a need for contraction
 Processing
    Correct implementation of the array based list as described in the textbook.
    Use of templates
    Use of interface
 Output
    main function demonstrates lists features and dynamic sizing
    Proper clean up - no dangling pointers, no memory leaks.
 */
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
