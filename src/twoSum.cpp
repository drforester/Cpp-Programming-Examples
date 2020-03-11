/*
Given an array of n integers and a number t. Determine whether there is a
pair of elements in the array that sums to exactly t and eturn the indexes
of the first two such elements in the array. If no such pair exist, then
return the string "No such element pair was found."

For example, given the array [2,7,5,2,1], and t = 9, the program
should return the index pair (1,3).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using std::cout;
using std::vector;
using std::unordered_map;
using std::pair;

int main()
{
    int target = 13;
    vector<int> inVec {1,7,2,5,9,2,1,8,4,7,6,9,3};
    unordered_map<int,int> umap;
    // traverse the vector once mapping indexes to desired value, where
    // desired value is the number needed to add to the value at this
    // index to equal target, i.e. desired = target - inVec[i]
    int i, desired;
    int EXISTS = 0;
    for (i=0; i<inVec.size(); i++) {
        desired = target - inVec[i];
        if (umap.find(desired) == umap.end()) // not found
            umap.insert(pair(inVec[i],i));
        else {
            cout << umap[desired] << ":" << i << "\n";
            EXISTS = 1;
            break;
        }
    }
    
    if (!EXISTS)
        cout << "No such element pair exists.\n";
}
