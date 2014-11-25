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
#include <iostream>

template <class T, class J, const int R, const int C>
class GameBoard {
    enum class Move { Up, Down, Left, Right };
    
public:
    GameBoard();
    GameBoard(std::vector<J> players);
    void add(const T& tile, int row, int col);
    const T& getTile(int row, int col) const;
    void getCoordinate(const T &tile, int *row, int *col) const;
    void setPlayer(J player);
    J getPlayer(const std::string& playerName);
    const T& getTile(const std::string& playerName) const;
    std::vector<J> getPlayers(const T& tile) const;
    const T& move(enum Move move, const std::string& playerName);
    void draw() const;
};

#include "gameboard.cpp"

#endif /* defined(__CSI2372_Project__gameboard__) */
