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
    virtual string getType() const { return ""; }// = 0
    virtual string getAction() const = 0;
    friend ostream &operator<<(ostream &output, const Tile *tile);
    void addPlayer(Player& player);
    void addPlayers(vector<Player> newPlayers);
    void removePlayer(Player& player);
    bool isOnTile(Player& player);
    int getIdentifier() const;
    vector<Player> getPlayers() const;
};

class Desert: public Tile {
public:
    Desert();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class Restaurant: public Tile {
public:
    Restaurant();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class SpiceMerchant: public Tile {
public:
    SpiceMerchant();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class FabricManufacturer: public Tile {
public:
    FabricManufacturer();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class Jeweler: public Tile {
public:
    Jeweler();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class CartManufacturer: public Tile {
public:
    CartManufacturer();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class SmallMarket: public Tile {
public:
    SmallMarket();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class SpiceMarket: public Tile {
public:
    SpiceMarket();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class JewelryMarket: public Tile {
public:
    JewelryMarket();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class FabricMarket: public Tile {
public:
    FabricMarket();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class BlackMarket: public Tile {
public:
    BlackMarket();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class Casino: public Tile {
public:
    Casino();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class GemMerchant: public Tile {
    int previousBuyers;
    
public:
    GemMerchant();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

class Palace: public Tile {
public:
    Palace();
    bool action(Player& player);
    string getType() const;
    string getAction() const;
};

#endif /* defined(__CSI2372_Project__tile__) */
