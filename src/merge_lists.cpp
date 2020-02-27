#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>

using std::cout;

int RandInt() { return(std::rand()%100); }

int main()
{
    std::srand(97);

    // create a list of randomly generated ints and print it
    int n = 15;
    std::list<int> aList (n);
    std::generate(aList.begin(), aList.end(), RandInt);
    aList.sort();
    for (auto& e: aList)
        cout << e << " ";
    cout << "\n";

    // create and print another list
    n = 8;
    std::list<int> bList (n);
    std::generate(bList.begin(), bList.end(), RandInt);
    bList.sort();
    for (auto& e: bList)
        cout << e << " ";
    cout << "\n";

    // merge the two lists and print the result
    aList.merge(bList);

    for (auto& e: aList)
        cout << e << " ";
    cout << "\n";
}
