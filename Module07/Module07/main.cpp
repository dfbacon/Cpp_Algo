//
//  Name: Daniel Bacon
//  Assignment: Module07 - Programming Problems 2 and 3
//
//

#include <iostream>
#include <cassert>
using namespace std;

template < class ItemType>
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
class ArrayList : public ListInterface<ItemType> {
    private :
        static const int DEFAULT_CAPACITY = 10;
        ItemType* items;
        int itemCount;
        int maxItems;
    
        /**
         Doubles the capacity of the list.
         @pre The list is full.
         @post The list cpacity has doubled but it retained all its elements in
         order.
        */
        void increaseCapacity() {
            ItemType* newItems = NULL;
            int tempItemCount = itemCount;
            
            // Uncomment for testing.
            /*
            cout << "Expanding..." << endl;
            cout << "List size before expansion: " << maxItems << endl;
            cout << "items location before expansions: " << &items[0] << endl;
             */
            
            maxItems *= 2;
            newItems = new ItemType[maxItems];
            
            for (int index = 0; index < itemCount; index++) {
                newItems[index] = items[index];
            }

            clear();
            delete [] items;

            items = newItems;
            itemCount = tempItemCount;
            
            // Uncomment for testing.
            /*
            cout << "List size after expansion: " << maxItems << endl;
            cout << "items location after expansion (should be different" <<
                " than original address): " << &items[0] << endl;
             */
            
            newItems = nullptr;
            delete newItems;
            newItems = NULL;
        }
    
        /**
         Reduces the capacity of the list by 3/4.
         @pre: The list capacity is greater than 20 and the number of items is
         less than half of the total capacity.
         @post the list capacity has been reduced to 3/4 size with all elements
         retained in order.
        */
        void decreaseCapacity() {
            ItemType* reducedItems = NULL;
            int tempItemCount = itemCount;
            
            // Uncomment for testing.
            /*
            cout << "Contracting..." << endl;
            cout << "List size before contraction: " << maxItems << endl;
            cout << "items location before contraction: " << &items[0] << endl;
             */
            
            maxItems *= 0.75;
            reducedItems = new ItemType[maxItems];
            
            for (int index = 0; index < itemCount; index++) {
                reducedItems[index] = items[index];
            }
            
            clear();
            delete [] items;
            
            items = reducedItems;
            itemCount = tempItemCount;
            
            // Uncomment for testing.
            /*
            cout << "List size after contraction: " << maxItems << endl;
            cout << "items location after contraction (should be different" <<
            " than original address): " << &items[0] << endl;
             */
            
            reducedItems = nullptr;
            delete reducedItems;
            reducedItems = NULL;
        }
    
    public :
        ArrayList() : itemCount(0), maxItems(DEFAULT_CAPACITY) {
            items = new ItemType[maxItems];
        }

        ~ArrayList() {
            clear();
            maxItems = 0;
            delete [] items;
        }
    
        bool isEmpty() const {
            return itemCount == 0;
        }
    
        int getLength() const {
            return itemCount;
        }
    
        bool insert( int newPosition, const ItemType& newEntry) {
            bool ableToInsert = (newPosition >= 1) && (newPosition <=
                                                       itemCount + 1);
            
            if (ableToInsert && (itemCount == maxItems)) {
                increaseCapacity();
            }
            
            if (ableToInsert) {
                for ( int pos = itemCount; pos >= newPosition; pos--)
                    items[pos] = items[pos - 1];

                items[newPosition - 1] = newEntry;
                itemCount++;
            }
            
            return ableToInsert;
        }
    
        bool remove(int position) {
            bool ableToRemove = (position >= 1) && (position <= itemCount);
            
            if (ableToRemove) {
                for (int fromIndex = position, toIndex = fromIndex - 1;
                     fromIndex < itemCount; fromIndex++, toIndex++) {
                    items[toIndex] = items[fromIndex];
                }
                
                itemCount--;
            }
            
            if (maxItems > 20) {
                if (itemCount < (maxItems / 2)) {
                    decreaseCapacity();
                }
            }
            
            return ableToRemove;
        }

        void clear() {
            for (int index = 0; index < maxItems; index++) {
                items[index] = NULL;
            }
            
            itemCount = 0;
        }
    
        ItemType getEntry(int position) const {
            bool ableToGet = (position >= 1) && (position <= itemCount);
                if (ableToGet) {
                    return items[position - 1];
                }
                else {
                    return NULL;
                }
        }
    
        void setEntry( int position, const ItemType& newEntry) {
            bool ableToSet = (position >= 1) && (position <= itemCount);
            
            if (ableToSet) {
                items[position - 1] = newEntry;
            }
        }
};






int main(int argc, const char * argv[]) {
    ArrayList<int> intList;
    
    /*
     To view expansion and contraction of intList, uncomment lines in
     increaseCapacity() and decreaseCapacity(), respectively.
     */
    
    cout << "List is empty. Should be 1 : " << intList.isEmpty() << endl;
    
    for (int i = 1; i < 25; i++) {
        intList.insert(i, i);
    }

    if (!intList.isEmpty()) {
        cout << "Entries added." << endl;
        cout << "First entry should be 1 : " << intList.getEntry(1) << endl;
        intList.setEntry(1, 100);
        cout << "Change first entry to 100 : " << intList.getEntry(1) << endl;
        
        cout << "Before removal, list size is 24 : " << intList.getLength() << endl;
        if (intList.remove(1)) {
            cout << "Removed first entry. List size should be 23 : " <<
                intList.getLength() << endl;
        }
        
        intList.insert(1000, 777);
        cout << "Inserting new element outside of array bounds. List size " <<
            "should still be 23 : " << intList.getLength() << endl;
        
        intList.remove(1000);
        cout << "Removing outside of array bounds. List size " <<
            "should still be 23 : " << intList.getLength() << endl;
    
        cout << "Removing multiple items..." << endl;
        for (int i = 24; i > 12; i--) {
            intList.remove(i);
        }

        cout << "List size should be 12 : " << intList.getLength() << endl;
        
        cout << "Clearing list..." << endl;
        intList.clear();
    }
    
    cout << "List size should be 0 : " << intList.getLength() << endl;

    return 0;
}
