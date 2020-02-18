/*
    UNORDERED_MAP
Unordered map is an associative container that contains key-value pairs with unique keys. Search, insertion, and removal of elements have average constant-time complexity.
Internally, the elements are not sorted in any particular order, but organized into buckets. Which
bucket an element is placed into depends entirely on the hash of its key. This allows fast access
to individual elements, since once the hash is computed, it refers to the exact bucket the element
is placed into. (https://en.cppreference.com/w/cpp/container/unordered_map)

*/

#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;

int main(void)
{
    // Create an unordered_map that maps colors to hex-codes
    std::unordered_map<std::string, std::string> umap = {
        {"RED","#FF0000"},
        {"GREEN","#00FF00"},
        {"BLUE","#0000FF"}
    };
 
    // Add two new entries to the unordered_map using the [] operator
    umap["BLACK"] = "#000000";
    umap["WHITE"] = "#FFFFFF";

    // Insert a key,value pair using the insert function 
    umap.insert(std::make_pair("YELLOW", "#FFFF00"));

    // Iterate and print keys and values (method 1)
    std::unordered_map<std::string, std::string>::iterator itr; 
    cout << "Iterating - Method 1 :" << endl; 
    for (itr = umap.begin(); itr != umap.end(); itr++) { 
        cout << itr->first << "  " << itr->second << endl; 
     }  
 
    // Iterate and print keys and values (method 2)
    cout << "Iterating - Method 2:" << endl;
    for( const auto& n : umap ) {
        std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
    }

    // search for a key in umap
    std::string key = "GREEN"; 
    if (umap.find(key) == umap.end()) 
        cout << key << " not found\n"; 
    else
        cout << "Found " << key << endl; 
 
    return 0;
}
