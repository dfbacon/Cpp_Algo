/*
 Name: Daniel Bacon
 Class: Clock
 Assignment: Module 3 - Programming Problem #1.
 */

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;


class Clock {

private:
    static const int MAX_MINUTES = 60;
    static const int MAX_HOUR_12 = 12;
    static const int MAX_HOUR_24 = 24;
    int hours, minutes;
    
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
    
    /** Checks time at creation for validity. If invalid, sets to 00:00 */
    void checkTime();
    
    /** Displays the time in 12 hour mode. */
    void display12Hour() const;
    
    /** Displays the time in 24 hour mode. */
    void display24Hour() const;
    
    
public:
    Clock(int newHour = 0, int newMinute = 0) : hours(newHour), minutes(newMinute) {
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






void Clock::displayTime() const {
    cout << "\n12 Hour Mode:" << endl << "\t";
    display12Hour();
    cout << "\n24 Hour Mode:" << endl << "\t";
    display24Hour();
    cout << endl;
}






void Clock::setTime(const int newHour, const int newMinute) {
    setHour(newHour);
    setMinutes(newMinute);
}






void Clock::addMinutes(const int minutesToAdd) throw(out_of_range){
    int hoursToAdd;
    
    try {
        if (minutesToAdd > 0) {
            
            hoursToAdd = minutesToAdd / MAX_MINUTES;
            minutes += minutesToAdd % MAX_MINUTES;
            
            if (minutes == MAX_MINUTES) {
                setMinutes(0);
                hoursToAdd++;
            }
            else if (minutes > MAX_MINUTES) {
                setMinutes(minutes % MAX_MINUTES);
                hoursToAdd++;
            }
            
            if (hoursToAdd > 0) {
                increaseHour(hoursToAdd);
            }
        }
        else {
            throw out_of_range("Value must be greater than zero.");
        }
    } catch (out_of_range& e) {
        cout << "Clock not updated: " << e.what() << endl;
    }
}







void Clock::setMinutes(const int newMinute) throw(out_of_range){
    try {
        if (newMinute >= 0 && newMinute < MAX_MINUTES) {
            this->minutes = newMinute;
        }
        else {
            throw out_of_range("Value must be between 0 and 59.");
        }
    }
    
    catch (out_of_range& e) {
        cout << "Minute not set: " << e.what() << endl;
        }
}







void Clock::setHour(const int newHour) throw(out_of_range) {
    try {
        if (newHour >= 0 && newHour < MAX_HOUR_24) {
            this->hours = newHour;
        }
        else {
            throw out_of_range("Value must be between 0 and 23.");
        }
    }
    
    catch (out_of_range& e) {
        cout << "Hour not set: " << e.what() << endl;
    }
}







void Clock::increaseHour(const int hoursToAdd) {
    int addedHours = hoursToAdd;
    
    if (addedHours > MAX_HOUR_24) {
        addedHours %= MAX_HOUR_24;
    }
    
    hours += addedHours;
    
    if (hours == MAX_HOUR_24) {
        setHour(0);
    }
    else if (hours > MAX_HOUR_24) {
        setHour(hours % MAX_HOUR_24);
    }
}






void Clock::checkTime() {
    if (hours < 0 || hours >= MAX_HOUR_24) {
        setHour(0);
    }
    
    if (minutes < 0 || minutes >= 60) {
        setMinutes(0);
    }
}







void Clock::display12Hour() const {
    if (hours == 0) {
        cout << setfill('0') << setw(2) << (MAX_HOUR_12) <<
        ":" << setfill('0') << setw(2) << minutes;
    }
    
    else if (hours > MAX_HOUR_12) {
        cout << setfill('0') << setw(2) << (hours - MAX_HOUR_12) <<
        ":" << setfill('0') << setw(2) << minutes;
    }
    
    else {
        cout << setfill('0') << setw(2) << (hours) <<
        ":" << setfill('0') << setw(2) << minutes;
    }
}






void Clock::display24Hour() const {
    cout << setfill('0') << setw(2) << hours << ":" << setfill('0') <<
    setw(2) << minutes;
}






int main(int argc, const char * argv[]) {
    Clock clock24; //24 hour
    Clock clock12(4, 30); //12 hour

    
    cout << "Time is 04:30";
    clock12.displayTime();
    cout << endl;
    
    cout << "Time is 00:00";
    clock24.displayTime();
    cout << endl;

    cout << "----------------- TESTING setTime() -------------------\n" << endl;
    
    clock24.setTime(11, 11);
    cout << "new time is 11:11" << endl;
    clock24.displayTime();
    cout << endl;
    
    cout << "Error should appear: ";
    clock24.setTime(25, 0);
    cout << "new time is 11:00" << endl;
    clock24.displayTime();
    cout << endl;
    
    cout << "Error should appear: ";
    clock24.setTime(02, 67);
    cout << "new time is 02:00" << endl;
    clock24.displayTime();
    cout << endl;
    
    cout << "Error should appear: ";
    clock24.setTime(28, 79);
    cout << "new time is 02:00" << endl;
    clock24.displayTime();
    cout << endl;
    
    clock24.setTime(15, 30);
    cout << "new time is 15:30" << endl;
    clock24.displayTime();
    cout << endl;
    
    cout << "----------------- TESTING addMinutes() ----------------\n" << endl;

    clock24.addMinutes(1500); //adding 25 hours
    cout << "1500 minutes added, new time is 16:30" << endl;
    clock24.displayTime();
    cout << endl;

    clock24.addMinutes(75);
    cout << "75 minutes added.\nTime should be 17:45" << endl;
    clock24.displayTime();
    cout << endl;
    
    clock24.addMinutes(480);
    cout << "480 minutes added.\nTime should be 01:45" << endl;
    clock24.displayTime();
    cout << endl;
    
    clock24.addMinutes(40);
    cout << "40 minutes added.\nTime should be 02:25" << endl;
    clock24.displayTime();
    cout << endl;
    
    clock24.addMinutes(3);
    cout << "3 minutes added.\nTime should be 02:28" << endl;
    clock24.displayTime();
    cout << endl;
    
    cout << "Error should appear: ";
    clock24.addMinutes(-1);
    cout << endl;
    cout << "Time should be 02:28" << endl;
    clock24.displayTime();
    cout << endl;
    
    return 0;
}
