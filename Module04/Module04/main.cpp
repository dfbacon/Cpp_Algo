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
    Modification of the Node class: Constructor/descructor for the new node (w/
        a next and prev pointers)
 
    Modification of the Node class: addition of setPrev and getPrev Functions

    Modification of the LinkedBag class: constructors and destructors
 
    Modification of the LinkedBag class: add and remove

    main.cpp demonstrates the initialization and destruction of a double linked
        list.
 
    main.cpp  demonstrates an addition and removal from the double linked list.
 */
#include <iostream>
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
    nextNode = nullptr;
    prevNode = nullptr;
    delete(nextNode);
    delete(prevNode);
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




int main(int argc, const char * argv[]) {

    Node<int> zeroNode(0);
    Node<int> secondNode(2);
    Node<int> firstNode(1, &secondNode, &zeroNode);
    Node<int> emptyNode;
    
    cout << firstNode.getData() << endl;
    cout << firstNode.getNext() << endl;
    cout << firstNode.getPrev() << endl;
    
    cout << zeroNode.getPrev() << endl;
    zeroNode.setNextPtr(&firstNode);
    cout << "firstNode location: " << &firstNode << endl;
    cout << zeroNode.getNext() << endl;
    
    cout << secondNode.getNext() << endl;
    
    cout << emptyNode.getData() << endl;
    
    return 0;
}
