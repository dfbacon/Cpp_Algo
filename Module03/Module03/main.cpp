/*
 Name: Daniel Bacon
 Class: Clock
 Assignment: Module 3 - Programming Problem #1.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;
/*
 Programming Problem #1
 
 Design and implement an ADT that represents the time of day. Represent the time as hours and minutes on a 24-hour clock. The hours and minutes are the private data members of the class that implements the ADT.
 
     Also include operations that set the time, increase the present time by a number of minutes, and display the time in 12-hour and 24-hour notations.
 
 Key Topics
 
 The ADT includes interfaces for set the time and increase the present time by a number of minutes.
 Users cannot impact non-interface members of the ADT.
 
 The ADT handles various time related math (e.g. increasing time by 60 minutes increases the number of hours displayed by 1).
 Correct use of initialization and constructors.
 
 The ADT correctly handles different time displays ("display the time in 12-hour and 24-hour notations.")
 */

class Clock {

private:
    static const int MAX_MINUTES = 60;
    static const int MAX_HOUR_12 = 12;
    static const int MAX_HOUR_24 = 24;
    int hours, minutes;
    bool is24;
    
    
    /** Sets the clock to 12- or 24-hour mode.
     @return Client decision on clock mode. */
    bool set24();
    
    
    /** Sets the minute value.
     @post Minute value has been updated.
     @param newMinute The new minute value. */
    void setMinutes(const int newMinute) throw(out_of_range);
    
    
    /** Sets the hour value.
     @post Hour value has been updated.
     @param newHour The new hour value. */
    void setHour(const int newHour) throw(out_of_range);
    
    
    /** Increases the hour value by a given amount.
     @post The time has been increased by the given number of hours.
     @param hoursToAdd The number of hours to add. */
    void increaseHour(const int hoursToAdd);
    
    
    /** Checks time at creation for validity. If invalid, sets to 01:00 */
    void checkTime();
    
    
public:
    Clock(int newHour = 1, int newMinute = 0) : hours(newHour), minutes(newMinute) {
        is24 = set24();
        checkTime();
    }
    
    
    /** Displays the current time in the format HH:MM. */
    void displayTime() const;
    
    
    /** Sets the time.
     @post The time has been set to the new hour and minute values.
     @param newHour The new hour value.
     @param newMinute The new minute value. */
    void setTime(const int newHour, const int newMinute);

    
    /** Adds a given number of minutes to the time.
     @post The time has been increased by the given number of minutes.
     @param minutesToAdd The number of minutes to add. */
    void addMinutes(const int minutesToAdd) throw(out_of_range);
};






bool Clock::set24() {
    string userResponse;
    
    cout << "DEFAULT NOTATION: 12 hour.\nWould you like to set clock to " <<
    "24 hour mode? (Y/N): ";
    
    cin >> userResponse;
    if (userResponse == "y" || userResponse == "Y") {
        cout << "24 hour mode set." << endl;
        return true;
    }
    
    cout << "12 hour mode set." << endl;
    return false;
}






void Clock::setMinutes(const int newMinute) throw(out_of_range){
    try {
        if (newMinute >= 0 && newMinute <= MAX_MINUTES) {
            this->minutes = newMinute;
        }
        else {
            throw out_of_range("Value must be between 0 and 60.");
        }
    }
    
    catch (out_of_range& e) {
        cout << "Minute not set: " << e.what() << endl;
        }
}
        
        
        
        
        

void Clock::setHour(const int newHour) throw(out_of_range) {
    try {
        if (is24) {
            if (newHour >= 0 && newHour < MAX_HOUR_24) {
                this->hours = newHour;
            }
            else {
                throw out_of_range("Value must be between 0 and 23.");
            }
        }
        else {
            if (newHour > 0 && newHour <= MAX_HOUR_12) {
                this->hours = newHour;
            }
            else {
                throw out_of_range("Value must be between 1 and 12.");
            }
        }
    }
    
    catch (out_of_range& e) {
        cout << "Hour not set: " << e.what() << endl;
    }
}






void Clock::checkTime() {
    if (is24) {
        if (hours < 0 || hours > MAX_HOUR_24) {
            setHour(1);
        }
    }
    else if (hours < 1 || hours > MAX_HOUR_12) {
        setHour(1);
    }
    
    if (minutes < 0 || minutes > 60) {
        setMinutes(0);
    }
}







void Clock::displayTime() const {
    cout << std::setfill('0') << std::setw(2) << hours << ":" <<
    std::setfill('0') << std::setw(2) << minutes;
}






void Clock::setTime(const int newHour, const int newMinute) {
    setHour(newHour);
    setMinutes(newMinute);
}






void Clock::addMinutes(const int minutesToAdd) throw(out_of_range){
    int reducedMinutes, hoursToAdd;
    
    try {
        if (minutesToAdd >= 0) {
            
            reducedMinutes = minutesToAdd % MAX_MINUTES;
            hoursToAdd = minutesToAdd / MAX_MINUTES;
            
            while (reducedMinutes > 0) {
                minutes += 1;
                                
                if (minutes == MAX_MINUTES) {
                    setMinutes(0);
                    hoursToAdd += 1;
                    reducedMinutes -= 1;
                }
                
                reducedMinutes -= 1;
            }
            
            if (hoursToAdd > 0) {
                increaseHour(hoursToAdd);
            }
        }
        else {
            throw out_of_range("Value can not be negative.");
        }
    } catch (out_of_range& e) {
        cout << "Clock not updated: " << e.what() << endl;
    }
}






void Clock::increaseHour(const int hoursToAdd) {
    int maxHours, addedHours = hoursToAdd;
    
    if (is24) {
        maxHours = MAX_HOUR_24;
    }
    else {
        maxHours = MAX_HOUR_12;
    }
    
    while (addedHours > maxHours) {
        addedHours /= maxHours;
    }
    
    while (addedHours > 0) {
        hours += 1;
        
        if (hours == maxHours) {
            setHour(0);
        }
        
        addedHours -= 1;
    }
}






int main(int argc, const char * argv[]) {
    Clock clock24; //24 hour
//    Clock clock12(4, 30); //12 hour


    cout << "----------------- TESTING 24 HOUR ---------------------" << endl;

    clock24.displayTime();
    cout << endl;
    
    //TESTING
    clock24.setTime(23, 0);
    clock24.displayTime();
    cout << endl;

//    clock24.setTime(11, 11);
//    cout << "new time is 11:11 : ";
//    clock24.displayTime();
//    cout << endl;

    clock24.addMinutes(60);
    cout << "Minutes added, new time is 00:00 : ";
    clock24.displayTime();
    cout << endl;

//    cout << "Error should appear." << endl;
//    clock24.setTime(25, 0);
//    cout << "new time is 11:00 : ";
//    clock24.displayTime();
//    cout << endl;
//
//    clock24.setTime(02, 67);
//    cout << "new time is 02:00 : ";
//    clock24.displayTime();
//    cout << endl;
//
//    clock24.setTime(28, 79);
//    cout << "new time is 02:00 : ";
//    clock24.displayTime();
//    cout << endl;
//
//    clock24.addMinutes(60);
//    cout << "Minutes added.\nTime should be 12:11 : ";
//    clock24.displayTime();
//    cout << endl;
//
//    clock24.addMinutes(61);
//    cout << "Minutes added.\nTime should be 13:12 : ";
//    clock24.displayTime();
//    cout << endl;
//
//    clock24.addMinutes(120);
//    cout << "Minutes added.\nTime should be 11:12 : ";
//    clock24.displayTime();
//    cout << endl;
//
//    cout << "Error should appear: ";
//    clock24.addMinutes(-1);
//    cout << endl;
//    cout << "Time should be 11:12 : ";
//    clock24.displayTime();
//    cout << endl;
    
//    cout << "\n----------------- TESTING 12 HOUR ---------------------" << endl;
//    clock12.displayTime();
//    cout << endl;
//
//    clock12.setTime(03, 16);
//    cout << "new time is 03:16 : ";
//    clock12.displayTime();
//    cout << endl;
//
//    clock12.setTime(15, 30);
//    cout << "new time is 03:30 : ";
//    clock12.displayTime();
//    cout << endl;
    
    
    return 0;
}
