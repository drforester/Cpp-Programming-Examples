#include <iostream>
#include <vector>
#include <list>

// a tempate vector print function
template <typename T>
void printVec(std::vector<T> &V) {
    for (auto& e: V)
        std::cout << e << " ";
    std::cout << "\n";
}

// a template list print function
template <typename T>
void printList(std::list<T> &L) {
    for (auto& e: L)
        std::cout << e << " ";
    std::cout << "\n";
}
