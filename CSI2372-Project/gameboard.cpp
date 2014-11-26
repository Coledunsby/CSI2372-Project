//
//  gameboard.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-25.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

template <class T, class J, const int R, const int C>
GameBoard<T, J, R, C>::GameBoard() {
    
}

template <class T, class J, const int R, const int C>
GameBoard<T, J, R, C>::GameBoard(std::vector<J> players) {
    
}

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
    J temp("");
    return temp;
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(const std::string &playerName) const {
    
}

template <class T, class J, const int R, const int C>
std::vector<J> GameBoard<T, J, R, C>::getPlayers(const T &tile) const {
    std::vector<J> temp;
    return temp;
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::move(enum Move move, const std::string &playerName) {
    T *temp = new T;
    return *temp;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::draw() const {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            std::cout << "[" << r << "," << c << "]";
        }
        std::cout << std::endl;
    }
}
