/*
Use generate() to initialize a vector of (pseudo-) randomly generated numbers.
The ForwardIterator Generate generates values over a given range using a function.
The function generator uses the function pseudo random number generator rand() function, which is
seeded by srand(). The srand() function may be seeded either by a constant or using the system
time.

    ~$ g++ vec_rand_floats.cpp -o vec_rand_floats
*/

#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include <ctime>        // std::time
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand

using std::cout;

// function generator 1: generate a number from 0.0 to 1.0, inclusive
float RandomNumber1() { 
    return ( static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX) );
}

// function generator 2: generate a number from 0.0 to 50.0 (for example)
float RandomNumber2() { 
    return ( static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX/50) );
}

// function generator 3: generate a number from LO to HI
float RandomNumber3() {
    float LO = 10;
    float HI = 20; 
    return ( LO + static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX/(HI-LO)) );
}



int main() {

    std::srand(97);
    //std::srand(unsigned(std::time(0)));

    std::vector<float> aVec (8);

    std::generate(aVec.begin(), aVec.end(), RandomNumber1);

    cout << "using func gen 1:";
    for (std::vector<float>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    std::generate(aVec.begin(), aVec.end(), RandomNumber2);

    cout << "using func gen 2:";
    for (std::vector<float>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    std::generate(aVec.begin(), aVec.end(), RandomNumber3);

    cout << "using func gen 3:";
    for (std::vector<float>::iterator it=aVec.begin(); it!=aVec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    return 0;
}
