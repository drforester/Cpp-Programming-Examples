#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include <ctime>        // std::time
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand

using namespace std;

// a tempate vector print function
template <typename T>
T printVec(vector<T> V) {
    for (auto& e: V)
        cout << e << " ";
    cout << "\n";
}

int f1() { // generator of odd numbers staring at 1
    static int i = -1;
    return i+=2;
}

int f2() { // generator of even numbers staring at 2
    static int i=0;
    return i+=2;
}

int RandInt() { // generator of random, positive ints from 0 to 100;
    return (std::rand()%100);
}

// function generator 1: generate a number from 0.0 to 1.0, inclusive
float RandFloat1() { 
    return ( static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX) );
}

// function generator 2: generate a number from 0.0 to 50.0 (for example)
float RandFloat2() { 
    return ( static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX/50) );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // get number of vector elements from user
    cin >> n;

    // generate a vector of odd ints
    vector<int> v1(n);
    generate(v1.begin(), v1.end(), f1);
    printVec(v1);
    
    // generate a vector of even ints
    vector<int> v2(n);
    generate(v2.begin(), v2.end(), f2);
    printVec(v2);

    // generate a vector of random ints from 0 to 100
    vector<int> v3(n);
    generate(v3.begin(), v3.end(), RandInt);
    printVec(v3);

    // generate a vector of random floats between 0 and 1
    vector<float> v4(n);
    generate(v4.begin(), v4.end(), RandFloat1);
    printVec(v4);

    // generate a vector of random floats between 0 and 50
    vector<float> v5(n);
    generate(v5.begin(), v5.end(), RandFloat2);
    printVec(v5);

    return 0;
}
