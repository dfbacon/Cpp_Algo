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
#include <string>
#include <stdexcept>

using namespace std;

class PrecondViolatedExcep: public logic_error
{
    public :
    PrecondViolatedExcep(const string& message = ""):
        logic_error("Precondition Violated Exception: " + message){}
};

template <class ItemType>
class ListInterface {
    public :
    /** Sees whether this list is empty.
     @return True if the list is empty; otherwise returns false. */
    virtual bool isEmpty() const = 0;
    
    /** Gets the current number of entries in this list.
     @return The integer number of entries currently in the list. */
    virtual int getLength() const = 0;
    
    /** Inserts an entry into this list at a given position.
     @pre None.
     @post If 1 <= position <= getLength() + 1 and the insertion is
     successful, newEntry is at the given position in the list,
     other entries are renumbered accordingly, and the returned
     value is true.
     @param newPosition The list position at which to insert newEntry.
     @param newEntry The entry to insert into the list.
     @return True if insertion is successful, or false if not. */
    virtual bool insert( int newPosition, const ItemType& newEntry) = 0;
    
    /** Removes the entry at a given position from this list.
     @pre None.
     @post If 1 <= position <= getLength() and the removal is successful,
     the entry at the given position in the list is removed, other
     items are renumbered accordingly, and the returned value is true.
     @param position The list position of the entry to remove.
     @return True if removal is successful, or false if not. */
    virtual bool remove( int position) = 0;
    
    /** Removes all entries from this list.
     @post List contains no entries and the count of items is 0. */
    virtual void clear() = 0;
    
    /** Gets the entry at the given position in this list.
     @pre 1 <= position <= getLength().
     @post The desired entry has been returned.
     @param position The list position of the desired entry.
     @return The entry at the given position. */
    virtual ItemType getEntry( int position) const = 0;
    
    /** Replaces the entry at the given position in this list.
     @pre 1 <= position <= getLength().
     @post The entry at the given position is newEntry.
     @param position The list position of the entry to replace.
     @param newEntry The replacement entry. */
    virtual void setEntry( int position, const ItemType& newEntry) = 0;
};


template <class ItemType>
class SortedListInterface: ListInterface<ItemType> {
    public :
    /** Inserts an entry into this sorted list in its proper order
     so that the list remains sorted.
     @pre None.
     @post newEntry is in the list, and the list is sorted.
     @param newEntry The entry to insert into the sorted list. */
    virtual void insertSorted( const ItemType& newEntry) = 0;
    
    /** Removes the first or only occurrence of the given entry from this
     sorted list.
     @pre None.
     @post If the removal is successful, the first occurrence of the
     given entry is no longer in the sorted list, and the returned
     value is true. Otherwise, the sorted list is unchanged and the
     returned value is false.
     @param anEntry The entry to remove.
     @return True if removal is successful, or false if not. */
    virtual bool removeSorted( const ItemType& anEntry) = 0;
    
    /** Gets the position of the first or only occurrence of the given
     entry in this sorted list. In case the entry is not in the list,
     determines where it should be if it were added to the list.
     @pre None.
     @post The position where the given entry is or belongs is returned.
     The sorted list is unchanged.
     @param anEntry The entry to locate.
     @return Either the position of the given entry, if it occurs in the
     sorted list, or the position where the entry would occur, but as a
     negative integer. */
    virtual int getPosition( const ItemType& anEntry) = 0;
    
    // The following methods are the same as those given in ListInterface
    // in Listing 8-1 of Chapter 8 and are completely specified there.
    /** Sees whether this list is empty. */
    virtual bool isEmpty() const = 0;
    
    /** Gets the current number of entries in this list. */
    virtual int getLength() const = 0;
    
    /** Removes the entry at a given position from this list. */
    virtual bool remove( int position) = 0;
    
    /** Removes all entries from this list. */
    virtual void clear() = 0;
    
    /** Gets the entry at the given position in this list. */
    virtual ItemType getEntry( int position) const = 0;
};


template < class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>
{
    private :
    ListInterface<ItemType>* listPtr;
    int itemCount;
    
    public :
    SortedListHasA();
    SortedListHasA(const SortedListHasA<ItemType>& sList);
    virtual ~SortedListHasA();
    void insertSorted( const ItemType& newEntry);
    bool removeSorted( const ItemType& anEntry);
    int getPosition( const ItemType& newEntry) const;

    bool isEmpty() const {
        return itemCount == 0;
    }
    
    int getLength() const {
        return itemCount;
    }
    
    bool remove(int position) {
        bool ableToRemove = (position >= 1) && (position <= itemCount);
        
        if (ableToRemove) {
            
            for (int fromIndex = position, toIndex = fromIndex - 1;
                 fromIndex < itemCount; fromIndex++, toIndex++) {
                
                listPtr[toIndex] = listPtr[fromIndex];
            }
            
            itemCount--;
        }
        
        return ableToRemove;
    }
    
    void clear() {
        for (int index = 0; index < itemCount; index++) {
            
            listPtr[index] = NULL;
        }
        
        itemCount = 0;
    }
    
    ItemType getEntry( int position) const throw(PrecondViolatedExcep) {
        bool ableToGet = (position >= 1) && (position <= itemCount);
        
        if (ableToGet) {
            
            return listPtr[position - 1];
        }
        else {
            
            string message = "getEntry() called with an empty list or ";
            message = message + "invalid position.";
            throw(PrecondViolatedExcep(message));
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
