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

template <class ItemType>
class ArrayList {
    private :
        static const int DEFAULT_CAPACITY = 10;
        ItemType* items;
        int itemCount;
        int maxItems;
    
    public :
        ArrayList();
        // Copy constructor and destructor are supplied by compiler
    
        /**
         Sees whether this list is empty.
         @return True if the list is empty; otherwise returns false.
        */
        bool isEmpty() const;
    
        /**
         Gets the current number of entries in this list.
         @return The integer number of entries currently in the list.
        */
        int getLength() const;
    
        /**
         Inserts an entry into this list at a given position.
         @pre None.
         @post If successful, newEntry is at the given position in the list,
         other entries are renumbered accordingly, and the returned
         value is true.
         
         @param newPosition The list position at which to insert newEntry.
         @param newEntry The entry to insert into the list.
         @return True if insertion is successful, or false if not.
        */
        bool insert( int newPosition, const ItemType& newEntry);
    
        /**
         Removes the entry at a given position from this list.
         @pre None.
         @post If successful, the entry at the given position in the list is
         removed, other items are renumbered accordingly, and the returned value
         is true.
         
         @param position The list position of the entry to remove.
         @return True if removal is successful, or false if not.
        */
        bool remove( int position);
    
        /**
         Removes all entries from this list.
         @post List contains no entries and the count of items is 0.
        */
        void clear();
    
        /**
         Gets the entry at the given position in this list.
         @pre 1 <= position <= getLength().
         @post The desired entry has been returned.
         
         @param position The list position of the desired entry.
         @return The entry at the given position.
        */
        ItemType getEntry( int position) const;
    
        /**
         Replaces the entry at the given position in this list.
         @pre 1 <= position <= getLength().
         @post The entry at the given position is newEntry.
         
         @param position The list position of the entry to replace.
         @param newEntry The replacement entry.
        */
        void setEntry( int position, const ItemType& newEntry);
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
