#include <vector>

// a tempate vector print function
template <typename T>
T printVec(std::vector<T> V) {
    for (auto& e: V)
        std::cout << e << " ";
    std::cout << "\n";
}
