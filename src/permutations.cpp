/*
std::next_permutation rearranges the elements in a container into the next
lexicographically greater permutation. A collection of N elements has N!
possible arrangements.

related functions in the std::algorithm library are:
    std::prev_permutation()
    std::lexicographical_compare()

reference: https://www.cplusplus.com/reference/algorithm/next_permutation/
*/

#include <iostream>
#include <vector>
#include <algorithm> // std::next_permutation, std::sort

using std::cout;
using std::vector;

int main()
{
    // first, get all permutations in an array of ints
    int intArr[] = {1,2,3};
    std::sort(intArr, intArr+3);
    cout << "The 3! possible permutations of ints in our Array:\n";
    do {
        cout << intArr[0] << ' ' << intArr[1] << ' ' << intArr[2] << '\n';
    } while ( std::next_permutation(intArr,intArr+3) );
    // checking that the array is back in the same order
    cout << "After loop: " << intArr[0] << ' ' << intArr[1] << ' ' << intArr[2] << "\n\n"; 

    // next, test std::next_permutation() on a vector of chars
    vector<char> charVec = {'a','b','c'};
    std::sort(charVec.begin(), charVec.end());
    cout << "The 3! possible permutations of chars in our Vector:\n";
    do {
        cout << charVec[0] << ' ' << charVec[1] << ' ' << charVec[2] << '\n';
    } while ( std::next_permutation(charVec.begin(),charVec.end()) );
    // checking that the vector is back in the same order
    cout << "After loop: " << charVec[0] << ' ' << charVec[1] << ' ' << charVec[2] << '\n'; 
    
    

}
