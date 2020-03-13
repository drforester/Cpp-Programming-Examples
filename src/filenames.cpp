#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

vector<string> split_string(const string& str, const string& delimiter);
void printStrVec(const vector<string> Vec);

int main()
{

    const string filename = "/home/zippy/Documents/synths/arturia.txt";

    /* Illustrating  std::string::find_last_of */
    std::size_t found = filename.find_last_of("/");
    cout << " path: " << filename.substr(0,found) << "\n";
    cout << " file: " << filename.substr(found+1) << "\n\n";


    /* Illustrating a custom string splitting function */
    // break file string into separate strings
    vector<string> fnVec1 = split_string(filename, "/"); // split on dir separator
    printStrVec(fnVec1);
    // perhaps we want to see only the name of the file
    string fnStr1 = fnVec1[fnVec1.size()-1]; // last elem in vector
    cout << fnStr1 << "\n";
    // what if we only want the name without the file extension?
    vector<string> fnVec2 = split_string(fnStr1, "."); // split on dir separator
    string fnStr2 = fnVec2[0];
    cout << fnStr2 << "\n";
}


vector<string> split_string(const string& str, const string& delimiter) {
    vector<string> strings;
    string::size_type pos = 0;
    string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != string::npos) {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    strings.push_back(str.substr(prev));

    return strings;
}

void printStrVec(const vector<string> Vec) {
    for (auto& e: Vec)
        cout << e << " ";
    cout << "\n";
}
