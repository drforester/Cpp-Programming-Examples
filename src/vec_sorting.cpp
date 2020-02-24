/*

    ~$ g++ vec_sorting.cpp -o vec_sorting
*/

#include <iostream>     // std::cout
#include <algorithm>    // std::generate, std::sort
#include <ctime>        // std::time
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand

using std::cout;

// function generator:
int RandomNumber() { return (std::rand()%100); }

bool sortAsc(int i,int j) { return (i<j); } // i<j ascending
bool sortDesc(int i,int j) { return (i>j); } // i>j descending

int main() {

    // generate a vector randomly
    std::srand(97);
    std::vector<int> aVec (8);
    std::generate(aVec.begin(), aVec.end(), RandomNumber);
    cout << "unsorted vector:";
    for (std::vector<int>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    // make three copies of the vector that we will sort using two different comparators
    std::vector<int> aVec1(aVec);
    std::vector<int> aVec2(aVec);
    std::vector<int> aVec3(aVec);

    // default sort entire vector ascending
    std::sort(aVec1.begin(), aVec1.end());

    // use our comparator function sortDesc()
    std::sort(aVec2.begin(), aVec2.end(), sortDesc);

    // sort half the vector using sortAsc()
    std::sort(aVec3.begin(), aVec3.begin()+4, sortAsc);

    cout << "sorted using default ascending comparator:";
    for (std::vector<int>::iterator it=aVec1.begin(); it!=aVec1.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    cout << "sorted using descending comparator:";
    for (std::vector<int>::iterator it=aVec2.begin(); it!=aVec2.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    cout << "sorted 1st half of vector using ascending comparator:";
    for (std::vector<int>::iterator it=aVec3.begin(); it!=aVec3.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;
}
