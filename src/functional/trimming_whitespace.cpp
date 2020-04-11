/*
    String Trimming (the functional way)
    Strip whitespace from the start and end of a string.
    (see pg. 31 of Functional Programming in C++, by Ivan Čukić)
*/

#include <iostream>
#include <string>
#include <algorithm> // std::find_if(), std::move()

using std::cout;
using std::string;

bool is_not_space(char c);
string trim_left(string s);
string trim_right(string s);
string trim(string s);

int main()
{
    string input = "     Subterranian Homesick Blues  ";
    cout << "|" << trim(input) << "|" << '\n';
}


bool is_not_space(char c) {
    return (c != ' ') ? true : false;
}

string trim_left(string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
    return s;
}

string trim_right(string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
    return s;
}

/* Composing the two functions above for the full trim function */
string trim(string s) {
    return trim_left(trim_right(std::move(s)));
}

