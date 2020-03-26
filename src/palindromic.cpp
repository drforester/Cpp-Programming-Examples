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
    string s;
    std::getline(std::cin, s); // for testing only XXXXXXXXX

    int n = s.size();
    int greatest_len = 0;
    string longest_pal = "";

    // case 1: middle "mid" is a char
    for(int mid = 0; mid < n; mid++) {
        for(int x = 0; mid - x >= 0 && mid + x < n; x++) {
            if(s[mid-x] != s[mid+x]) {
                break;
            }
            int len = 2 * x + 1;
            if(len > greatest_len) {
                greatest_len = len;
                longest_pal = s.substr(mid - x, len);
            }
        }
    }

    // case 2: middle "mid" is between two chars
    for(int mid = 0; mid < n - 1; mid++) {
        for(int x = 1; mid - x + 1 >= 0 && mid + x < n; x++) {
            if(s[mid-x+1] != s[mid+x]) {
                break;
            }
            int len = 2 * x;
            if(len > greatest_len) {
                greatest_len = len;
                longest_pal = s.substr(mid - x + 1, len);
            }
        }
    }

    cout << longest_pal << "\n";
}
