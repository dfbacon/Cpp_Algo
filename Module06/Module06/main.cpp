//
//  main.cpp
//  Module06
//
//  Created by Daniel Bacon on 10/7/19.
//  Copyright © 2019 Daniel Bacon. All rights reserved.
//

/**
 Programming Problem #3
 Data Abstraction and Problem Solving with C++ 6th ed page 221
 
 Write a function that uses a stack to test whether a given string is a
    palindrome. Exercise 14 asked you to write an algorithm for such a function
 
 Use the STL library stack and see the note at the bottom of programming problem 1.
 
 Submission and Assessment
 To submit this assignment, use the submit button (Links to an external site.)
    and type your answer into the available text box.
 
 Key Topics
 Input
 
 accept a string
 add characters to the stack
 Processing
 
 push
 pop
 isEmpty
 peek
 Output
 
 use stack methods to check for palindromes
 */

#include <iostream>
#include <stack>

using namespace std;

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
