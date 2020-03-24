/*
--- Longest Palindromic Substring ---

Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.

Example 1:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

Example 2:
    Input: "cbbd"
    Output: "bb"
*/

#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::string;
using std::map;

int main()
{
    string inStr;
    std::getline(std::cin, inStr); // for testing only XXXXXXXXX
    
    bool FOUND = false;
    unsigned int i=0;
    map<char,int> omap; 
    while (! FOUND) {
        omap[inStr[i]]++;

        cout << inStr[i] << ":" << omap[inStr[i]] << " ";
       
        // check loop termination condition & increment index
        if (i==(inStr.size()-1))
            FOUND = true;
        i += 1;
    }

}
