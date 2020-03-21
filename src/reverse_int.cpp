/*
Reverse an Integer
Given a positive integer input, print the reverse-order version.
For example:
    Input : 1234
    Output: 4321
*/

#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::vector;

int main()
{
    int input = 123456789;
    // count the digits in this number
    int test = input;
    int digCount = 1;
    do {
        test /= 10;
        if (test > 0) {
            digCount += 1;
        }
    } while (test > 10);

    cout << input << " has " << digCount << " digits.\n";

    // get the 1's place digit by modulo 10 and place the
    // result in a vector. Then remove the digit by subtraction
    // and division by 10.
    int res;
    vector<int> ans;
    for (int i=1; i<=digCount; i++) {
        res = input % 10;
        input -= res;
        input /= 10;
        ans.push_back(res);
    }
    for (auto& e:ans)
        cout << e;
    cout << "\n";

}
