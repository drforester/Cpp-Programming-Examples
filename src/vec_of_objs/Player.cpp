#include <iostream>
#include "Player.h"


// Constructor
Player::Player(std::string nom, int intel, int stren, int wis, int charis) {
    name = nom;
    intelligence = intel;
    strength = stren;
    wisdom = wis;
    charisma = charis;
    ++playerCount;
}

Player::Player() {
    ++playerCount;
}

// Destructor
Player::~Player() {}

void Player::removePlayer() {
    --playerCount;
}

size_t Player::getCharisma() const {
    return charisma;
}

size_t Player::getPlayerCount() const {
    return playerCount;
}

void Player::listPlayer() const {
    std::cout << name << "(" 
              << intelligence << ',' 
              << strength  << ',' 
              << wisdom << ','
              << charisma
              << ")\n";
}
