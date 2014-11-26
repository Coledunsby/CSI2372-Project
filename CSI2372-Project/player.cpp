//
//  player.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "player.h"

Player::Player(std::string _name) {
    name = _name;
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

// Getters

std::string Player::getName() const {
    return name;
}

int Player::getGold() const {
    return gold;
}

int Player::getRuby() const {
    return ruby;
}

int Player::getSpice() const {
    return spice;
}

int Player::getFabric() const {
    return fabric;
}

int Player::getJewel() const {
    return jewel;
}

int Player::getCart() const {
    return cart;
}

int Player::getFood() const {
    return food;
}

// Setters

void Player::setName(const std::string newName) {
    name = newName;
}

void Player::setGold(const int newGold) {
    gold = newGold;
}

void Player::setRuby(const int newRuby) {
    ruby = newRuby;
}

void Player::setSpice(const int newSpice) {
    spice = newSpice;
}

void Player::setFabric(const int newFabric) {
    fabric = newFabric;
}

void Player::setJewel(const int newJewel) {
    jewel = newJewel;
}

void Player::setCart(const int newCart) {
    cart = newCart;
}

void Player::setFood(const int newFood) {
    food = newFood;
}
