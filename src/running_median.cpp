/*

*/

#include <iostream>     // std::cout
#include <algorithm>    // std::generate
#include <ctime>        // std::time
#include <deque>
#include <vector>
#include <cstdlib>      // std::rand, std::srand

using std::cout;
using std::deque;
using std::vector;

// function generator of random ints:
int RandInt() { return (std::rand()%100); }

int main() {

    std::srand(97);
    //std::srand(unsigned(std::time(0)));

    // declare a list and populate it with randomly generated ints
    int N = 13;
    deque<int> rDeq (N);
    std::generate(rDeq.begin(), rDeq.end(), RandInt);
    vector<int> sVec;

    // at each iteration a previous value is removed from the back of the list and
    // a new value inserted at the front. Calculate the median of the list.
    int ntrials = 100;
    int midx1, midx2;
    size_t sz = rDeq.size();
    bool ISODD = (sz & 1);
    for (int i=0; i<ntrials; i++) {
        rDeq.pop_front();
        int irand = std::rand()%100;
        rDeq.push_back(irand);

        cout << "deque        : ";
        for (auto& e:rDeq)
            cout << e << " ";
        cout << "\n";

        // copy to a vector and sort it to find the median
        sVec.clear(); // to keep the vector from growing with each copy
        std::copy(rDeq.begin(), rDeq.end(), std::back_inserter(sVec));
        std::sort(sVec.begin(), sVec.end());
        cout << "sorted vector: ";
        for (auto& e:sVec)
            cout << e << " ";
        cout << "\nmedian: ";       

        if (ISODD) { // odd number of elements
            midx1 = sz/2;
            cout << sVec[midx1];
        }
        else {      // even number of elements
            midx1 = sz/2 - 1;
            midx2 = midx1 + 1;
            cout << (sVec[midx1] + sVec[midx2]) / 2;
        }
        cout << "\n\n";        
    }

}
