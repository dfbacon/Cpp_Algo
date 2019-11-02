//
//  Name: Daniel Bacon
//  Assignment: Module09 - Ch 12 Programming Problem #3
//

#include <iostream>
#include <cstddef>
#include <cassert>
#include <cmath>

using namespace std;


template <class ItemType>
class Node {
    
private:
    
    ItemType item;
    Node<ItemType>* next;
    
public:
    
    Node() : next(nullptr) {}
    Node(const ItemType& anItem) : item(anItem), next(nullptr) {}
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) :
        item(anItem), next(nextNodePtr) {}
    
    void setItem(const ItemType& anItem) {
        
        item = anItem;
    }
    
    void setNext(Node<ItemType>* nextNodePtr) {
        
        next = nextNodePtr;
    }
    
    ItemType getItem() const {
        
        return item;
    }
    
    Node<ItemType>* getNext() const {
        
        return next;
    }
};






template <class ItemType>
class ListInterface {
    
public:
    
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
    virtual bool insert(int newPosition, const ItemType& newEntry) = 0;
    
    /** Removes the entry at a given position from this list.
     @pre None.
     @post If 1 <= position <= getLength() and the removal is successful,
     the entry at the given position in the list is removed, other
     items are renumbered accordingly, and the returned value is true.
     @param position The list position of the entry to remove.
     @return True if removal is successful, or false if not. */
    virtual bool remove(int position) = 0;
    
    /** Removes all entries from this list.
     @post List contains no entries and the count of items is 0. */
    virtual void clear() = 0;
    
    /** Gets the entry at the given position in this list.
     @pre 1 <= position <= getLength().
     @post The desired entry has been returned.
     @param position The list position of the desired entry.
     @return The entry at the given position. */
    virtual ItemType getEntry(int position) const = 0;
    
    /** Replaces the entry at the given position in this list.
     @pre 1 <= position <= getLength().
     @post The entry at the given position is newEntry.
     @param position The list position of the entry to replace.
     @param newEntry The replacement entry. */
    virtual void setEntry(int position, const ItemType& newEntry) = 0;
}; // End ListInterface






template <class ItemType>
class LinkedList : public ListInterface<ItemType> {
    
private:
    
    Node<ItemType>* headPtr;
    int itemCount;

    Node<ItemType>* getNodeAt(int position) const {
        
        assert ((position >= 1) && (position <= itemCount));
        Node<ItemType>* curPtr = headPtr;
        
        for (int index = 1; index < position; index++) {
         
            curPtr = curPtr->getNext();
        }
        
        return curPtr ;
    }
    
public:
    
    LinkedList() : headPtr(nullptr), itemCount(0) {}
    
    
    LinkedList(const LinkedList<ItemType>& aList) {

        if (aList.isEmpty()) {
            
            LinkedList();
        }
        else {
            
            LinkedList<ItemType>* tempList = new LinkedList<ItemType>();
            
            for (int index = 1; index <= aList.getLength(); index++) {
                
                tempList->insert(index, aList.getEntry(index));
            }
            
            headPtr = tempList->headPtr;
            itemCount = tempList->itemCount;
            delete tempList;
        }
    }
    
    
    virtual ~LinkedList() {

        clear();
    }
    
    
    bool isEmpty() const {
        
        return itemCount == 0;
    }
    
    
    int getLength() const {
        
        return itemCount;
    }
    
    
    bool insert(int newPosition, const ItemType& newEntry) {
        
        bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
        
        if (ableToInsert) {
            
            Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

            if (newPosition == 1) {
                
                newNodePtr->setNext(headPtr);
                headPtr = newNodePtr;
            }
            else {

                Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

                newNodePtr->setNext(prevPtr->getNext());
                prevPtr->setNext(newNodePtr);
            }
            
            itemCount++;
        }
        
        return ableToInsert;
    }
    
    
    bool remove(int position) {
        
        bool ableToRemove = (position >= 1) && (position <= itemCount);
        
        if (ableToRemove) {
            Node<ItemType>* curPtr = nullptr;
            
            if (position == 1) {

                curPtr = headPtr;
                headPtr = headPtr->getNext();
            }
            else {

                Node<ItemType>* prevPtr = getNodeAt(position - 1);

                curPtr = prevPtr->getNext();
                prevPtr->setNext(curPtr->getNext());
            }

            curPtr->setNext(nullptr);
            delete curPtr;
            curPtr = nullptr;
            itemCount--;
        }
        
        return ableToRemove;
    }
    
    
    void clear() {

        while (!isEmpty()) {
            remove(1);
        }
    }
    

    ItemType getEntry(int position) const {
        
        bool ableToGet = (position >= 1) && (position <= itemCount);
        
        if (ableToGet) {
            
            Node<ItemType>* nodePtr = getNodeAt(position);
            
            return nodePtr->getItem();
        }
        else {
            
            return NULL;
        }
    }
    

    void setEntry(int position, const ItemType& newEntry) {
    
        bool ableToGet = (position >= 1) && (position <= itemCount);
        
        if (ableToGet) {
            
            Node<ItemType>* nodePtr = getNodeAt(position);
            nodePtr->setItem(newEntry);
        }
    }
    
}; // End LinkedList





template <class ItemType>
class SortedListInterface: LinkedList<ItemType> {
    
public:
    
    /** Inserts an entry into this sorted list in its proper order
     so that the list remains sorted.
     @pre None.
     @post newEntry is in the list, and the list is sorted.
     @param newEntry The entry to insert into the sorted list. */
    virtual void insertSorted(const ItemType& newEntry) = 0;
    
    /** Removes the first or only occurrence of the given entry from this
     sorted list.
     @pre None.
     @post If the removal is successful, the first occurrence of the
     given entry is no longer in the sorted list, and the returned
     value is true. Otherwise, the sorted list is unchanged and the
     returned value is false.
     @param anEntry The entry to remove.
     @return True if removal is successful, or false if not. */
    virtual bool removeSorted(const ItemType& anEntry) = 0;
    
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
    virtual int getPosition(const ItemType& anEntry) const = 0;
    
    // The following methods are the same as those given in ListInterface
    // in Listing 8-1 of Chapter 8 and are completely specified there.
    /** Sees whether this list is empty. */
    virtual bool isEmpty() const = 0;
    
    /** Gets the current number of entries in this list. */
    virtual int getLength() const = 0;
    
    /** Removes the entry at a given position from this list. */
    virtual bool remove(int position) = 0;
    
    /** Removes all entries from this list. */
    virtual void clear() = 0;
    
    /** Gets the entry at the given position in this list. */
    virtual ItemType getEntry(int position) const = 0;
    
}; // End SortedListInterface






template <class ItemType>
class SortedListHasA : public SortedListInterface<ItemType> {
    
private:
    
    ListInterface<ItemType>* listPtr;
    
public:
    
    SortedListHasA() {
        
        listPtr = new LinkedList<ItemType>();
    }
    
    
    SortedListHasA(const SortedListHasA<ItemType>& sList) {
        
        listPtr = new LinkedList<ItemType>();
        
        for (int index = 1; index <= sList.getLength(); index++) {

            listPtr->insert(index, sList.getEntry(index));
        }
    }
    
    
    virtual ~SortedListHasA() {
        
        clear();
    }
    
    
    void insertSorted(const ItemType& newEntry) {
        
        int newPosition;
        
        if (isEmpty()) {
            
            newPosition = 1;
        }
        else {
            
            newPosition = fabs(getPosition(newEntry));
        }
        
        listPtr->insert(newPosition, newEntry);
    }
    

    bool removeSorted(const ItemType& anEntry) {
        
        int target = getPosition(anEntry);
        bool ableToRemove = target > 1;
        
        if (ableToRemove) {
            
            return listPtr->remove(target);
        }
        
        return ableToRemove;
    }
    

    int getPosition(const ItemType& anEntry) const {
 
        if (getLength() == 1) {
            
            if (getEntry(1) <= anEntry) {
                return -1;
            }
            
            return -2;
        }
        
        for (int backIndex = 1, frontIndex = backIndex + 1; backIndex <= getLength(); backIndex++, frontIndex++) {

            if (getEntry(backIndex) <= anEntry) {
                
                return backIndex;
            }
            else if (getEntry(frontIndex) == anEntry) {
                
                return frontIndex;
            }
            else if (getEntry(backIndex) > anEntry && getEntry(frontIndex) < anEntry) {
                
                return frontIndex * -1;
            }
        }
        
        return getLength() * -1;
    }

    
    bool isEmpty() const {
        
        return listPtr->isEmpty();
    }
    
    
    int getLength() const {

        return listPtr->getLength();
    }
    
    
    bool remove(int position) {
        
        return listPtr->remove(position);
    }
    
    
    void clear() {
        
        listPtr->clear();
    }
    
    
    ItemType getEntry(int position) const {
    
        return listPtr->getEntry(position);
    }
    
}; // End SortedListHasA






template <class ItemType>
class ArcadeScores : public SortedListHasA<ItemType> {
    
private:
    
    SortedListHasA<ItemType> highScores;
    
public:
    
    ArcadeScores() {
        
        highScores.insertSorted(100);
        highScores.insertSorted(300);
        highScores.insertSorted(200);
        highScores.insertSorted(400);
        highScores.insertSorted(500);
    }
    
    
    ~ArcadeScores() {
        
        clear();
    }
    
    
    void displayScores() {
        
        for (int index = 1; index <= highScores.getLength(); index++) {
            
            cout << highScores.getEntry(index) << endl;
        }
        
        cout << endl;
    }
    
    
    void insertSorted(const ItemType& newEntry) {

        highScores.insertSorted(newEntry);
    }
    
    
    void clear() {
        
        highScores.clear();
    }
    
}; // End ArcadeScores






int main(int argc, const char * argv[]) {

    ArcadeScores<int> highScoreList;

    bool continueAdding = false;
    int newScore;
    
    do {
        
        cout << "Current high scores are: " << endl;
        highScoreList.displayScores();
        
        cout << "Enter a new high score, or a negative value to exit: ";
        while (cin.fail()) {
            
            cin.clear();
            cin.ignore();
            cout << "\nInvalid input..." << endl;
            cout << "Enter a new high score, or a negative value to exit: ";
        }
        
        cin >> newScore;
        
        if (newScore < 0) {

            continueAdding = false;
        }
        else {

            highScoreList.insertSorted(newScore);
            continueAdding = true;
        }
        
    } while (continueAdding);
    
    cout << "Finished.\nHigh scores are: " << endl;
    highScoreList.displayScores();
    cout << "Exiting..." << endl;
    
    return 0;
}
