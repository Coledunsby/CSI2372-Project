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
    int identifier;
    
protected:
    vector<Player> players;
    
public:
    Tile();
    bool operator==(const Tile &tile);
    virtual void action(Player& player) = 0;
    virtual Tile* clone() const = 0;
    virtual string getType() const = 0;
    virtual string getAction() const = 0;
    virtual bool hasAction() const = 0;
    virtual bool canPerformAction(Player& player) const = 0;
    friend ostream &operator<<(ostream &output, const Tile *tile);
    void addPlayer(Player& player);
    void addPlayers(vector<Player> newPlayers);
    void removePlayer(Player& player);
    bool isOnTile(Player& player);
    int getIdentifier() const;
    void setIdentifier(const int newIdentifier);
    vector<Player> getPlayers() const;
};

class Desert: public Tile {
public:
    Desert();
    void action(Player& player);
    Desert* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class Restaurant: public Tile {
public:
    Restaurant();
    void action(Player& player);
    Restaurant* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class SpiceMerchant: public Tile {
public:
    SpiceMerchant();
    void action(Player& player);
    SpiceMerchant* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class FabricManufacturer: public Tile {
public:
    FabricManufacturer();
    void action(Player& player);
    FabricManufacturer* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class Jeweler: public Tile {
public:
    Jeweler();
    void action(Player& player);
    Jeweler* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class CartManufacturer: public Tile {
public:
    CartManufacturer();
    void action(Player& player);
    CartManufacturer* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class SmallMarket: public Tile {
public:
    SmallMarket();
    void action(Player& player);
    SmallMarket* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class SpiceMarket: public Tile {
public:
    SpiceMarket();
    void action(Player& player);
    SpiceMarket* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class JewelryMarket: public Tile {
public:
    JewelryMarket();
    void action(Player& player);
    JewelryMarket* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class FabricMarket: public Tile {
public:
    FabricMarket();
    void action(Player& player);
    FabricMarket* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class BlackMarket: public Tile {
public:
    BlackMarket();
    void action(Player& player);
    BlackMarket* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class Casino: public Tile {
public:
    Casino();
    void action(Player& player);
    Casino* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class GemMerchant: public Tile {
    int previousBuyers;
    int getCost() const;
    
public:
    GemMerchant();
    void action(Player& player);
    GemMerchant* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

class Palace: public Tile {
public:
    Palace();
    void action(Player& player);
    Palace* clone() const;
    string getType() const;
    string getAction() const;
    bool hasAction() const;
    bool canPerformAction(Player& player) const;
};

#endif /* defined(__CSI2372_Project__tile__) */
