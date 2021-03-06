#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include <string>

class Player
{
private:
    std::string name {"Oaf"};
    int intelligence {0};
    int strength {0};
    int wisdom {0};
    int charisma {0};
    double gold {0.0};
    bool isOverBurdened {false}; // is the player's inventory at max capacity

public:
    // Constructors
    Player(std::string nom, int intel, int stren, int wis, int charis);

    // Destructor
    ~Player();

    size_t getCharisma() const;
    void listPlayer() const;
};
#endif
