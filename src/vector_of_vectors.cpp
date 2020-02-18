/*
a vector of vectors
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
    // Initialize the vector of vectors of ints
    // notice that the different vectors can have different lengths 
    vector<vector<int> > vec{ { 1, 2, 3 }, 
                              { 4, 5, 6 }, 
                              { 7, 8, 9, 8, 7 } };

    // Display the 2D vector 
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) 
            cout << vec[i][j] << " "; 
        cout << endl; 
    }

    return 0;  
}
