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

string Tile::getType() const {
    return "Tile";
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

void Tile::setPlayers(const vector<Player> newPlayers) {
    players = newPlayers;
}