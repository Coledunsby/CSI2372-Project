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

/* ------------------------------------------------------------------
 TileFactory
 ----------------------------------------------------------------- */

TileFactory::TileFactory(int _nTiles) {
    
}

/*
TileFactory* TileFactory::get(int _nTiles) {
    static TileFactory tf(_nTiles);
    return &tf;
}
 */

Tile* TileFactory::next() {
    return nullptr;
}

/* ------------------------------------------------------------------
 Black Market
 ----------------------------------------------------------------- */

bool BlackMarket::action(Player &player) {
    if (player.getGold() >= 1) {
        srand(static_cast<unsigned int>(time(0)));
        int randNum = std::rand() % 5;
        
        while (randNum > 0 && (player.getSpice() + player.getFabric() + player.getJewel() + player.getRuby() < player.getCart())) {
            int goodType = std::rand() % 4;
            
            // Random number between 0 and 3
            // 0 = spice
            // 1 = fabric
            // 2 = jewel
            // 3 = ruby
            
            if (goodType == 0) {
                player.setSpice(player.getSpice() + 1);
            } else if (goodType == 1) {
                player.setFabric(player.getFabric() + 1);
            } else if (goodType == 2) {
                player.setJewel(player.getJewel() + 1);
            } else {
                player.setRuby(player.getRuby() + 1);
            }
            
            randNum--;
        }
        
        return true;
    } else {
        return false;
    }
}

/* ------------------------------------------------------------------
 Casino
 ----------------------------------------------------------------- */

bool Casino::action(Player &player) {
    if (player.getGold() >= 1) {
        srand(static_cast<unsigned int>(time(0)));
        int randNum = std::rand() % 10 + 1;
        int winnings = 0;
        
        // Random number between 1 and 10
        // 1  =  0 gold (2/5)
        // 2  =  0 gold (2/5)
        // 3  =  0 gold (2/5)
        // 4  =  0 gold (2/5)
        // 5  =  2 gold (3/10)
        // 6  =  2 gold (3/10)
        // 7  =  2 gold (3/10)
        // 8  =  3 gold (2/10)
        // 9  =  3 gold (2/10)
        // 10 = 10 gold (1/10)
        
        if (randNum >= 5 && randNum <= 7) {
            winnings = 2;
        } else if (randNum >= 8 && randNum <= 9) {
            winnings = 3;
        } else if (randNum == 10) {
            winnings = 10;
        }
        
        player.setGold(player.getGold() - 1 + winnings);
        
        return true;
    } else {
        return false;
    }
}

/* ------------------------------------------------------------------
 Gem Merchant
 ----------------------------------------------------------------- */

GemMerchant::GemMerchant() {
    previousBuyers = 0;
}

bool GemMerchant::action(Player& player) {
    int cost = 12 + previousBuyers;
    if (player.getGold() >= cost) {
        previousBuyers++;
        player.setGold(player.getGold() - cost);
        player.setRuby(player.getRuby() + 1);
        return true;
    } else {
        return false;
    }
}

/* ------------------------------------------------------------------
 Palace
 ----------------------------------------------------------------- */

bool Palace::action(Player& player) {
    if (player.getFabric() >= 5 && player.getJewel() >= 5 && player.getSpice() >= 5) {
        player.setFabric(player.getFabric() - 5);
        player.setJewel(player.getJewel() - 5);
        player.setSpice(player.getSpice() - 5);
        player.setRuby(player.getRuby() + 1);
        return true;
    } else {
        return false;
    }
}