/*
https://leetcode.com/problems/string-to-integer-atoi/

Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit
signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of
representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−2^31) is returned.

*/

#include <iostream>
#include <string>    // stoi()
#include <ctype.h>   // isdigit()
#include <algorithm> // lexicographical_compare()
#include <stdexcept>
#include <climits>   // INT_MIN, INT_MAX

using std::cin;
using std::cout;
using std::string;

int main()
{
    // step 1: extract the substring containing the valid digits
    string input;
    string digitString;
    std::getline(cin, input);

    // the first non-whitespace char can be a digit, a + or a -
    bool HASBEGUN = false;
    bool ISNEG = false;
    unsigned int pos = 0;
    for (int i=0; i<input.size(); i++) {
        if (!HASBEGUN) {
            if (input[i]=='-') {
                ISNEG = true;
                if ((input.size()-i) > 1) { // no whitespace allowed after sign
                    if (!isdigit(input[i+1])) {
                        digitString.insert(digitString.begin()+pos, '0');
                        break;
                    }
                }
            }
            if (input[i]=='+') {
                if ((input.size()-i) > 1) { // no whitespace allowed after sign
                    if (!isdigit(input[i+1])) {
                        digitString.insert(digitString.begin()+pos, '0');
                        break;
                    }
                }
            }
            if ( (!isdigit(input[i])) && (input[i]!=' ') &&
                 (input[i]!='+') && (input[i]!='-') ) {
                digitString.insert(digitString.begin()+pos, '0');
                break;
            }
            if ( isdigit(input[i]) ) {
                if ((i>1) && (input[i-2] != ' ')) {
                    digitString.insert(digitString.begin()+pos, '0');
                    break;
                }
                digitString.insert(digitString.begin()+pos, input[i]);
                HASBEGUN = true;
                pos += 1;
            }
        }
        else {
            digitString.insert(digitString.begin()+pos, input[i]);
            pos += 1;
        }
    }
        // step 2: convert this string of digits to an integer
        int result;
        try {
            result = stoi(digitString);
            if (ISNEG) result *= -1;
        }
        catch (const std::out_of_range& oor) { // to large for int dtype
            if (ISNEG)
                result = INT_MIN;
            else
                result = INT_MAX;
        }
        catch (const std::invalid_argument& inva) { // not a valid string
            result = 0;
        }        
        cout << result << "\n";
        
}
