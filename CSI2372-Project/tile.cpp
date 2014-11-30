//
//  tile.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "tile.h"

int Tile::counter = 0;

Tile::Tile() : identifier(counter++) {
    
}

bool Tile::operator==(const Tile &tile) {
    return (identifier == tile.identifier);
}

Tile* Tile::clone() {
    return nullptr;
}

ostream &operator<<(ostream &output, const Tile *tile) {
    cout << tile->getType() << ": " << tile->getAction();
    
    return output;
}

void Tile::addPlayer(Player& player) {
    players.push_back(player);
}

void Tile::addPlayers(vector<Player> newPlayers) {
    for (Player player : newPlayers) {
        addPlayer(player);
    }
}

void Tile::removePlayer(Player& player) {
    players.erase(remove(players.begin(), players.end(), player), players.end());
}

bool Tile::isOnTile(Player& player) {
    cout << players.size();
    /*
    for (Player p : players) {
        if (p == player) {
            return true;
        }
    }
     */
    return false;
}

// Getters

int Tile::getIdentifier() const {
    return identifier;
}

vector<Player> Tile::getPlayers() const {
    return players;
}
