//
//  player.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "player.h"

Player::Player() {
    gold = 5;
    ruby = 0;
    spice = 1;
    fabric = 1;
    jewel = 1;
    cart = 9;
    food = 10;
}

bool Player::canAct() const {
    return food > 0;
}

bool Player::pay(Player &player) {
    return true;
}

void Player::eat() {
    if (food > 0) {
        food--;
    }
}