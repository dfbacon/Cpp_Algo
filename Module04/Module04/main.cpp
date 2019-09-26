//
//  Name: Daniel Bacon
//  Class: Node, LinkedBag
//  Assignment: Module04 - Programming Problem #6
//

#include <iostream>
#include <vector>
using namespace std;

/*
    Node class
 */
template <class ItemType>
class Node {

private:
    ItemType data;
    Node<ItemType>* nextNode;
    Node<ItemType>* prevNode;
    
public:
    Node();
    Node(const ItemType& newData);
    Node(const ItemType& newData, Node<ItemType>* newNextPtr, Node<ItemType>* newPrevPtr);
    virtual ~Node();
    
    /**
        Sets the data variable.
     
        @param newData Memory location of new data value.
     */
    void setData(const ItemType& newData);
    
    
    /**
        Sets the nextNode variable.
     
        @param newNext Pointer to next node.
     */
    void setNext(Node<ItemType>* newNext);
    
    
    /**
        Sets the prevNode variable.
     
        @param newPrev Pointer to previous node.
     */
    void setPrev(Node<ItemType>* newPrev);
    
    
    /**
        Retrieves the value of the data variable.
     
        @return The data value.
     */
    ItemType getData() const;
    
    
    /**
        Retrieves the value of the nextNode variable.
     
        @return Pointer to the next node.
     */
    Node<ItemType>* getNext() const;
    
    
    /**
        Retrieves the value of the prevNode variable.
     
        @return Pointer to the previous node.
     */
    Node<ItemType>* getPrev() const;
};



/*
    LinkedBag class.
 */
template <class ItemType>
class LinkedBag {
private:
    Node<ItemType>* head;
    int itemCount;
    
    /**
        Retrieves a pointer to Node.
     
        @param target Location of data value to search for.
        @return Pointer to Node with corresponding data value.
     */
    Node<ItemType>* getPointerTo(const ItemType& target) const;
    
public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag);
    virtual ~LinkedBag();
    
    
    /**
        Retrieves the number of elements in the bag.
     
        @return The number of elements in the bag.
     */
    int getCurrentSize() const;
    
    
    /**
        Determines if the bag is empty.
     
        @return true if the bag has at least one element, false otherwise.
     */
    bool isEmpty() const;
    
    
    /**
        Adds a new element to the bag.
     
        @param newEntry Location of the new data value to add.
        @return true if element was added, false otherwise.
     */
    bool add(const ItemType& newEntry);
    
    
    /**
        Removes an existing element from the bag.
     
        @param anEntry Location of data value to remove.
        @return true if element was located and removed, false otherwise.
     */
    bool remove(const ItemType& anEntry);
    
    
    /**
        Removes all elements from the bag.
     */
    void clear();
    
    
    /**
        Determines if an element is in the bag.
     
        @param anEntry Location of data value to search for.
        @return true if the element was found, false otherwise.
     */
    bool contains(const ItemType& anEntry) const;
    
    
    /**
        Determines how many times an element appares in the bag.
     
        @param anEntry Location of data value to search for.
        @return The number of times a given element occurs in the bag.
     */
    int getFrequencyOf(const ItemType& anEntry) const;
    
    
    /**
        Converts the bag to a vector.
     
        @return Vector version of the bag.
     */
    vector<ItemType> toVector() const;
};



/*
    Node method definitions.
 */

template <class ItemType>
Node<ItemType>::Node() : nextNode(nullptr), prevNode(nullptr) {}


template <class ItemType>
Node<ItemType>::Node(const ItemType& newData) : data(newData), nextNode(nullptr), prevNode(nullptr) {}


template <class ItemType>
Node<ItemType>::Node(const ItemType& newData, Node<ItemType>* newNextPtr,
                     Node<ItemType>* newPrevPtr) : data(newData), nextNode(newNextPtr), prevNode(newPrevPtr){}


template <class ItemType>
Node<ItemType>::~Node() {
    delete(nextNode);
    delete(prevNode);
}


template <class ItemType>
void Node<ItemType>::setData(const ItemType& newData) {
    data = newData;
}


template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* newNext) {
    nextNode = newNext;
}


template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* newPrev) {
    prevNode = newPrev;
}


template <class ItemType>
ItemType Node<ItemType>::getData() const {
    return data;
}


template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
    return nextNode;
}


template <class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const {
    return prevNode;
}



/*
    LinkedBag method definitions.
 */

template <class ItemType>
LinkedBag<ItemType>::LinkedBag() : head(nullptr), itemCount(0) {}



template <class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& originalBag) {
    itemCount = originalBag.itemCount;
    Node<ItemType>* originalHead = originalBag.head;
    
    if (originalHead == nullptr ) {
        head = nullptr ;
    }
    
    else {
        head = new Node<ItemType>();
        Node<ItemType>* newHead = head;
        newHead->setData(originalHead->getData());

        while (originalHead->getNext() != nullptr) {
            originalHead = originalHead->getNext();

            ItemType nextItem = originalHead->getData();
            Node<ItemType>* newNode = new Node<ItemType>(originalHead->getData());

            newHead->setNext(newNode);
            newNode->setPrev(newHead);

            newHead = newHead->getNext();
        }
    }
}



template <class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}



template <class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const {
    bool found = false ;
    Node<ItemType>* current = head;
    
    while (!found && (current != nullptr)) {
        if (target == current->getData()) {
            found = true ;
        }
        
        else {
            current = current->getNext();
        }
    }
    
    return current;
}



template <class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}



template <class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}



template <class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
    Node<ItemType>* newNode = new Node<ItemType>();
    
    newNode->setData(newEntry);
    
    if (head != nullptr) {
        newNode->setNext(head);
        head->setPrev(newNode);
    }

    head = newNode;
    
    itemCount++;
    
    return true ;
}



template <class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* targetNode = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (targetNode != nullptr);
    
    if (canRemoveItem) {
        targetNode->setData(head->getData());
        
        Node<ItemType>* nodeToDelete = head;
        head = head->getNext();
        
        nodeToDelete->setNext(nullptr);
        nodeToDelete->setPrev(nullptr);
        delete nodeToDelete;
        nodeToDelete = nullptr;
        
        itemCount--;
    }
    
    return canRemoveItem;
}



template <class ItemType>
void LinkedBag<ItemType>::clear() {
    while (head != nullptr) {
        Node<ItemType>* nodeToDelete = head;
        head = head->getNext();

        nodeToDelete->setNext(nullptr);
        nodeToDelete->setPrev(nullptr);
        delete nodeToDelete;
        nodeToDelete = nullptr;
    }
    
    itemCount = 0;
}



template <class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}



template <class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0, counter = 0;
    Node<ItemType>* current = head;
    
    while ((current != nullptr) && (counter < itemCount)) {
        if (anEntry == current->getData()) {
            frequency++;
        }
        
        counter ++;
        current = current->getNext();
    }
    
    return frequency;
}



template < class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const {
    vector<ItemType> bagContents;
    Node<ItemType>* current = head;
    int counter = 0;
    
    while ((current != nullptr) && (counter < itemCount)) {
        bagContents.push_back(current->getData());
        current = current->getNext();
        counter++;
    }
    
    return bagContents;
}



/*
    Testing methods.
 */


/**
    Displays the contents of a LinkedBag object.
 
    @param bag Location of LinkedBag of strings.
 */
void displayBag(LinkedBag<string>& bag) {
    cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
    
    vector<string> bagItems = bag.toVector();
    int numberOfEntries = (int)bagItems.size();
    
    for (int i = 0; i < numberOfEntries; i++) {
        cout << bagItems[i] << " ";
    }
    
    cout << endl << endl;
}


/**
    Test method for a LinkedBag object.
 
    @param bag Location of a LinkedBag of strings.
 */
void bagTester(LinkedBag<string>& bag) {
    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
    displayBag(bag);

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the bag: " << endl;

    for (int i = 0; i < 6; i++) {
        bag.add(items[i]);
    }

    displayBag(bag);
    
    LinkedBag<string> copyBag(bag);
    
    cout << "Testing copy constructor, should print same as above:" << endl;
    displayBag(copyBag);
    
    copyBag.~LinkedBag();
    cout << "Copied bag destroyed. Should be 0: " << copyBag.getCurrentSize() << endl;

    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;
    
    displayBag(bag);
    
    cout << "Testing frequency, should be 2: " << bag.getFrequencyOf("one") << endl;
   
    cout << "Testing contains, should be true (1): " << bag.contains("two") << endl;
    cout << "Testing contains, should be false (0): " << bag.contains("nine") << endl;
    
    cout << "Testing remove, should be true (1): " << bag.remove("three") << endl;
    cout << "Testing remove, should be false (0): " << bag.remove("three") << endl;
    
    bag.clear();
    cout << "Testing clear, should be 0: " << bag.getCurrentSize() << endl;
    
}


/**
    Driver.
 */
int main(int argc, const char * argv[]) {
    LinkedBag<string> bag;
    cout << "Testing the Linked-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    cout << "All done!" << endl;
    return 0;
}
