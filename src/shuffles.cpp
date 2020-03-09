#include <iostream>
#include <vector>
#include <list>
#include <numeric>    // iota
#include <random>    // mt19937
#include <algorithm> // shuffle
#include "printing.cpp"

using std::cout;

int main()
{
    // Randomly shuffle a vector
    int N = 13;
    std::vector<int> v1 (N);
    std::iota(v1.begin(), v1.end(), -3);
    cout << "----- Vector -----\n";
    cout << "before shuffle: ";
    printVec(v1);
    
    std::shuffle(v1.begin(), v1.end(), std::mt19937{std::random_device{}()});
    cout << "after shuffle : ";
    printVec(v1);

    // Randomly shuffle a list
    // The following example applies std::shuffle to a vector of std::list iterators
    // since std::shuffle cannot be applied to a std::list directly.
    // see: https://en.cppreference.com/w/cpp/algorithm/iota
    std::list<int> l1(N);
    std::iota(l1.begin(), l1.end(), 0);
    cout << "----- List -----\n";
    cout << "before shuffle: ";
    printList(l1);

    std::vector<std::list<int>::iterator> vit(l1.size());
    std::iota(vit.begin(), vit.end(), l1.begin());
    std::shuffle(vit.begin(), vit.end(), std::mt19937{std::random_device{}()});
    cout << "after shuffle : ";
    for (auto i:vit) std::cout << *i << " ";
    std::cout << "\n";

}
