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

using std::cout;
using std::string;

int main()
{
    string world = {'_','/','\\','_','/','/','\\','\\'};
    cout << world << '\n';

    unsigned int h = 0;
    unsigned int h1, h2, il, ir;
    for (unsigned int i=0; i<world.size(); i++) {
        if (world[i] == '/')
            h += 1;
        if (world[i] == '\\')
            h -= 1;
        cout << h << " ";
    }
    cout << '\n';
    
}
