#include <iostream>
#include <vector>
#include <list>

// a tempate vector print function
template <typename T>
T printVec(std::vector<T> V) {
    for (auto& e: V)
        std::cout << e << " ";
    std::cout << "\n";
}

template <typename T>
T printList(std::list<T> L) {
    for (auto& e: L)
        std::cout << e << " ";
    std::cout << "\n";
}
