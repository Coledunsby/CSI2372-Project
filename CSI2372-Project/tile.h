//
//  tile.h
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#ifndef __CSI2372_Project__tile__
#define __CSI2372_Project__tile__

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "player.h"

class Tile {
    static int counter;
    const int identifier;
    
protected:
    vector<Player> players;
    
public:
    Tile();
    bool operator==(const Tile &tile);
    virtual bool action(Player& player) = 0;
    virtual Tile* clone();
    virtual string getType() const = 0;
    virtual string getAction() const = 0;
    friend ostream &operator<<(ostream &output, const Tile *tile);
    void addPlayer(Player& player);
    void addPlayers(vector<Player> newPlayers);
    void removePlayer(Player& player);
    bool isOnTile(Player& player);
    
    // Getters
    int getIdentifier() const;
    vector<Player> getPlayers() const;
};

class Desert: public Tile {
public:
    Desert() {
        
    }
    
    bool action(Player& player) {
        return false;
    }
    
    string getType() const {
        return "Desert";
    }
    
    string getAction() const {
        return "No action possible on this tile.";
    }
};

class Restaurant: public Tile {
public:
    Restaurant() {
        
    }
    
    bool action(Player& player) {
        player.setFood(10);
        return true;
    }
    
    string getType() const {
        return "Restaurant";
    }
    
    string getAction() const {
        return "Your food has been replenished!";
    }
};

class SpiceMerchant: public Tile {
public:
    SpiceMerchant() {
        
    }
    
    bool action(Player& player) {
        if (player.getGold() >= (2 + players.size() - 1)) {
            player.setGold(player.getGold() - 2);
            player.setSpice(player.getSpice() + std::min(player.emptySpace(), 3));
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Spice Merchant";
    }
    
    string getAction() const {
        return "Trade 2 pieces of gold for 3 sacks of spices?";
    }
};

class FabricManufacturer: public Tile {
public:
    FabricManufacturer() {
        
    }
    
    bool action(Player& player) {
        if (player.getGold() >= (2 + players.size() - 1)) {
            player.setGold(player.getGold() - 2);
            player.setFabric(player.getFabric() + std::min(player.emptySpace(), 3));
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Fabric Manufacturer";
    }
    
    string getAction() const {
        return "Trade 2 pieces of gold for 3 rolls of fabrics?";
    }
};

class Jeweler: public Tile {
public:
    Jeweler() {
        
    }
    
    bool action(Player& player) {
        if (player.getGold() >= (2 + players.size() - 1)) {
            player.setGold(player.getGold() - 2);
            player.setJewel(player.getJewel() + std::min(player.emptySpace(), 3));
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Jeweler";
    }
    
    string getAction() const {
        return "Trade 2 pieces of gold for 3 pieces of jewelry?";
    }
};

class CartManufacturer: public Tile {
public:
    CartManufacturer() {
        
    }
    
    bool action(Player& player) {
        if (player.getGold() >= (7 + players.size() - 1)) {
            player.setGold(player.getGold() - 7);
            player.setCart(player.getCart() + 3);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Cart Manufacturer";
    }
    
    string getAction() const {
        return "Increase your cart capacity by 3 for 7 gold?";
    }
};

class SmallMarket: public Tile {
public:
    SmallMarket() {
        
    }
    
    bool action(Player& player) {
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
    
    string getType() const {
        return "Small Market";
    }
    
    string getAction() const {
        return "Trade 1 roll of fabric, 1 jewel and 1 sack of spices for 8 gold?";
    }
};

class SpiceMarket: public Tile {
public:
    SpiceMarket() {
        
    }
    
    bool action(Player& player) {
        if (player.getSpice() >= 3) {
            player.setSpice(player.getSpice() - 3);
            player.setGold(player.getGold() + 6);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Spice Market";
    }
    
    string getAction() const {
        return "Sell 3 sacks of spices for 6 gold?";
    }
};

class JewelryMarket: public Tile {
public:
    JewelryMarket() {
        
    }
    
    bool action(Player& player) {
        if (player.getJewel() >= 3) {
            player.setJewel(player.getJewel() - 3);
            player.setGold(player.getGold() + 6);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Jewelry Market";
    }
    
    string getAction() const {
        return "Sell 3 pieces of jewelry for 6 gold?";
    }
};

class FabricMarket: public Tile {
public:
    FabricMarket() {
        
    }
    
    bool action(Player& player) {
        if (player.getFabric() >= 3) {
            player.setFabric(player.getFabric() - 3);
            player.setGold(player.getGold() + 6);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Fabric Market";
    }
    
    string getAction() const {
        return "Sell 3 rolls of fabric for 6 gold?";
    }
};

class BlackMarket: public Tile {
public:
    BlackMarket() {
        
    }
    
    bool action(Player& player) {
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
    
    string getType() const {
        return "Black Market";
    }
    
    string getAction() const {
        return "Get between 0 and 5 goods at random for 1 gold?";
    }
};

class Casino: public Tile {
public:
    Casino() {
        
    }
    
    bool action(Player& player) {
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
            
            return true;
        } else {
            return false;
        }
    }
    
    string getType() const {
        return "Casino";
    }
    
    string getAction() const {
        return "Gamble for 1 gold (could win 0 (40%), 2 (30%), 3 (20%), or 10 (10%) gold)?";
    }
};

class GemMerchant: public Tile {
    int previousBuyers;
    
public:
    GemMerchant() {
        previousBuyers = 0;
    }
    
    bool action(Player& player) {
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
    
    string getType() const {
        return "Gem Merchant";
    }
    
    string getAction() const {
        int cost = 12 + previousBuyers;
        return "Buy a ruby for " + to_string(cost) + " gold?";
    }
};

class Palace: public Tile {
public:
    Palace() {
        
    }
    
    bool action(Player& player) {
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
    
    string getType() const {
        return "Palace";
    }
    
    string getAction() const {
        return "Trade 5 rolls of fabric, 5 pieces of jewelry and 5 sacks of spices for 1 ruby?";
    }
};

#endif /* defined(__CSI2372_Project__tile__) */
