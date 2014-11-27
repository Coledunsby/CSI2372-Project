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
    
    
public:
    Tile();
    bool operator==(const Tile &t);
    virtual bool action(Player& player);
    virtual Tile* clone();
    virtual string getType();
    //ostream& operator<<;
};

class Desert: public Tile {
public:
    string getType() {
        return "Desert";
    }
};

class Restaurant: public Tile {
public:
    bool action(Player& player) {
        player.setFood(10);
        return true;
    }
    
    string getType() {
        return "Restaurant";
    }
};

class SpiceMerchant: public Tile {
public:
    bool action(Player& player) {
        if (player.getGold() >= 2) {
            player.setGold(player.getGold() - 2);
            player.setSpice(player.getSpice() + std::min(player.emptySpace(), 3));
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Spice Merchant";
    }
};

class FabricManufacturer: public Tile {
public:
    bool action(Player& player) {
        if (player.getGold() >= 2) {
            player.setGold(player.getGold() - 2);
            player.setFabric(player.getFabric() + std::min(player.emptySpace(), 3));
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Fabric Manufacturer";
    }
};

class Jeweler: public Tile {
public:
    bool action(Player& player) {
        if (player.getGold() >= 2) {
            player.setGold(player.getGold() - 2);
            player.setJewel(player.getJewel() + std::min(player.emptySpace(), 3));
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Jeweler";
    }
};

class CartManufacturer: public Tile {
public:
    bool action(Player& player) {
        if (player.getGold() >= 7) {
            player.setGold(player.getGold() - 7);
            player.setCart(player.getCart() + 3);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Cart Manufacturer";
    }
};

class SmallMarket: public Tile {
public:
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
    
    string getType() {
        return "Small Market";
    }
};

class SpiceMarket: public Tile {
public:
    bool action(Player& player) {
        if (player.getSpice() >= 3) {
            player.setSpice(player.getSpice() - 3);
            player.setGold(player.getGold() + 6);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Spice Market";
    }
};

class JewelryMarket: public Tile {
public:
    bool action(Player& player) {
        if (player.getJewel() >= 3) {
            player.setJewel(player.getJewel() - 3);
            player.setGold(player.getGold() + 6);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Jewelry Market";
    }
};

class FabricMarket: public Tile {
public:
    bool action(Player& player) {
        if (player.getFabric() >= 3) {
            player.setFabric(player.getFabric() - 3);
            player.setGold(player.getGold() + 6);
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Fabric Market";
    }
};

class BlackMarket: public Tile {
public:
    bool action(Player& player) {
        if (player.getGold() >= 1 && player.emptySpace() > 0) {
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
    
    string getType() {
        return "Black Market";
    }
};

class Casino: public Tile {
public:
    bool action(Player& player) {
        if (player.getGold() >= 1) {
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
    
    string getType() {
        return "Casino";
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
        if (player.getGold() >= cost && player.emptySpace() > 0) {
            player.setGold(player.getGold() - cost);
            player.setRuby(player.getRuby() + 1);
            previousBuyers++;
            return true;
        } else {
            return false;
        }
    }
    
    string getType() {
        return "Gem Merchant";
    }
};

class Palace: public Tile {
public:
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
    
    string getType() {
        return "Palace";
    }
};

class TileFactory {
    std::vector<Tile> tiles;
    int nTiles;
    int nType;
    int index;
    
public:
    TileFactory(int _nTiles) {
        nTiles = _nTiles;
        nType = floor(nTiles / 14);
        index = -1;
        
        for (int i = 0; i < nType; i++) {
            Restaurant restaurantTile;
            SpiceMerchant spiceMerchantTile;
            FabricManufacturer fabricManufacturerTile;
            Jeweler jewelerTile;
            CartManufacturer cartManufacturerTile;
            SmallMarket smallMarketTile;
            SpiceMarket spiceMarketTile;
            JewelryMarket jewelryMarketTile;
            FabricMarket fabricMarketTile;
            BlackMarket blackMarketTile;
            Casino casinoTile;
            GemMerchant gemMerchantTile;
            Palace palaceTile;
            
            tiles.push_back(restaurantTile);
            tiles.push_back(spiceMerchantTile);
            tiles.push_back(fabricManufacturerTile);
            tiles.push_back(jewelerTile);
            tiles.push_back(cartManufacturerTile);
            tiles.push_back(smallMarketTile);
            tiles.push_back(spiceMarketTile);
            tiles.push_back(jewelryMarketTile);
            tiles.push_back(fabricMarketTile);
            tiles.push_back(blackMarketTile);
            tiles.push_back(casinoTile);
            tiles.push_back(gemMerchantTile);
            tiles.push_back(palaceTile);
        }
        
        while (tiles.size() < nTiles) {
            Desert desertTile;
            tiles.push_back(desertTile);
        }
        
        srand(unsigned(time(0)));
        random_shuffle(tiles.begin(), tiles.end());
    }
    
    static TileFactory *get(int _nTiles) {
        static TileFactory tf(_nTiles);
        return &tf;
    }
    
    Tile& next() {
        index++;
        return tiles[index];
    }
};

#endif /* defined(__CSI2372_Project__tile__) */
