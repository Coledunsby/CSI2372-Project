//
//  tile.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "tile.h"

/* ===============================================================
 Tile
=============================================================== */

#pragma mark - Tile

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
    cout << tile->getType() << ": " << tile->getAction() << endl;
    
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
    for (Player p : players) {
        if (p == player) {
            return true;
        }
    }
    return false;
}

int Tile::getIdentifier() const {
    return identifier;
}

vector<Player> Tile::getPlayers() const {
    return players;
}


/* ===============================================================
 Desert
=============================================================== */

#pragma mark - Desert

Desert::Desert() {
    
}

bool Desert::action(Player& player) {
    return false;
}

string Desert::getType() const {
    return "Desert";
}

string Desert::getAction() const {
    return "No action possible on this tile.";
}

bool Desert::hasAction() const {
    return false;
}


/* ===============================================================
 Restaurant
=============================================================== */

#pragma mark - Restaurant

Restaurant::Restaurant() {
    
}

bool Restaurant::action(Player& player) {
    player.setFood(10);
    return true;
}

string Restaurant::getType() const {
    return "Restaurant";
}

string Restaurant::getAction() const {
    return "Your food has been replenished!";
}

bool Restaurant::hasAction() const {
    return false;
}


/* ===============================================================
 SpiceMerchant
=============================================================== */

#pragma mark - SpiceMerchant

SpiceMerchant::SpiceMerchant() {
    
}

bool SpiceMerchant::action(Player& player) {
    if (player.getGold() >= (2 + players.size() - 1)) {
        player.setGold(player.getGold() - 2);
        player.setSpice(player.getSpice() + std::min(player.emptySpace(), 3));
        return true;
    } else {
        return false;
    }
}

string SpiceMerchant::getType() const {
    return "Spice Merchant";
}

string SpiceMerchant::getAction() const {
    return "Trade 2 pieces of gold for 3 sacks of spices?";
}

bool SpiceMerchant::hasAction() const {
    return true;
}


/* ===============================================================
 FabricManufacturer
=============================================================== */

#pragma mark - FabricManufacturer

FabricManufacturer::FabricManufacturer() {
    
}

bool FabricManufacturer::action(Player& player) {
    if (player.getGold() >= (2 + players.size() - 1)) {
        player.setGold(player.getGold() - 2);
        player.setFabric(player.getFabric() + std::min(player.emptySpace(), 3));
        return true;
    } else {
        return false;
    }
}

string FabricManufacturer::getType() const {
    return "Fabric Manufacturer";
}

string FabricManufacturer::getAction() const {
    return "Trade 2 pieces of gold for 3 rolls of fabrics?";
}

bool FabricManufacturer::hasAction() const {
    return true;
}


/* ===============================================================
 Jeweler
=============================================================== */

#pragma mark - Jeweler

Jeweler::Jeweler() {
    
}

bool Jeweler::action(Player& player) {
    if (player.getGold() >= (2 + players.size() - 1)) {
        player.setGold(player.getGold() - 2);
        player.setJewel(player.getJewel() + std::min(player.emptySpace(), 3));
        return true;
    } else {
        return false;
    }
}

string Jeweler::getType() const {
    return "Jeweler";
}

string Jeweler::getAction() const {
    return "Trade 2 pieces of gold for 3 pieces of jewelry?";
}

bool Jeweler::hasAction() const {
    return true;
}


/* ===============================================================
 CartManufacturer
=============================================================== */

#pragma mark - CartManufacturer

CartManufacturer::CartManufacturer() {
    
}

bool CartManufacturer::action(Player& player) {
    if (player.getGold() >= (7 + players.size() - 1)) {
        player.setGold(player.getGold() - 7);
        player.setCart(player.getCart() + 3);
        return true;
    } else {
        return false;
    }
}

string CartManufacturer::getType() const {
    return "Cart Manufacturer";
}

string CartManufacturer::getAction() const {
    return "Increase your cart capacity by 3 for 7 gold?";
}

bool CartManufacturer::hasAction() const {
    return true;
}


/* ===============================================================
 SmallMarket
=============================================================== */

#pragma mark - SmallMarket

SmallMarket::SmallMarket() {
    
}

bool SmallMarket::action(Player& player) {
    if (player.getFabric() >= 1 && player.getJewel() >= 1 && player.getSpice() >= 1) {
        player.setFabric(player.getFabric() - 1);
        player.setJewel(player.getJewel() - 1);
        player.setSpice(player.getSpice() - 1);
        player.setGold(player.getGold() + 8);
        return true;
    } else {
        return false;
    }
}

string SmallMarket::getType() const {
    return "Small Market";
}

string SmallMarket::getAction() const {
    return "Trade 1 roll of fabric, 1 jewel and 1 sack of spices for 8 gold?";
}

bool SmallMarket::hasAction() const {
    return true;
}


/* ===============================================================
 SpiceMarket
=============================================================== */

#pragma mark - SpiceMarket

SpiceMarket::SpiceMarket() {
    
}

bool SpiceMarket::action(Player& player) {
    if (player.getSpice() >= 3) {
        player.setSpice(player.getSpice() - 3);
        player.setGold(player.getGold() + 6);
        return true;
    } else {
        return false;
    }
}

string SpiceMarket::getType() const {
    return "Spice Market";
}

string SpiceMarket::getAction() const {
    return "Sell 3 sacks of spices for 6 gold?";
}

bool SpiceMarket::hasAction() const {
    return true;
}


/* ===============================================================
 JewelryMarket
=============================================================== */

#pragma mark - JewelryMarket

JewelryMarket::JewelryMarket() {
    
}

bool JewelryMarket::action(Player& player) {
    if (player.getJewel() >= 3) {
        player.setJewel(player.getJewel() - 3);
        player.setGold(player.getGold() + 6);
        return true;
    } else {
        return false;
    }
}

string JewelryMarket::getType() const {
    return "Jewelry Market";
}

string JewelryMarket::getAction() const {
    return "Sell 3 pieces of jewelry for 6 gold?";
}

bool JewelryMarket::hasAction() const {
    return true;
}


/* ===============================================================
 FabricMarket
=============================================================== */

#pragma mark - FabricMarket

FabricMarket::FabricMarket() {
    
}

bool FabricMarket::action(Player& player) {
    if (player.getFabric() >= 3) {
        player.setFabric(player.getFabric() - 3);
        player.setGold(player.getGold() + 6);
        return true;
    } else {
        return false;
    }
}

string FabricMarket::getType() const {
    return "Fabric Market";
}

string FabricMarket::getAction() const {
    return "Sell 3 rolls of fabric for 6 gold?";
}

bool FabricMarket::hasAction() const {
    return true;
}


/* ===============================================================
 BlackMarket
=============================================================== */

#pragma mark - BlackMarket

BlackMarket::BlackMarket() {
    
}

bool BlackMarket::action(Player& player) {
    if (player.getGold() >= (1 + players.size() - 1) && player.emptySpace() > 0) {
        srand(unsigned(time(0)));
        int randNum = rand() % 5;
        
        while (randNum > 0 && player.emptySpace() > 0) {
            int goodType = rand() % 4;
            
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

string BlackMarket::getType() const {
    return "Black Market";
}

string BlackMarket::getAction() const {
    return "Get between 0 and 5 goods at random for 1 gold?";
}

bool BlackMarket::hasAction() const {
    return true;
}


/* ===============================================================
 Casino
=============================================================== */

#pragma mark - Casino

Casino::Casino() {
    
}

bool Casino::action(Player& player) {
    if (player.getGold() >= (1 + players.size() - 1)) {
        srand(unsigned(time(0)));
        int randNum = rand() % 10 + 1;
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
        
        cout << "You won " << winnings << " gold!" << endl;
        cout << endl;
        
        return true;
    } else {
        return false;
    }
}

string Casino::getType() const {
    return "Casino";
}

string Casino::getAction() const {
    return "Gamble for 1 gold (could win 0 (40%), 2 (30%), 3 (20%), or 10 (10%) gold)?";
}

bool Casino::hasAction() const {
    return true;
}


/* ===============================================================
 GemMerchant
=============================================================== */

#pragma mark - GemMerchant

GemMerchant::GemMerchant() {
    previousBuyers = 0;
}

bool GemMerchant::action(Player& player) {
    int cost = 12 + previousBuyers;
    if (player.getGold() >= (cost + players.size() - 1) && player.emptySpace() > 0) {
        player.setGold(player.getGold() - cost);
        player.setRuby(player.getRuby() + 1);
        previousBuyers++;
        return true;
    } else {
        return false;
    }
}

string GemMerchant::getType() const {
    return "Gem Merchant";
}

string GemMerchant::getAction() const {
    int cost = 12 + previousBuyers;
    return "Buy a ruby for " + to_string(cost) + " gold?";
}

bool GemMerchant::hasAction() const {
    return true;
}


/* ===============================================================
 Palace
=============================================================== */

#pragma mark - Palace

Palace::Palace() {
    
}

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

string Palace::getType() const {
    return "Palace";
}

string Palace::getAction() const {
    return "Trade 5 rolls of fabric, 5 pieces of jewelry and 5 sacks of spices for 1 ruby?";
}

bool Palace::hasAction() const {
    return true;
}
