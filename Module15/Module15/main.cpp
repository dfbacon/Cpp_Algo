//
//  Name: Daniel Bacon
//  Assignment: Module 15 - Custom Dictionary
//

#include <iostream>
#include <string>

using namespace std;
/*
 
 For this assignment, you will implement a dictionary to track the name and
    birthday of your friends and relatives.  You should be able to do the
    following operations:
 
    add an entry
    remove an entry
    search the dictionary for the birthday for a given name
    display the name and birthday of every entry in the dictionary
    list everyone in the dictionary who was born in a given month
    The search key is the name, and you may assume that the names are unique.
 
 Design and implement a C++ class to represent a person, which contains a name
    and a birthday at minimum.  Additionally, design and implement a C++ class
    to represent an ADT Dictionary of Person objects.  Do not use an existing
    library class for the dictionary, you must implement your own.
 
 Searching for a person in your dictionary must be an average-case O(log n)
    operation; adding and removing can be O(n); and the "list everyone who was
    born in a given month" operation can be an O(n) operation.  With these
    requirements in mind, it is up to you which type of dictionary to use.
    You are free to leverage any work done in previous assignments.
 
 You may create an interactive program which supports all of the required
    operations, or you may hard-code a sequence of operations that fully
    demonstrates your dictionary.
 
 */


template <class ItemType>
class Node {
    
private:
    ItemType data;
    Node<ItemType>* leftChild;
    Node<ItemType>* rightChild;
    
    
public:
    Node() : data(NULL), leftChild(nullptr), rightChild(nullptr) {}
    
    Node(const ItemType& newData) : data(newData), leftChild(nullptr),
        rightChild(nullptr) {}
    
    Node(const ItemType& newData, Node<ItemType>* left, Node<ItemType>* right) :
        data(newData), leftChild(left), rightChild(right) {}
    
    ItemType getData() const {
        
        return data;
    }
    
    void setData(const ItemType& newData) {
        
        data = newData;
    }
    
    Node<ItemType>* getLeftChild() const {
    
        return leftChild;
    }
    
    Node<ItemType>* getRightChild() const {
        
        return rightChild;
    }
    
    void setLeftChild(Node<ItemType>* left) {
    
        leftChild = left;
    }
    
    void setRightChild(Node<ItemType>* right) {
        
        rightChild = right;
    }
    
    bool hasLeftChild() {
        
        return leftChild != nullptr;
    }
    
    bool hasRightChild() {
        
        return rightChild != nullptr;
    }
    
    bool isLeaf() {
        
        return leftChild == nullptr && rightChild == nullptr;
    }
};




template <class ItemType>
class Person {

private:
    string name;
    int day;
    int month;
    int year;
    
public:
    Person(const string newName) : name(newName), day(0), month(0), year(0) {}
    
    Person(const string newName, const int newDay, const int newMonth,
           const int newYear) : name(newName), day(newDay), month(newMonth),
            year(newYear) {}
    
    string getName() const {
        
        return name;
    }
    
    void setName(const string newName) {
        
        name = newName;
    }
    
    int getDay() const {
        
        return day;
    }
    
    void setDay(const int newDay) {
        
        day = newDay;
    }
    
    int getMonth() const {
        
        return month;
    }
    
    void setMonth(const int newMonth) {
        
        month = newMonth;
    }
    
    int getYear() const {
        
        return year;
    }
    
    void setYear(const int newYear) {
        
        year = newYear;
    }
};





template <class ItemType>
class DictionaryOfPerson {
    
private:
    Node<ItemType>* root;
    
    
protected:
    int getHeightHelper(Node<ItemType>* subTreePtr) const {
        
        if (subTreePtr == nullptr) {
            
            return 0;
            
        } else {
            
            return 1 + max(getHeightHelper(subTreePtr->getLeftChild()),
                           getHeightHelper(subTreePtr->getRightChild()));
        }
    }
    
    Node<ItemType>* balancedAdd(Node<ItemType>* subTreePtr,
                                Node<ItemType>* newNode) {
        
        if (subTreePtr == nullptr) {
            
            return newNode;
            
        } else {
            
            Node<ItemType>* left = subTreePtr->getLeftChild();
            Node<ItemType>* right = subTreePtr->getRightChild();
            
            if (getHeightHelper(left) > getHeightHelper(right)) {
                
                right = balancedAdd(right , newNode);
                subTreePtr->setRightChild(right );
                
            } else {
                
                left = balancedAdd(left, newNode);
                subTreePtr->setLeftChild(left);
            }
            
            return subTreePtr;
        }
    }
    
    void destroyTree(Node<ItemType>* subTreePtr) {
        
        if (subTreePtr != nullptr) {
            
            destroyTree(subTreePtr->getLeftChild());
            destroyTree(subTreePtr->getRightChild());
            
            delete subTreePtr;
        }
    }
    
    Node<ItemType>* findEntry(Node<ItemType>* currentNode, ItemType anEntry) {
        
        Node<ItemType> result = nullptr;
        
        if (currentNode != nullptr) {
            
            ItemType currentEntry = currentNode->getData();
            
            if (anEntry.compare(currentEntry->name) == 0) {
                
                result = currentNode;
                
            } else if (anEntry.compare(currentEntry->name) < 0) {
                
                result = findEntry(currentNode->getLeftChild(), anEntry);
                
            } else {
                
                result = findEntry(currentNode->getRightChild(), anEntry);
            }
        }
        
        return result;
    }
    
    Node<ItemType>* copyTree(const Node<ItemType>* currentTree) const {
        
        Node<ItemType>* newTree = nullptr;
        
        if (currentTree != nullptr) {
            
            newTree = new Node<ItemType>(currentTree->getItem(), nullptr, nullptr);
            newTree->setLeftChild(copyTree(currentTree->getLeftChild()));
            newTree->setRightChild(copyTree(currentTree->getRightChild()));
        }
        
        return newTree;
    }
    
    void inorder(void visit(ItemType&), Node<ItemType>* treePtr) const {
        
        if (treePtr != nullptr) {
            
            inorder(visit, treePtr->getLeftChildPtr());
            ItemType theItem = treePtr->getItem();
            visit(theItem);
            inorder(visit, treePtr->getRightChildPtr());
        }
    }
    
    // TODO
    Node<ItemType>* removeValue(Node<ItemType>* subTreePtr,
                                const ItemType target, bool& success);
    Node<ItemType>* moveValuesUpTree(Node<ItemType>* subTreePtr);
    
    
public:
    DictionaryOfPerson() : root(nullptr) {}
    
    DictionaryOfPerson(const ItemType& rootItem) {
        
        root = new Node<ItemType>(rootItem, nullptr, nullptr);
    }
    
    DictionaryOfPerson(const ItemType& rootItem,
                     const DictionaryOfPerson<ItemType>* leftTreePtr,
                     const DictionaryOfPerson<ItemType>* rightTreePtr) {
        
        root = new Node<ItemType>(rootItem, copyTree(leftTreePtr->root),
                                  copyTree(rightTreePtr->root));
    }
    
    DictionaryOfPerson(const DictionaryOfPerson<ItemType>& tree) {
        
        root = copyTree(tree.root);
    }
    
    ~DictionaryOfPerson() {
        
        destroyTree(root);
    }
    
    bool isEmpty() const {
        
        return root == nullptr;
    }
    
    void add(const ItemType& newData) {
        
        Node<ItemType>* newNode = new Node<ItemType>(newData);
        root = balancedAdd(root, newNode);
    }
    
    // TODO
    bool remove(const ItemType& data);
    
    ItemType getEntry(const ItemType& anEntry) const {
        
        return findEntry(root, anEntry);
    }
    
    void inorderTraverse(void visit(ItemType&)) const {
        
        inorder(visit, root);
    }
};





int main(int argc, const char * argv[]) {

    return 0;
}
