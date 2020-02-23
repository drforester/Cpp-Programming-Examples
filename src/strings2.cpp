/*
a program to check if a string contains a certain substring
*/

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;

int main(void)
{
    std::string substr = "joy";
    std::string word;
    std::getline(std::cin, word);
    if (word.find(substr) != std::string::npos)
        cout << "found!\n";
    else
        cout << "not found.\n";

    return 0;
}
