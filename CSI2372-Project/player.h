//
//  player.h
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#ifndef __CSI2372_Project__player__
#define __CSI2372_Project__player__

#include <iostream>
#include <string>

using namespace std;

class Player {
    string name;
    int gold;
    int ruby;
    int spice;
    int fabric;
    int jewel;
    int cart;
    int food;
    
public:
    Player(string _name);
    bool canAct() const;
    bool pay(Player& player);
    void eat();
    int emptySpace();
    friend ostream &operator<<(ostream &output, const Player &player);
    
    // Getters
    string getName() const;
    int getGold() const;
    int getRuby() const;
    int getSpice() const;
    int getFabric() const;
    int getJewel() const;
    int getCart() const;
    int getFood() const;
    
    // Setters
    void setName(const string newName);
    void setGold(const int newGold);
    void setRuby(const int newRuby);
    void setSpice(const int newSpice);
    void setFabric(const int newFabric);
    void setJewel(const int newJewel);
    void setCart(const int newCart);
    void setFood(const int newFood);
};

#endif /* defined(__CSI2372_Project__player__) */
