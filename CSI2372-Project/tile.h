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
    Tile();
    bool operator==(const Tile &t);
    virtual bool action(Player& player);
    virtual Tile* clone();
    //ostream& operator<<;
};

class TileFactory {
    
public:
    TileFactory(int _nTiles) {
        
    }
    
    static TileFactory *get(int _nTiles) {
        static TileFactory tf(_nTiles);
        return &tf;
    }
    
    Tile& next() {
        Tile *tile = new Tile();
        return *tile;
    }
};

class Desert: public Tile {
    
};

class Restaurant: public Tile {
    bool action(Player& player) {
        player.setFood(10);
        return true;
    }
};

class SpiceMerchant: public Tile {
    bool action(Player& player) {
        if (player.getGold() >= 2) {
             
            player.setGold(player.getGold() - 2);
            player.setSpice(player.getSpice() + 3);
            int goldNum = player.getGold();
            int spiceNum = player.getSpice();
            int rubysNum = player.getRuby();
            int fabricNum = player.getFabric();
            int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
            
            while (itemNum > player.getCart()) {
                player.setSpice(player.getSpice() - 1);
            }
            
            return true;
        } else {
            return false;
        }
    }
};

class FabricManufacturer: public Tile {
    bool action(Player& player){
         if(player.getGold() >= 2){
    player.setGold(player.getGold()-2);
    player.setFabric(player.getFabric()+3);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRuby();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    while (itemNum > player.getCart()){
                player.setFabric(player.getFabric()-1);
                }
                return true;
                }
                else return false;
                }
};

class Jeweler: public Tile {
    bool action(Player& player){
         if(player.getGold() >=2){
    player.setGold(player.getGold()-2);
    player.setJewel(player.getJewel()+3);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRuby();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    while (itemNum > player.getCart()){
                player.setJewel(player.getJewel()-1);
                }
                return true;
                }
                else return false;
                }
};

class CartManufacturer: public Tile {
    bool action(Player& player) {
        if(player.getGold() >= 7){
            
            player.setGold(player.getGold()-7);
            player.setCart(player.getCart()+3);
            return true;
        }
        else return false;
    }
};

class SmallMarket: public Tile {
    bool action(Player& player){
         if(player.getFabric() >=1 && player.getJewel() >=1 && player.getSpice() >=1){
             player.setFabric(player.getFabric()-1);
             player.setJewel(player.getJewel()-1);
             player.setSpice(player.getSpice()-1);
             player.setGold(player.getGold()+8);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRuby();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    while(itemNum > player.getCart()){
                player.setGold(player.getGold()-1);
                }
                return true;
                }
                else return false;  
                }  
};

class SpiceMarket: public Tile {
    bool action(Player& player){
         if(player.getSpice() >=3){
    player.setSpice(player.getSpice()-3);
    player.setGold(player.getGold()+6);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRuby();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    while(itemNum > player.getCart()){
                player.setGold(player.getGold()-1);
                } 
                return true;
                } 
                else return false;
                }
};

class Jewelrymarket: public Tile {
    bool action(Player& player){
         if(player.getJewel() >= 3){
    player.setJewel(player.getJewel()-3);
    player.setGold(player.getGold()+6);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRuby();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    while(itemNum > player.getCart()){
                player.setGold(player.getGold()-1);
                } 
                return true;
                }
                else return false;
                }
};

class FabricMarket: public Tile {
    bool action(Player& player) {
        if (player.getFabric() >= 3) {
            player.setFabric(player.getFabric()-3);
            player.setGold(player.getGold()+6);
    
            int goldNum = player.getGold();
            int spiceNum = player.getSpice();
            int rubysNum = player.getRuby();
            int fabricNum = player.getFabric();
            int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
            while (itemNum > player.getCart()) {
                player.setGold(player.getGold()-1);
            }
            return true;
            
        } else {
            return false;
        }
    }
};

class BlackMarket: public Tile {
    bool action(Player& player) {
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
};

class Casino: public Tile {
    bool action(Player& player) {
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
};

class GemMerchant: public Tile {
    int previousBuyers;
    
    GemMerchant() {
        previousBuyers = 0;
    }
    
    bool action(Player& player) {
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
};

class Palace: public Tile {
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
};

#endif /* defined(__CSI2372_Project__tile__) */
