/*
find freq of every word in a string, using unordered_map 
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
 
using std::cout;
using std::endl; 
  
int main() 
{ 
    std::string instr = "here we go round the mulberry bush "
                        "the mulberry bush "
                        "the mulberry bush"; 
    
    std::unordered_map<std::string, int> wordFreqs; 
  
    // break the input string into word using stringstream 
    std::stringstream ss(instr);  // used for breaking words 
    std::string word; // to store individual words 
    while (ss >> word) 
        wordFreqs[word]++; 
  
    // iterate over (word,freq) pair and print
    std::unordered_map<std::string, int>:: iterator itr; 
    for (itr = wordFreqs.begin(); itr != wordFreqs.end(); itr++) 
        cout << "(" << itr->first << ", " << itr->second << ")" << endl; 

    return 0; 
} 

