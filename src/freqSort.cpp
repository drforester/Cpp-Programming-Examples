/*
Sort the characters in a string by their frequency. For example, after
sorting, the string "araprt" should be sorted as "aarrpt" or "rraatp", etc.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>    // std::pair
#include <vector>
#include <algorithm>  // std::sort

using std::cout;
using std::string;
using std::unordered_map;
using std::pair;
using std::vector;

// sort the vector in ascending order of its pairs' second value, unless
// they are equal, in which sort by that pair's first value.
bool sortAsc(const pair<char,int> &a, const pair<char,int> &b) {
    if (a.second != b.second)
        return b.second < a.second;
    return a.first < b.first;
}

int main()
{
    string inStr = "araprt";

    // map each unique char to its occurance frequency
    unordered_map<char,int> umap;
    for (auto& e:inStr)
        if (umap.find(e) == umap.end())
            umap.insert(pair(e,1));
        else
            umap[e] += 1;

    // sort the key:value map by value. Do this by copying the map into a vector
    // of key-value pairs and sort that.
    vector<pair<char,int>> vec;
    std::copy(umap.begin(), umap.end(), std::back_inserter(vec));
    std::sort(vec.begin(), vec.end(), sortAsc);

    // print the sorted vector
    for (auto& e:vec) {
        for (int i=0; i<e.second; i++)
            cout << e.first;
    }
    cout << "\n";    
}
