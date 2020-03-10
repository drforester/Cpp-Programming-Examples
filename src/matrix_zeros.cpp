/*
input:

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
#include <utility>  // std::pair

using std::cout;
using std::vector;
using std::pair;

int main()
{

    vector<vector<int>> M = { {3,1,8,9,2},
                              {7,3,3,0,1},
                              {8,4,5,2,8},
                              {6,0,9,5,1} };

    // traverse the matrix, saving locations of zeros to a vector of pairs
    int i,j;
    vector<pair<int,int>> zyx;
    for (i=0; i<M.size(); i++) {
        for (j=0; j<M[i].size(); j++) {
            if (M[i][j] == 0)
                zyx.push_back(pair(i,j));
        }
    }

    // iterate over the zeros, if any
    if (zyx.size()) {
        for (auto& e:zyx) { // zero-out these rows
            for (int j=0; j<M[e.first].size(); j++)
                M[e.first][j] = 0;
        }
        for (auto& e:zyx) { // zero-out these cols
            for (int i=0; i<M.size(); i++)
                M[i][e.second] = 0;
        }
    }


    for (i=0; i<M.size(); i++) {
        for (j=0; j<M[i].size(); j++) {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
    

}
