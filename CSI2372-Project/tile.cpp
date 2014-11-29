//
//  tile.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "tile.h"

/* ------------------------------------------------------------------
 Tile
 ----------------------------------------------------------------- */

Tile::Tile() {
    identifier = counter++;
}

bool Tile::operator==(const Tile &t) {
    return false;
}

bool Tile::action(Player &player) {
    return false;
}

Tile* Tile::clone() {
    return nullptr;
}

ostream &operator<<(ostream &output, const Tile &tile) {
    cout << tile.getType() << ": " << tile.getAction();
    
    return output;
}

void Tile::addPlayer(Player& player) {
    players.push_back(player);
}

void Tile::removePlayer(Player& player) {
    players.erase(remove(players.begin(), players.end(), player), players.end());
}

// Getters

int Tile::getIdentifier() const {
    return identifier;
}

vector<Player> Tile::getPlayers() const {
    return players;
}

// Setters

void Tile::setIdentifier(const int newIdentifier) {
    identifier = newIdentifier;
}
