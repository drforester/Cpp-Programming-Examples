/*
Given a US phone number with parentheses around the area-code, and a hyphen
separating prefix from 4-digit number, extract only the digits. Another way
to approach the problem, remove all the non-digit chars.

The example below uses the erase-remove idiom. std::remove moves the non-removed
items to the front of the vector and returns an iterator pointing just beyond the
last un-removed item. Then std::erase trims the vector from that iterator to the end.
https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <string.h> // strlen

using std::cout;
using std::string;

void removeCharsFromString(string &str, char* charsToRemove);

int main()
{
    string inputStr = "(555) 867-5309";
    char chars2rm[] = "() -"; // left & right parens, whitespace, and hyphen
    cout << "before : " << inputStr << "\n";
    removeCharsFromString(inputStr, chars2rm);
    cout << "after  : " << inputStr << "\n";
}


void removeCharsFromString(string &str, char* charsToRemove) {
    for (unsigned int i=0; i<strlen(charsToRemove); ++i) {
        str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
    }
}
