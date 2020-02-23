/*
a program to check if a string contains vowels
*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using std::cout;

int main(void)
{
    std::list vowels = {'a', 'o', 'y', 'e', 'u', 'i'};
    std::string word;
    std::getline(std::cin, word);
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    int count = 0;
    for (int i=0; i<word.size(); i++) {
        bool found = (std::find(vowels.begin(), vowels.end(), word[i]) != vowels.end());
        if (found)
            count += 1;  
    }
    cout << "The input string contains " << count << " vowels.\n";

    return 0;
}
