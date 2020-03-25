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
#include <algorithm>

using std::cout;
using std::string;

int main()
{
    string inStr;
    std::getline(std::cin, inStr); // for testing only XXXXXXXXX

    int n = inStr.size();
    string pal, longest_pal;
    int dist, i1, i2;

    // center is a char
    for (int i=1; i<n-1; i++) {
        dist = std::min(i, n-1-i);
        cout << "i:" << i << " dist:" << dist << " ";
        for (int j=1; j<dist+1; j++) {
            cout << "j:" << j << " ";
            if (inStr[i-j] != inStr[i+j]) {
                break;
            }
            else {
                pal = inStr.substr(i-j, 2*j+1);
            }
        }
        if (pal.size() > longest_pal.size())
            longest_pal = pal;
        cout << "\n";
    }

    // center is between two chars
    // ...

    cout << "longest pal: " << longest_pal << "\n";
}


