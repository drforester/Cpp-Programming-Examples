#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split_string(const std::string& str,
                                      const std::string& delimiter) {
    std::vector<std::string> strings;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos) {
        strings.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }

    // To get the last substring (or only, if delimiter is not found)
    strings.push_back(str.substr(prev));

    return strings;
}


/*
example of usage:

    #include misc_utils.hpp

    ...
    vector<string> fnVec1 = split_string(filename, "/"); // split on dir separator
    string fnStr1 = fnVec1[fnVec1.size()-1]; // last elem in vector
    vector<string> fnVec2 = split_string(fnStr1, "."); // split on file extension dot
    string fnStr2 = fnVec2[0]; // first elem in vector
    cout << "FILENAME THING : " << fnStr2 << "\n";

*/
