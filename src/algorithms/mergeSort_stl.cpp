/*
    a C++ implementation of merge sort using std::inplace_merge().
    https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Merge_sort#C++
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using std::cout;

template <typename BidirIt, typename Compare = std::less<>>
void merge_sort(BidirIt first, BidirIt last, Compare cmp = Compare {})
{
    const auto n = std::distance(first, last);
    
    if (n > 1) {
        const auto middle = std::next(first, n / 2);
        
        merge_sort(first, middle, cmp);
        merge_sort(middle, last, cmp);
        
        std::inplace_merge(first, middle, last, cmp);
    }
}

// a tempate vector print function
template <typename T>
T printVec(std::vector<T> V) {
    for (auto& e: V)
        std::cout << e << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> v {3, -2, 1, 5, -9, 10, 3, -3, 2};
    
    merge_sort(std::begin(v), std::end(v)); // sort ascending
    cout << "sorted ascending: \n";
    printVec(v);
    merge_sort(std::begin(v), std::end(v), std::greater<> {}); // sort descending
    cout << "sorted descending: \n";
    printVec(v);
}
