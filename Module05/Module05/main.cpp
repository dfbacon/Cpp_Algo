//
// Name: Daniel Bacon
// Class:
// Assignment: Module 05 - Programming Problem 02
//


#include <iostream>
using namespace std;


/**
    Checks a given string for validity.
    Valid strings must follow these requirements:
        <S> =  $ | <W> | $<S>
        <W> = abb|a<W>bb
 
    @param str String being evaluated.
    @return true if string is valid, false otherwise.
 */
bool validPattern(string str);


/**
    Prints valid strings to the console.
 
    @param str String being evaluated.
 */
void writeString(string str);






bool validPattern(string str) {
    if (str.length() > 0 && str.length() <= 7) {
        if (str[0] == '$') {
            return true;
        }
        else if (str[0] == 'a' && str[str.length() - 1] == 'b' &&
                 str[str.length() - 2] == 'b') {
            return true;
        }
    }
    return false;
}






void writeString(string str) {
    if (validPattern(str)) {
        cout << str << endl;
    }
}






int main(int argc, const char * argv[]) {
    
    string testArray[] = {"$", "$I'm too long", "invalid", "$valid", "abb",
        "a$12bb", "a$bbb", "a$b", "a$invalidbb", "ayesbb", "atoolongbb", ""};
    //  true, false, false, true, true, true, true, false, false, true, false, false
    
    for (int index = 0; index < 12; index++) {
        writeString(testArray[index]);
    }
    
    return 0;
}
