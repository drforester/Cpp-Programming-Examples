/*

Given an nxm matrix of integers, zero-out the columns and the rows
of any elements equal to zero.

sample input:

    3 1 8 9 2
    7 3 3 0 1
    8 4 5 2 8
    6 0 9 5 1

output:

    3 0 8 0 2
    0 0 0 0 0
    8 0 5 0 8
    0 0 0 0 0

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::vector;
using std::unordered_set;

int main()
{

    vector<vector<int>> M = { {3,1,8,9,2},
                              {7,3,3,0,1},
                              {8,4,5,2,8},
                              {6,0,9,5,1} };

    // traverse the matrix, saving i,j indexes of zero elements to unordered_sets
    int i,j;
    vector<int> rowVec;
    vector<int> colVec;
    unordered_set<int> usetRows;
    unordered_set<int> usetCols;
    for (i=0; i<M.size(); i++) {
        for (j=0; j<M[i].size(); j++) {
            if (M[i][j] == 0) {
                usetRows.insert(i);
                usetCols.insert(j);
            }
        }
    }

    // iterate over the zeros, if any
    if (usetRows.size()) {
        for (auto& e:usetRows) { // zero-out these rows
            for (int j=0; j<M[e].size(); j++)
                M[e][j] = 0;
        }
        for (auto& e:usetCols) { // zero-out these cols
            for (int i=0; i<M.size(); i++)        
                M[i][e] = 0;
        }
    }

    // print the resultant matrix
    for (i=0; i<M.size(); i++) {
        for (j=0; j<M[i].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    
}
