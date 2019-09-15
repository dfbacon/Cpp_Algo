/*
 Name: Daniel Bacon
 Class: Clock
 Assignment: Module 3 - Programming Problem #1.
 */

#include <iostream>
#include <iomanip>
#include <string>
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

class ClockInterface {

public:
    /** Displays the current time in the format HH:MM. */
    virtual void displayTime() const = 0;
    
    /** Sets the time.
     @post The time has been set to the new hour and minute values.
     @param hours The new hour value.
     @param minutes The new minute value. */
    virtual void setTime(const int hours, const int minutes) = 0;
    
    /** Retrieves the current minute value. */
    virtual void getMinutes() const = 0;
    
    /** Adds a given number of minutes to the time.
     @post The time has been increased by the given number of minutes.
     @param minutesToAdd The number of minutes to add.
     @return The advanced minute value. */
    virtual int addMinutes(const int minutesToAdd) = 0;
    
    /** Retrieves the current hour value. */
    virtual void getHour() const = 0;
    
    /** Increases the hour value by a given amount.
     @post The time has been increased by the given number of hours.
     @param hoursToAdd The number of hours to add.
     @return The advanced hour value. */
    virtual int increaseHour(const int hoursToAdd) = 0;
};






class Clock : public ClockInterface {

private:
    
    static const int MAX_MINUTES = 60;
    static const int MAX_HOUR_12 = 12;
    static const int MAX_HOUR_24 = 24;
    int hours, minutes;
    bool is24;
    
    /** Sets the clock to 12- or 24-hour mode.
     @return Client decision on clock mode. */
    bool set24() {
        string userResponse;
        
        cout << "DEFAULT NOTATION: 12 hour.\nWould you like to set clock to " <<
        "24 hour mode? (Y/N): ";
        
        cin >> userResponse;
        if (userResponse == "y" || userResponse == "Y") {
            return true;
        }
        
        return false;
    }
    
public:
    
    Clock(int hours = 00, int minutes = 00) : hours(hours), minutes(minutes) {
        is24 = set24();
    }
    
    void displayTime() const {
        cout << std::setfill('0') << std::setw(2) << hours << ":" <<
        std::setfill('0') << std::setw(2) << minutes << endl;
    }
    
    
    
    
    
    
    void setTime(const int hours, const int minutes) {}
    
    
    
    
    
    
    void getMinutes() const {}
    
    
    
    
    
    
    int addMinutes(const int minutesToAdd) { return 0; }
    
    
    
    
    
    
    void getHour() const {}
    
    
    
    
    
    
    int increaseHour(const int hoursToAdd) { return 0; }
};






int main(int argc, const char * argv[]) {
    Clock noArgClock;
    Clock argClock(4, 30);
    
    noArgClock.displayTime();
    argClock.displayTime();
    return 0;
}
