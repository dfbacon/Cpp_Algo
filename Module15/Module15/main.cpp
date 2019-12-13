//
//  Name: Daniel Bacon
//  Assignment: Module 15 - Custom Dictionary
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

/**
 Person class. Represents a person with a name and a birthday.
 */
class Person {
private:
    string name;
    int day;
    int month;
    int year;
    
public:
    Person() : name(""), day(0), month(0), year(0) {}
    
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
    
    
    /**
     Gets the name value.
     @return Name of the Person.
     */
    string getName() const {
        
        return name;
    }
    
    
    /**
     Sets the name value.
     @param newName The new name of the Person.
     */
    void setName(const string newName) {
        
        name = newName;
    }
    
    
    /**
     Gets the day value.
     @return Day of Person's birth.
     */
    int getDay() const {
        
        return day;
    }
    
    
    /**
     Sets the day value.
     @param newDay The new day of birth.
     */
    void setDay(const int newDay) {
        
        day = newDay;
    }
    
    
    /**
     Gets the month value.
     @return Month of the Person's birth.
     */
    int getMonth() const {
        
        return month;
    }
    
    
    /**
     Sets the month value.
     @param newMonth The new month of birth.
     */
    void setMonth(const int newMonth) {
        
        month = newMonth;
    }
    
    
    /**
     Gets the year value.
     @return Year of Person's birth.
     */
    int getYear() const {
        
        return year;
    }
    
    
    /**
     Sets the year value.
     @param newYear The new year of birth.
     */
    void setYear(const int newYear) {
        
        year = newYear;
    }
    
    
    /**
     Prints a string format of Person's birthday in format MM/DD/YYYY.
     */
    void printBirthday() {
        
        cout << setfill('0') << setw(2) << month << "/" << setfill('0') <<
        setw(2) << day << "/" << setw(4) << year << endl;
    }
};




/**
 DictionaryOfPersons class. Acts as storage device for Person objects. Indexes
    from 1. Utilizes an array-based implementation of a min heap.
 */
class DictionaryOfPersons {
private:
    vector<Person*> priorityQueue;
    int size;
    Person BLANK; // Blank entry to stub at the front of priorityQueue
    
protected:
    
    /**
     Compares values and moves them up according to Person's name value.
     @param index The index of priorityQueue being evaluated.
     */
    void bubbleUp(int index) {
        
        int parentIndex = hasParent(index);

        if (parentIndex == -1) {
         
            return;
        }
        
        if (priorityQueue[parentIndex]->getName().compare(priorityQueue[index]->getName()) > 0) {

            swap(priorityQueue[parentIndex], priorityQueue[index]);
            bubbleUp(parentIndex);
        }
    }
    
    
    /**
     Compares values and moves them down according to Person's name value.
     @param index The index of priorityQueue being evaluated.
     */
    void trickleDown(int index) {
        
        int childIndex = hasChild(index);
        
        if (childIndex == -1) {
            
            return;
        }
        
        int minIndex = getMinimumIndex(index, childIndex, childIndex + 1);
        
        if (minIndex != index) {
            
            swap(priorityQueue[minIndex], priorityQueue[index]);
            trickleDown(minIndex);
        }
    }
    
    
    /**
     Determines the smallest name value of the three given Persons.
     @pre size of priorityQueue must be greater than 3.
     @param firstIndex One of the Person objects.
     @param secondIndex One of the Person objects.
     @param thirdIndex One of the Person objects.
     @return The smallest index of the three given indexes.
     */
    int getMinimumIndex(int firstIndex, int secondIndex, int thirdIndex) {
        
        bool isLeftSmaller = (priorityQueue[firstIndex]->getName() <
                              priorityQueue[secondIndex]->getName());
        
        if (thirdIndex > (int) size) {
            
            return isLeftSmaller ? firstIndex : secondIndex;
            
        } else if (isLeftSmaller) {
            
            return (priorityQueue[firstIndex]->getName() <
                    priorityQueue[thirdIndex]->getName()) ? firstIndex : thirdIndex;
            
        } else {
            
            return (priorityQueue[secondIndex]->getName() <
                    priorityQueue[thirdIndex]->getName()) ? secondIndex : thirdIndex;
        }
    }
    
    
    /**
     Determines if a given index has a parent index.
     @pre Size of priorityQueue is greater than 0.
     @param index The index being examined for a parent.
     @return The index of the parent if exists, -1 otherwise.
     */
    int hasParent(const int index) const {
        if (size <= 1) {
            
            return -1;
        }
        
        return ((int) index / 2);
    }
    
    
    /**
     Determines if a given index has a child index.
     @pre Size of priorityQueue is greater than 0; @index must be less than the
        size of priorityQueue.
     @param index The index being examined for a child.
     @return The index of the child if exists, -1 otherwise.
     */
    int hasChild(const int index) const {
        
        if (size <= 1 || 2 * index > size) {
            
            return -1;
        }
        
        return (2 * index);
    }
    
    
    /**
     Finds the index of a Person with a given name.
     @param index The index to begin searching from.
     @param value The name being searched for.
     @return The index of the Person with @name, -1 if not found.
     */
    int getIndex(const int index, const string value) const {
        
        if (index > size || value.compare(priorityQueue[index]->getName()) < 0) {
            
            return -1;
            
        } else if (value.compare(priorityQueue[index]->getName()) == 0) {
            
            return index;
        }
        
        int childIndex = hasChild(index);
        int i = -1;
        
        if (childIndex != -1) {
            
            i = max(getIndex(childIndex, value), getIndex(childIndex + 1, value));
        }
        
        return i;
    }
    
    
    /**
     Prints out names and birthdays of all Persons in priorityQueue.
     */
    void getAllData() const {

        for (int index = 1; index <= size; index++) {

            cout << priorityQueue[index]->getName() << endl;
            priorityQueue[index]->printBirthday();
            cout << endl;
        }
    }
    
    
    /**
     Prints out all names of Persons born in a given month.
     @param targetMonth The month being evaluated.
     */
    void getBirthdayByMonth(const int targetMonth) {
        
        for (int index = 1; index <= size; index++) {
            
            if (priorityQueue[index]->getMonth() == targetMonth) {
                
                cout << priorityQueue[index]->getName() << endl;
            }
        }
        
        cout << endl;
    }

public:
    DictionaryOfPersons() : priorityQueue(1, &BLANK), size(0) {}
    
    ~DictionaryOfPersons() {
        
        priorityQueue.clear();
    }
    
    
    /**
     Determines if the priorityQueue is empty.
     @return true if priorityQueue is empty, false otherwise.
     */
    bool isEmpty() const {
        
        return size == 0;
    }
    
    
    /**
     Gets the number of entries being stored.
     @return The number of entries in priorityQueue
     */
    int getSize() const {
        
        return size;
    }
    
    
    /**
     Removes all entries.
     @post All entries removed, stub replaced for priorityQueue re-use.
     */
    void clear() {
        
        priorityQueue.clear();
        priorityQueue.push_back(&BLANK);
        size = 0;
    }

    
    /**
     Gets the Person data from a given index.
     @pre The priorityQueue must not be empty.
     @param index The index being retrieved.
     @return Pointer to the Person data if present, nullptr otherwise.
     */
    Person* getItem(const int index) const {

        if (!isEmpty()) {
            
            return priorityQueue[index];
        }
        
        return nullptr;
    }
    
    
    /**
     Adds a Person to the priorityQueue.
     @post A new Person has been added.
     @param newValue The Person being added.
     */
    void insert(Person* newValue) {
        
        priorityQueue.push_back(newValue);
        size++;
        bubbleUp(size);
    }
    
    
    /**
     Removes a Person from the priorityQueue.
     @pre The Person exists in the priorityQueue.
     @post The Person has been removed.
     */
    void remove(Person* targetValue) {
        
        int index = getIndex(1, targetValue->getName());
        
        if (index == -1) {
         
            return;
        }
        
        priorityQueue[index] = priorityQueue[size--];
        priorityQueue.resize(size + 1);
        trickleDown(index);
        bubbleUp(index);
    }
    
    
    /**
     Retrieves and prints the birthday of a Person with a given name.
     @pre The priorityQueue is not empty.
     */
    void findBirthday(Person* personName) {
        
        if (!isEmpty()) {
            int index = getIndex(1, personName->getName());
            
            if (index > 0) {
                
                priorityQueue[index]->printBirthday();
                return;
            }
        }
        
        cout << "Person not found." << endl;
    }
    
    
    /**
     Outputs all birthdays to the console.
     */
    void displayAllBirthdays() {

        getAllData();
    }
    
    
    /**
     Displays all the birthdays for a given month.
     @param targetMonth The month being evaluated.
     */
    void displayBirthdaysForMonth(const int targetMonth) {
        
        getBirthdayByMonth(targetMonth);
    }
};





int main(int argc, const char * argv[]) {

    Person Daniel("Daniel", 5, 1, 1988);
    Person Marisa("Marisa", 10, 10, 1988);
    Person Nathaniel("Nathaniel", 14, 7, 2017);
    Person Susan("Susan", 14, 12, 1958);
    Person Aaron("Aaron", 2, 4, 1971);
    Person Mark("Mark", 2, 4, 1971);
    Person James("James", 21, 5, 1991);
    
    DictionaryOfPersons newDict;
    
    newDict.insert(&Susan);
    newDict.insert(&Marisa);
    newDict.insert(&James);
    newDict.insert(&Mark);
    newDict.insert(&Nathaniel);
    newDict.insert(&Daniel);
    newDict.insert(&Aaron);

    cout << newDict.getSize() << endl;
    newDict.findBirthday(&Nathaniel);
    newDict.displayAllBirthdays();
    
    newDict.remove(&Nathaniel);
    newDict.remove(&James);
    cout << newDict.getSize() << endl;

    newDict.displayBirthdaysForMonth(1);
    newDict.displayBirthdaysForMonth(4);
    
    newDict.clear();
    newDict.findBirthday(&Nathaniel);

    return 0;
}
