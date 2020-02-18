/*
Use generate() to initialize a vector of (pseudo-) randomly generated numbers.
The ForwardIterator Generate generates values over a given range using a function.
The function generator uses the function pseudo random number generator rand() function, which is
seeded by srand(). The srand() function may be seeded either by a constant or using the system
time.

    ~$ g++ vec_rand_ints.cpp -o vec_rand_ints
*/

#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include <ctime>        // std::time
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand

using std::cout;

// function generator:
int RandomNumber() { return (std::rand()%100); }

int main() {

    std::srand(97);
    //std::srand(unsigned(std::time(0)));

    std::vector<int> aVec (8);

    std::generate(aVec.begin(), aVec.end(), RandomNumber);

    cout << "aVec:";
    for (std::vector<int>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;
}
