/*

*/

#include <iostream>
#include <vector>
#include <algorithm>    // std::generate, std::sort
#include "Player.h"

using std::cout;

bool sortAsc(Player a, Player b) { 
    return (a.getCharisma()<b.getCharisma()); }

int main()
{   
    Player p001("Amwrath", 10,11,12,13);
    Player p002("Xenia", 15,11,15,16);
    Player p003("Galen", 16,10,17,14);
 
    std::vector<Player> playersVec;
    playersVec.push_back(p001);
    playersVec.push_back(p002);
    playersVec.push_back(p003);

    // sort vector according to players' charisma
    std::sort(playersVec.begin(), playersVec.end(), sortAsc);
    
    // print vector elements
    for (auto& e: playersVec)
        e.listPlayer();

    // how many players have been instantiated?
    cout << "number of players: " << playersVec[0].getPlayerCount() << "\n";

    // remove a player
    p003.removePlayer(); 

    // print vector elements
    for (auto& e: playersVec)
        e.listPlayer();

}
