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
    ostream& operator<<;
};

class TileFactory {
    
};

class Desert: public Tile {
    
};

class Restaurant: public Tile {
    
};

class SpiceMerchant: public Tile {
    
};

class FabricManufacturer: public Tile {
    
};

class Jeweler: public Tile {
    
};

class CartManufacturer: public Tile {
    
};

class SmallMarket: public Tile {
    
};

class SpiceMarket: public Tile {
    
};

class Jewelrymarket: public Tile {
    
};

class FabricMarket: public Tile {
    
};

class BlackMarket: public Tile {
    
};

class Casino: public Tile {
    
};

class GemMerchant: public Tile {
    
};

class Palace: public Tile {
    
};

#endif /* defined(__CSI2372_Project__tile__) */
