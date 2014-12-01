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

void Tile::setIdentifier(const int newIdentifier) {
    identifier = newIdentifier;
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

void Desert::action(Player& player) {
    
}

Desert* Desert::clone() const {
    return new Desert(*this);
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

bool Desert::canPerformAction(Player& player) const {
    return false;
}


/* ===============================================================
 Restaurant
=============================================================== */

#pragma mark - Restaurant

Restaurant::Restaurant() {
    
}

void Restaurant::action(Player& player) {
    player.setFood(10);
}

Restaurant* Restaurant::clone() const {
    return new Restaurant(*this);
}

string Restaurant::getType() const {
    return "Restaurant";
}

string Restaurant::getAction() const {
    return "Replenish your food for free?";
}

bool Restaurant::hasAction() const {
    return true;
}

bool Restaurant::canPerformAction(Player& player) const {
    return true;
}


/* ===============================================================
 SpiceMerchant
=============================================================== */

#pragma mark - SpiceMerchant

SpiceMerchant::SpiceMerchant() {
    
}

void SpiceMerchant::action(Player& player) {
    player.setGold(player.getGold() - 2);
    player.setSpice(player.getSpice() + std::min(player.emptySpace(), 3));
}

SpiceMerchant* SpiceMerchant::clone() const {
    return new SpiceMerchant(*this);
}

string SpiceMerchant::getType() const {
    return "SpiceMerchant";
}

string SpiceMerchant::getAction() const {
    return "Trade 2 pieces of gold for 3 sacks of spices?";
}

bool SpiceMerchant::hasAction() const {
    return true;
}

bool SpiceMerchant::canPerformAction(Player& player) const {
    return (player.getGold() >= (2 + players.size() - 1));
}


/* ===============================================================
 FabricManufacturer
=============================================================== */

#pragma mark - FabricManufacturer

FabricManufacturer::FabricManufacturer() {
    
}

void FabricManufacturer::action(Player& player) {
    player.setGold(player.getGold() - 2);
    player.setFabric(player.getFabric() + std::min(player.emptySpace(), 3));
}

FabricManufacturer* FabricManufacturer::clone() const {
    return new FabricManufacturer(*this);
}

string FabricManufacturer::getType() const {
    return "FabricManufacturer";
}

string FabricManufacturer::getAction() const {
    return "Trade 2 pieces of gold for 3 rolls of fabrics?";
}

bool FabricManufacturer::hasAction() const {
    return true;
}

bool FabricManufacturer::canPerformAction(Player& player) const {
    return (player.getGold() >= (2 + players.size() - 1));
}


/* ===============================================================
 Jeweler
=============================================================== */

#pragma mark - Jeweler

Jeweler::Jeweler() {
    
}

void Jeweler::action(Player& player) {
    player.setGold(player.getGold() - 2);
    player.setJewel(player.getJewel() + std::min(player.emptySpace(), 3));
}

Jeweler* Jeweler::clone() const {
    return new Jeweler(*this);
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

bool Jeweler::canPerformAction(Player& player) const {
    return (player.getGold() >= (2 + players.size() - 1));
}


/* ===============================================================
 CartManufacturer
=============================================================== */

#pragma mark - CartManufacturer

CartManufacturer::CartManufacturer() {
    
}

void CartManufacturer::action(Player& player) {
    player.setGold(player.getGold() - 7);
    player.setCart(player.getCart() + 3);
}

CartManufacturer* CartManufacturer::clone() const {
    return new CartManufacturer(*this);
}

string CartManufacturer::getType() const {
    return "CartManufacturer";
}

string CartManufacturer::getAction() const {
    return "Increase your cart capacity by 3 for 7 gold?";
}

bool CartManufacturer::hasAction() const {
    return true;
}

bool CartManufacturer::canPerformAction(Player& player) const {
    return (player.getGold() >= (7 + players.size() - 1));
}


/* ===============================================================
 SmallMarket
=============================================================== */

#pragma mark - SmallMarket

SmallMarket::SmallMarket() {
    
}

void SmallMarket::action(Player& player) {
    player.setFabric(player.getFabric() - 1);
    player.setJewel(player.getJewel() - 1);
    player.setSpice(player.getSpice() - 1);
    player.setGold(player.getGold() + 8);
}

SmallMarket* SmallMarket::clone() const {
    return new SmallMarket(*this);
}

string SmallMarket::getType() const {
    return "SmallMarket";
}

string SmallMarket::getAction() const {
    return "Trade 1 roll of fabric, 1 jewel and 1 sack of spices for 8 gold?";
}

bool SmallMarket::hasAction() const {
    return true;
}

bool SmallMarket::canPerformAction(Player& player) const {
    return (player.getFabric() >= 1 && player.getJewel() >= 1 && player.getSpice() >= 1);
}


/* ===============================================================
 SpiceMarket
=============================================================== */

#pragma mark - SpiceMarket

SpiceMarket::SpiceMarket() {
    
}

void SpiceMarket::action(Player& player) {
    player.setSpice(player.getSpice() - 3);
    player.setGold(player.getGold() + 6);
}

SpiceMarket* SpiceMarket::clone() const {
    return new SpiceMarket(*this);
}

string SpiceMarket::getType() const {
    return "SpiceMarket";
}

string SpiceMarket::getAction() const {
    return "Sell 3 sacks of spices for 6 gold?";
}

bool SpiceMarket::hasAction() const {
    return true;
}

bool SpiceMarket::canPerformAction(Player& player) const {
    return (player.getSpice() >= 3);
}


/* ===============================================================
 JewelryMarket
=============================================================== */

#pragma mark - JewelryMarket

JewelryMarket::JewelryMarket() {
    
}

void JewelryMarket::action(Player& player) {
    player.setJewel(player.getJewel() - 3);
    player.setGold(player.getGold() + 6);
}

JewelryMarket* JewelryMarket::clone() const {
    return new JewelryMarket(*this);
}

string JewelryMarket::getType() const {
    return "JewelryMarket";
}

string JewelryMarket::getAction() const {
    return "Sell 3 pieces of jewelry for 6 gold?";
}

bool JewelryMarket::hasAction() const {
    return true;
}

bool JewelryMarket::canPerformAction(Player& player) const {
    return (player.getJewel() >= 3);
}


/* ===============================================================
 FabricMarket
=============================================================== */

#pragma mark - FabricMarket

FabricMarket::FabricMarket() {
    
}

void FabricMarket::action(Player& player) {
    player.setFabric(player.getFabric() - 3);
    player.setGold(player.getGold() + 6);
}

FabricMarket* FabricMarket::clone() const {
    return new FabricMarket(*this);
}

string FabricMarket::getType() const {
    return "FabricMarket";
}

string FabricMarket::getAction() const {
    return "Sell 3 rolls of fabric for 6 gold?";
}

bool FabricMarket::hasAction() const {
    return true;
}

bool FabricMarket::canPerformAction(Player& player) const {
    return (player.getFabric() >= 3);
}


/* ===============================================================
 BlackMarket
=============================================================== */

#pragma mark - BlackMarket

BlackMarket::BlackMarket() {
    
}

void BlackMarket::action(Player& player) {
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
}

BlackMarket* BlackMarket::clone() const {
    return new BlackMarket(*this);
}

string BlackMarket::getType() const {
    return "BlackMarket";
}

string BlackMarket::getAction() const {
    return "Get between 0 and 5 goods at random for 1 gold?";
}

bool BlackMarket::hasAction() const {
    return true;
}

bool BlackMarket::canPerformAction(Player& player) const {
    return (player.getGold() >= (1 + players.size() - 1) && player.emptySpace() > 0);
}


/* ===============================================================
 Casino
=============================================================== */

#pragma mark - Casino

Casino::Casino() {
    
}

void Casino::action(Player& player) {
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
}

Casino* Casino::clone() const {
    return new Casino(*this);
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

bool Casino::canPerformAction(Player& player) const {
    return (player.getGold() >= (1 + players.size() - 1));
}


/* ===============================================================
 GemMerchant
=============================================================== */

#pragma mark - GemMerchant

GemMerchant::GemMerchant() {
    previousBuyers = 0;
}

int GemMerchant::getCost() const {
    return 12 + previousBuyers;
}

void GemMerchant::action(Player& player) {
    player.setGold(player.getGold() - getCost());
    player.setRuby(player.getRuby() + 1);
    previousBuyers++;
}

GemMerchant* GemMerchant::clone() const {
    return new GemMerchant(*this);
}

string GemMerchant::getType() const {
    return "GemMerchant";
}

string GemMerchant::getAction() const {
    int cost = 12 + previousBuyers;
    return "Buy a ruby for " + to_string(cost) + " gold?";
}

bool GemMerchant::hasAction() const {
    return true;
}

bool GemMerchant::canPerformAction(Player& player) const {
    return (player.getGold() >= (getCost() + players.size() - 1) && player.emptySpace() > 0);
}


/* ===============================================================
 Palace
=============================================================== */

#pragma mark - Palace

Palace::Palace() {
    
}

void Palace::action(Player& player) {
    player.setFabric(player.getFabric() - 5);
    player.setJewel(player.getJewel() - 5);
    player.setSpice(player.getSpice() - 5);
    player.setRuby(player.getRuby() + 1);
}

Palace* Palace::clone() const {
    return new Palace(*this);
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

bool Palace::canPerformAction(Player& player) const {
    return (player.getFabric() >= 5 && player.getJewel() >= 5 && player.getSpice() >= 5);
}
