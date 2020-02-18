/*
Demonstrate operations on vectors and algorithms to use on them

    ~$ g++ vector_STL_algorithms.cpp -o vec_algos
*/

#include <iostream>     // std::cout
#include <algorithm>    // std::generate, std::reverse, std::count, std::find 
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand
#include <numeric>      // accumulate operation 

using std::cout;
using std::endl;

// function generator:
int RandomNumber(){ return (std::rand()%100); }

int main() {

    // initialize a vector
    std::srand(97);
    std::vector<int> aVec (8);
    std::generate(aVec.begin(), aVec.end(), RandomNumber);
    cout << "our vector:";
    for (std::vector<int>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    // reverse the vector
    std::reverse(aVec.begin(), aVec.end()); 
    cout << "reversed vector:";
    for (std::vector<int>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    // maximum element
    cout << "max element: " << *max_element(aVec.begin(), aVec.end()) << endl;
    
    // minimum element
    cout << "min element: " << *min_element(aVec.begin(), aVec.end()) << endl;
    
    // sum
    cout << "max element: " << accumulate(aVec.begin(), aVec.end(), 0) << endl;

    // count the occurances of a number, say 55
    cout << "nb occurances of 55: " << std::count(aVec.begin(), aVec.end(), 55) << endl;

    // find the last occurance of the number 55
    std::vector<int>::iterator it;    
    it = std::find(aVec.begin(), aVec.end(), 55);
    if (it != aVec.end())
        std::cout << "Element found at: " << it-aVec.begin() << endl;
    else
        std::cout << "Element not found in vector" << endl; 
    

    return 0;
}
