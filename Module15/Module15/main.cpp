//
//  Name: Daniel Bacon
//  Assignment: Module 15 - Custom Dictionary
//

#include <iostream>
#include <iomanip>
#include <vector>
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

class Person {
    
private:
    string name;
    int day;
    int month;
    int year;
    
public:
    Person() : name("empty"), day(0), month(0), year(0) {}
    
    Person(const string newName) : name(newName), day(0), month(0), year(0) {}
    
    Person(const string newName, const int newDay, const int newMonth,
           const int newYear) : name(newName), day(newDay), month(newMonth),
    year(newYear) {}
    
    Person(const Person& existingPerson) {
        
        name = existingPerson.getName();
        day = existingPerson.getDay();
        month = existingPerson.getMonth();
        year = existingPerson.getYear();
    }
    
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
    
    void printBirthday() {
        
        cout << setfill('0') << setw(2) << month << "/" << setfill('0') <<
        setw(2) << day << "/" << setw(4) << year << endl;
    }
};





class DictionaryOfPersons {

private:
    vector<Person*> priorityQueue;
    int size;
    int MINIMUM_NUMBER_ELEMENTS = 10;
    
protected:
    void bubbleUp(int index) {}
//    void trickleDown(int index);
//    int getMinimumIndex(int firstIndex, int secondIndex, int thirdIndex);
    
public:
    DictionaryOfPersons() : priorityQueue(NULL), size(0) {}
    
    bool isEmpty() const {
        
        return size == 0;
    }
    
    int getSize() const {
        
        return size;
    }

    
    Person* getItem(const int index) const {

        return priorityQueue[index];
    }
    
//    int hasParent(const int index) const;
//    int hasChild(const int index) const;
//    int getIndex(const int index, const string value) const;
    void insert(Person* newValue) {

        priorityQueue.push_back(newValue);
        size++;
        bubbleUp(size);
    }
//    void remove(Person* targetValue);
//    void heapify(std::vector<Person>& input);
//    Person& dequeue();
//    vector<ItemType> heapSort();
    
    void checkContents() const {
        for (int i = 0; i < size; i++) {
            priorityQueue[i]->printBirthday();
        }
    }
};





int main(int argc, const char * argv[]) {

    Person Daniel("Daniel", 5, 1, 1988);

    cout << Daniel.getName() << endl;
    cout << &Daniel << endl;

    DictionaryOfPersons newDict;
    cout << newDict.getSize() << "\n";

    newDict.insert(&Daniel);
    
    cout << newDict.getSize() << endl;
    
    newDict.getItem(0)->printBirthday();
    cout << newDict.getItem(newDict.getSize() - 1)->getName() << endl;

    return 0;
}
