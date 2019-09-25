//
//  main.cpp
//  Module04 - Programming Problem #6
//
//  Created by Daniel Bacon on 9/24/19.
//  Copyright © 2019 Daniel Bacon. All rights reserved.
//

/*
 Define a class DoublyLinkedBag that implements the ADT bag by using a doubly
 linked chain, as shown in Figure 4-9. Use the class of nodes that Exercise
 10 defines.
 
 Demonstrate your double linked list implementation in a main function.
 
 Tips: Unlike the previous assignment (with arrays) we are not using integers
 as our data - but the ADT bag, which uses templates.
 
 It would be best to implement the ADT linked based implementation of bag first.
 This majority of this code is done for you in the textbook. Then simply modify
 the LinkedBag code to handle a double linked list.
 
 Key Topics

    Modification of the LinkedBag class: constructors and destructors
 
    Modification of the LinkedBag class: add and remove

    main.cpp demonstrates the initialization and destruction of a double linked
        list.
 
    main.cpp  demonstrates an addition and removal from the double linked list.
 */
#include <iostream>
#include <vector>
using namespace std;

// Node class definition.
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
    void setData(const ItemType& newData);
    void setNextPtr(Node<ItemType>* newNext);
    void setPrevPtr(Node<ItemType>* newPrev);
    ItemType getData() const;
    Node<ItemType>* getNext() const;
    Node<ItemType>* getPrev() const;
    
};


// LinkedBag class definition.
template <class ItemType>
class LinkedBag {
private:
    Node<ItemType>* head;
    int itemCount;
    Node<ItemType>* getPointerTo(const ItemType& target) const;
    
public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag);
    virtual ~LinkedBag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const ;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
};




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
    nextNode = nullptr;
    prevNode = nullptr;
}


template <class ItemType>
void Node<ItemType>::setData(const ItemType& newData) {
    data = newData;
}


template <class ItemType>
void Node<ItemType>::setNextPtr(Node<ItemType>* newNext) {
    nextNode = newNext;
}


template<class ItemType>
void Node<ItemType>::setPrevPtr(Node<ItemType>* newPrev) {
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


template <class ItemType>
LinkedBag<ItemType>::LinkedBag() : head(nullptr), itemCount(0) {}


template <class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {}


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
        newNode->setNextPtr(head);
        head->setPrevPtr(newNode);
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
        
        nodeToDelete->setNextPtr(nullptr);
        nodeToDelete->setPrevPtr(nullptr);
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

        nodeToDelete->setNextPtr(nullptr);
        nodeToDelete->setPrevPtr(nullptr);
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







void displayBag(LinkedBag<string>& bag) {
    cout << "The bag contains " << bag.getCurrentSize() << " items:" << endl;
    
    vector<string> bagItems = bag.toVector();
    int numberOfEntries = (int)bagItems.size();
    
    for (int i = 0; i < numberOfEntries; i++) {
        cout << bagItems[i] << " ";
    }
    
    cout << endl << endl;
}


void bagTester(LinkedBag<string>& bag) {
    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)" << endl;
    displayBag(bag);

    string items[] = {"one", "two", "three", "four", "five", "one"};
    cout << "Add 6 items to the bag: " << endl;

    for (int i = 0; i < 6; i++) {
        bag.add(items[i]);
    }

    displayBag(bag);

    cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)" << endl;
    cout << "getCurrentSize: returns " << bag.getCurrentSize() << "; should be 6" << endl;
    cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << endl;
    
    cout << "Testing frequency, should be 2: " << bag.getFrequencyOf("one") << endl;
   
    cout << "Testing contains, should be true (1): " << bag.contains("two") << endl;
    cout << "Testing contains, should be false (0): " << bag.contains("nine") << endl;
    
    cout << "Testing remove, should be true (1): " << bag.remove("three") << endl;
    cout << "Testing remove, should be false (0): " << bag.remove("three") << endl;
    
    bag.clear();
    cout << "Testing clear, should be 0: " << bag.getCurrentSize() << endl;
}


int main(int argc, const char * argv[]) {
    LinkedBag<string> bag;
    cout << "Testing the Linked-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    cout << "All done!" << endl;
    return 0;
}
