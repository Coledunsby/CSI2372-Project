//
//  gameboard.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "gameboard.h"

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::add(const T& tile, int row, int col) {
    
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(int row, int col) const {
    
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::getCoordinate(const T &tile, int *row, int *col) const {
    
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::setPlayer(J player) {
    
}

template <class T, class J, const int R, const int C>
J GameBoard<T, J, R, C>::getPlayer(const std::string &playerName) {
    
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(const std::string &playerName) const {
    
}

template <class T, class J, const int R, const int C>
std::vector<J> GameBoard<T, J, R, C>::getPlayers(const T &tile) const {
    
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::move(enum Move move, const std::string &playerName) {
    
}
