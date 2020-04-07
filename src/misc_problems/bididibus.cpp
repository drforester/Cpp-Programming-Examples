/*
Global Raining at Bididibus
https://onlinejudge.org/external/117/11786.pdf

test input:
     /\
_/\_/  \

output:
2 (since 1/2 + 1 + 1/2 = 2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>    // std::pair
#include <algorithm>  // std::min

using std::cout;
using std::string;
using std::vector;
using std::pair;

int main()
{
    string world = {'_','/','\\','_','/','/','\\','\\'};
    cout << world << '\n';

    // 1st pass through the string: identify the peak-pairs,
    // and their corresponding heights.
    char prev;
    unsigned int ip = 0;
    unsigned int h = 0;
    vector<pair<unsigned int, unsigned int>> peakIdx;
    vector<pair<unsigned int, unsigned int>> peakHeights;
    pair<unsigned int, unsigned int> pidx;
    pair<unsigned int, unsigned int> ph;
    for (unsigned int i=0; i<world.size(); i++) {
        if (world[i] == '/')
            h += 1;
        if (world[i] == '\\' && prev != '\\') {
            if (ip == 0) {
                pidx.first = i;
                ph.first = h;
                ip = 1;
            }
            else if (ip == 1) {
                pidx.second = i;
                ph.second = h;
                peakIdx.push_back(pidx);
                peakHeights.push_back(ph);
                ip = 0;
            }   
            h -= 1;
        }
        prev = world[i];
        cout << h << " ";
    }
    cout << '\n';

    for (auto &e: peakIdx)
        cout << "(" << e.first << "," << e.second << ")  ";
    cout << '\n';

    for (auto &e: peakHeights)
        cout << "(" << e.first << "," << e.second << ")  ";
    cout << '\n';

    // 2nd pass through the string: count the space between peak-pairs.
    for (unsigned int i=0; i<peakHeights.size(); i++) {
        unsigned int height = std::min(peakHeights[i].first, peakHeights[i].second);
        cout << "height: " << height << " ";
    }
    cout << '\n';
    
}
