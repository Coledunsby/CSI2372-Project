//
//  player.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "player.h"

Player::Player() {
    setDefaults();
}

Player::Player(string _name) {
    name = _name;
    setDefaults();
}

void Player::setDefaults() {
    gold = 5;
    ruby = 0;
    spice = 1;
    fabric = 1;
    jewel = 1;
    cart = 9;
    food = 10;
}

bool Player::operator==(const Player &p) {
    return (name == p.name);
}

bool Player::canAct() const {
    return food > 0;
}

bool Player::pay(Player &player) {
    if (gold >= 1) {
        gold--;
        player.gold++;
        return true;
    } else {
        return false;
    }
}

void Player::eat() {
    if (food > 0) {
        food--;
    }
}

int Player::emptySpace() {
    return cart - (spice + fabric + jewel + ruby);
}

ostream &operator<<(ostream &output, const Player &player) {
    cout << "|------------" << endl;
    cout << "|" << player.name << endl;
    cout << "|------------" << endl;
    cout << "|Gold:   " << player.gold << endl;
    cout << "|Rubies: " << player.ruby << endl;
    cout << "|Spices: " << player.spice << endl;
    cout << "|Fabric: " << player.fabric << endl;
    cout << "|Jewels: " << player.jewel << endl;
    cout << "|Cart:   " << player.cart << endl;
    cout << "|Food:   " << player.food << endl;
    cout << "|------------" << endl;
    
    return output;
}

// Getters

string Player::getName() const {
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

void Player::setName(const string newName) {
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
