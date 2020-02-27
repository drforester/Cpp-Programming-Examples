/*
remove all elements from a list meeting some condition using erase and remove_if.
see: https://en.cppreference.com/w/cpp/algorithm/remove
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

using std::cout;

int RandInt() { return(std::rand()%100); }

int main()
{
    std::srand(97);

    // create a list of randomly generated ints, then print
    int n = 13;
    std::list<int> aList (n);
    std::generate(aList.begin(), aList.end(), RandInt);
    aList.sort();
    for (auto& e: aList)
        cout << e << " ";
    cout << "\n";

    // remove values less than 20
    aList.erase(std::remove_if(aList.begin(), aList.end(), [](int x){return x<20;}), aList.end());

    for (auto& e: aList)
        cout << e << " ";
    cout << "\n";

}
