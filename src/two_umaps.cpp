/*
Checking whether one map's key exists in another map
*/

#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::string;

int main(void)
{
    // previous year's t-shirt sizes and counts
    std::unordered_map<string, int> umap1 = {
        {"M", 13},
        {"L",21},
        {"XL",17},
        {"XXL",3}
    };

    // current year's t-shirt sizes and counts
    std::unordered_map<string, int> umap2 = {
        {"M", 14},
        {"L",24},
        {"XL",18}
    };

    for (std::unordered_map<string, int>::iterator itr=umap1.begin(); itr!=umap1.end(); itr++) {
        bool isin = umap2[itr->first]; // checking if first map's key is in 2nd map
        string matchMsg = itr->first + " is in both umaps";
        string notMatchMsg = itr->first + " is NOT in both umaps";
        string output = isin ? matchMsg : notMatchMsg;
        cout << output << "\n";
    }
} 
