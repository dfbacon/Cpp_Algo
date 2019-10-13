//
// Name: Daniel Bacon
// Assignment: Module 06 - Programming Problem #3
//

#include <iostream>
#include <stack>

using namespace std;

/**
    Checks if a string is a palindrome, using a stack data structure.
 
    @param testString The string being examined.
    @return true if the string is a palindrome, false otherwise.
 */
bool isPalindrome(string testString) {
    if (!testString.empty()) {
        
        int stringLength = testString.length();
        stack<char> stringStack;
        
        for (int index = 0; index < stringLength / 2; index++) {
            stringStack.push(testString[index]);
        }
        
        for (int index = (stringLength + 1) / 2 ; index < stringLength; index++) {
            if (stringStack.top() != testString[index]) {
                return false;
            }
            
            stringStack.pop();
        }
    }
    
    return true;
}



int main(int argc, const char * argv[]) {
    
    string string1 = "abba is si abba";
    string string2 = "abc";
    string string3 = "";
    string string4 = "a";
    string string5 = "abcba";

    cout << "Testing... should be true(1): " << isPalindrome(string1) << endl;
    cout << "Testing... should be false(0): " << isPalindrome(string2) << endl;
    cout << "Testing... should be true(1): " << isPalindrome(string3) << endl;
    cout << "Testing... should be true(1): " << isPalindrome(string4) << endl;
    cout << "Testing... should be true(1): " << isPalindrome(string5) << endl;
    
    return 0;
}
