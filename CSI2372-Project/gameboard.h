//
//  gameboard.h
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#ifndef __CSI2372_Project__gameboard__
#define __CSI2372_Project__gameboard__

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

enum class Move { UP, DOWN, LEFT, RIGHT };

template <class T, class J, const int R, const int C>
class GameBoard {
    map<string, J> players;
    T* tiles[R][C];
    
public:
    GameBoard();
    GameBoard(vector<J> _players);
    J getPlayer(const string& playerName);
    void setPlayer(J player);
    void addTile(T* tile, int row, int col);
    void getCoordinate(const T* tile, int *row, int *col) const;
    vector<J> getPlayers(const T* tile) const;
    T* getTile(int row, int col) const;
    T* getTile(const string& playerName);
    T* move(enum Move move, const string& playerName);
    bool win(const string& playerName);
    void draw() const;
    
    friend ostream& operator<<(ostream &os, GameBoard& GameBoard){
           os << GameBoard;
           return os;
    friend istream& operator>>(istream& istream, GameBoard& GameBoard){
           is >> GameBoard;
           return is;
};

#include "gameboard.cpp"

#endif /* defined(__CSI2372_Project__gameboard__) */
