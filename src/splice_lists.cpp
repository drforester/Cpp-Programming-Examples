/*
append a list to the end of another list
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

    int n = 15;
    std::list<int> aList (n);
    std::generate(aList.begin(), aList.end(), RandInt);
    aList.sort();
    for (auto& e: aList)
        cout << e << " ";
    cout << "\n";

    n = 8;
    std::list<int> bList (n);
    std::generate(bList.begin(), bList.end(), RandInt);
    bList.sort();
    for (auto& e: bList)
        cout << e << " ";
    cout << "\n";

    // move the items in bList to the end of aList, emptying B in so doing
    aList.splice(aList.end(), bList);

    // print the combined list
    for (auto& e: aList)
        cout << e << " ";
    cout << "\n";

    // show that bList is not empty
    for (auto& e: bList)
        cout << e << " ";
    cout << "\n";
}
