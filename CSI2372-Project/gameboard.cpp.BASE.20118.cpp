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
void GameBoard<T, J, R, C>::addPlayer(J player, string name) {
    players[name] = player;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::setPlayer(J player) {
    
}

template <class T, class J, const int R, const int C>
J GameBoard<T, J, R, C>::getPlayer(const string &playerName) {
    return players[playerName];
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::addTile(const T& tile, int row, int col) {
    tiles[row][col] = tile;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::getCoordinate(const T &tile, int *row, int *col) const {
    
}

template <class T, class J, const int R, const int C>
vector<J> GameBoard<T, J, R, C>::getPlayers(const T &tile) const {
    vector<J> temp;
    return temp;
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(int row, int col) const {
    return tiles[row][col];
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::getTile(const string &playerName) const {
    
}

template <class T, class J, const int R, const int C>
const T& GameBoard<T, J, R, C>::move(enum Move move, const string &playerName) {
    T *temp = new T;
    return *temp;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::draw() const {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << "[" << r << "," << c << "]";
        }
        cout << endl;
    }
}
