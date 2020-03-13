/*

Based on the implementation found here:
https://www.geeksforgeeks.org/lru-cache-implementation/
*/

#include <iostream>
#include <list>
#include <unordered_map>

using std::cout;
using std::list;
using std::unordered_map;

class LRUCache {
    list<int> keysList;
    unordered_map<int, list<int>::iterator> umap;
    int szcache;

public:
    LRUCache(int);
    void refer(int);
    void display();  
};


// Constructor
LRUCache::LRUCache(int n) {
    szcache = n;
}


// Refer key x within the LRU cache
void LRUCache::refer(int x) {
    if (umap.find(x) == umap.end()) { // if key not in cache
        cout << x << " : miss\n";
        if (keysList.size() == szcache) { // if cache is full
            int last = keysList.back(); // copy the last element
            keysList.pop_back(); // remove the last element from the list
            umap.erase(last); // removes the last element from mapping
        }
    }
    else { // key is in cache
        cout << x << " : hit\n";
        keysList.erase(umap[x]);
    }

    // update the reference
    keysList.push_front(x);
    umap[x] = keysList.begin();
}


// Display the contents of the cache
void LRUCache::display() {
    for (auto& e: keysList)
        cout << e << " ";
    cout << "\n";
}


int main()
{
    LRUCache lruc(4);

    lruc.refer(1);
    lruc.refer(2);
    lruc.refer(3);
    lruc.refer(1);
    lruc.refer(4);
    lruc.refer(5);

    lruc.display();
}
