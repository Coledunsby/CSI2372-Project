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
#include <iostream>
#include "player.h"

class Tile {
    
    
public:
    bool operator==(const Tile &t);
    virtual bool action(Player& player);
    virtual Tile* clone();
    //ostream& operator<<;
};

class TileFactory {
    
public:
    TileFactory(int _nTiles);
    static TileFactory *get(int _nTiles) {
        static TileFactory tf(_nTiles);
        return &tf;
    }
    Tile* next(); // return new tile
};

class Desert: public Tile {
    
};

class Restaurant: public Tile {
    bool action(Player& player);
};

class SpiceMerchant: public Tile {
    bool action(Player& player);
};

class FabricManufacturer: public Tile {
    bool action(Player& player);
};

class Jeweler: public Tile {
    bool action(Player& player);
};

class CartManufacturer: public Tile {
    bool action(Player& player);
};

class SmallMarket: public Tile {
    bool action(Player& player);
};

class SpiceMarket: public Tile {
    bool action(Player& player);
};

class Jewelrymarket: public Tile {
    bool action(Player& player);
};

class FabricMarket: public Tile {
    bool action(Player& player);
};

class BlackMarket: public Tile {
    bool action(Player& player);
};

class Casino: public Tile {
    bool action(Player& player);
};

class GemMerchant: public Tile {
    bool action(Player& player);
};

class Palace: public Tile {
    bool action(Player& player);
};

#endif /* defined(__CSI2372_Project__tile__) */
