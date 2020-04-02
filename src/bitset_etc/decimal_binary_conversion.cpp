/*
    - Convert an integer to its binary representation -
    std::bitset has a .to_string() method that returns a std::string holding a text
    representation in binary, with leading-zero padding.
*/

#include <iostream>
#include <bitset>
#include <string>

using std::cout;
using std::string;

int main()
{
    // test with an 8-bit value
    unsigned int x = 255;

    // to binary
    string binary = std::bitset<8>(x).to_string();
    cout << binary << '\n';

    // back to decimal
    unsigned long decimal = std::bitset<8>(binary).to_ulong();
    cout << decimal << '\n';

    ///////////////////////////////////////////////////////////    
    // test with a 16-bit value
    unsigned long y = 512;

    // to binary
    binary = std::bitset<16>(y).to_string();
    cout << binary << '\n';

    // back to decimal
    decimal = std::bitset<16>(binary).to_ulong();
    cout << decimal << '\n';

}
