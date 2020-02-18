/*
Populate a vector of vectors of floats.
Traverse and print the values (cols) in each vector (rows).
*/

#include <iostream>     // std::cout
#include <vector>       // std::vector

using std::cout;
using std::endl;

int main() {
    int rows = 5;
    int cols[] = {10, 7, 11, 4, 1};
    std::vector< std::vector<float> > vvec(rows);    

    for (int i=0; i<rows; i++) {
        vvec[i] = std::vector<float>(cols[i]);
        for (int j=0; j<cols[i]; j++) {
            vvec[i][j] = j/((i+1)*10.0);
        }
    }

    cout.precision(5);
    cout.setf(std::ios::fixed, std::ios::floatfield);

    // Iterate method 1
    //for (int i=0; i<rows; i++) {
    //    for (int j=0; j<vvec[i].size(); j++) {
    //        cout << vvec[i][j] << " ";
    //    }

    // Iterate method 2
    for (int i=0; i<rows; i++) {
        for (auto& val: vvec[i]) {
            cout << val << " ";
        }
    cout << endl;
    }


    return 0;
}
