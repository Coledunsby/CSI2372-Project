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
    player.setfood(10);
};

class SpiceMerchant: public Tile {
    bool action(Player& player);
    player.setGold(player.getGold()-2);
    player.setSpice(player.getSpice()+3);
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for (itemNum > player.getCart()){
                player.setSpice(player.getSpice()-1);
                }   
};

class FabricManufacturer: public Tile {
    bool action(Player& player);
    player.setGold(player.getGold()-2);
    player.setFabric(player.getFabric()+3);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for (itemNum > player.getCart()){
                player.setFabric(player.getFabric()-1);
                }
};

class Jeweler: public Tile {
    bool action(Player& player);
    player.setGold(player.getGold()-2);
    player.setJewlery(player.getJewlery()+3);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for (itemNum > player.getCart()){
                player.setJewlery(player.getJewlery()-1);
                }
};

class CartManufacturer: public Tile {
    bool action(Player& player);
    player.setGold(player.getGold()-7);
    player.setCart(player.getCart()+3);
};

class SmallMarket: public Tile {
    bool action(Player& player);
    player.setFabric(player.getFabric()-1);
    player.setJewlery(player.getJewlery()-1);
    player.setSpice(player.getSpice()-1);
    player.setGold(player.getGold()+8)
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for(itemNum > player.getCart()){
                player.setGold(player.getGold()-1);
                }    
};

class SpiceMarket: public Tile {
    bool action(Player& player);
    player.setSpice(player.getSpice()-3);
    player.setGold(player.getGold()+6);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for(itemNum > player.getCart()){
                player.setGold(player.getGold()-1);
                } 
};

class Jewelrymarket: public Tile {
    bool action(Player& player);
    player.setJewlery(player.getJewlery()-3);
    player.setGold(player.getGold()+6);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for(itemNum > player.getCart()){
                player.setGold(Player::getGold()-1);
                } 
};

class FabricMarket: public Tile {
    bool action(Player& player);
    player.setFabric(player.getFabric()-3);
    player.setGold(player.getGold()+6);
    
    int goldNum = player.getGold();
    int spiceNum = player.getSpice();
    int rubysNum = player.getRubys();
    int fabricNum = player.getFabric();
    int itemNum = goldNum + spiceNum + rubysNum + fabricNum;
    
    for(itemNum > player.getCart()){
                player.setGold(player.getGold()-1);
                } 
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
