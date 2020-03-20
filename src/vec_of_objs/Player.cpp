#include <iostream>
#include "Player.h"


// Constructor
Player::Player(std::string nom, int intel, int stren, int wis, int charis) {
    name = nom;
    intelligence = intel;
    strength = stren;
    wisdom = wis;
    charisma = charis;
}

// Destructor
Player::~Player() {}

size_t Player::getCharisma() const {
    return charisma;
}

void Player::listPlayer() const {
    std::cout << name << "(" 
              << intelligence << ',' 
              << strength  << ',' 
              << wisdom << ','
              << charisma
              << ")\n";
}
