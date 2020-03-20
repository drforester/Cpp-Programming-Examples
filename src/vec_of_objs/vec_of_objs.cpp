/*

*/

#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
#include "Player.h"

using std::cout;

bool sortDesc(Player a, Player b) { 
    return (a.getCharisma()>b.getCharisma()); }

int main()
{   
    Player p001("Amwrath", 10,11,12,13);
    Player p002("Xenia", 15,11,15,16);
    Player p003("Grendel", 14,21,12,8);
    Player p004("Galen", 16,10,17,14);
 
    std::vector<Player> playersVec;
    // move the objects into the vector (not a copy)
    playersVec.push_back(std::move(p001));
    playersVec.push_back(std::move(p002));
    playersVec.push_back(std::move(p003));
    playersVec.push_back(std::move(p004));

    // sort vector according to players' charisma
    std::sort(playersVec.begin(), playersVec.end(), sortDesc);
    
    // print vector elements
    cout << "Players sorted by charisma:\n";
    for (auto& e: playersVec)
        e.listPlayer();
    cout << "\n";

    // pop from the vector the player with lowest charisma
    playersVec.pop_back();
    cout << "Player with lowest charisma dropped from vector:\n";

    // print vector elements
    for (auto& e: playersVec)
        e.listPlayer();

}
