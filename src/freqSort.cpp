/*
Sort the characters in a string by their frequency. For example, after
sorting, the string "araprt" should be sorted as "aarrpt" or "rraatp", etc.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

using std::cout;
using std::string;
using std::unordered_map;
using std::pair;

int main()
{
    string inStr = "araprt";
    unordered_map<char,int> umap;
    for (auto& e:inStr)
        if (umap.find(e) == umap.end())
            umap.insert(pair(e,1));
        else
            umap[e] += 1;

    for (auto& e:umap)
        cout << e.first << " : " << e.second << "\n";

}
