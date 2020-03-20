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
    bool isOverBurdened {false};

public:
    // Constructors
    Player(std::string nom, int intel, int stren, int wis, int charis) {
        name = nom;
        intelligence = intel;
        strength = stren;
        wisdom = wis;
        charisma = charis;
    }

    Player() = default;     // No-arg constructor

    int getCharisma() {
        return charisma;
    }

    void listPlayer() const {
        std::cout << name << "(" 
                  << intelligence << ',' 
                  << strength  << ',' 
                  << wisdom << ','
                  << charisma
                  << ")\n";
    }
};
#endif
