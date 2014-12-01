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
GameBoard<T, J, R, C>::GameBoard(vector<J> _players) {
    for (J player : _players) {
        players[player.getName()] = player;
    }
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::setPlayer(J player) {
    
}

template <class T, class J, const int R, const int C>
J GameBoard<T, J, R, C>::getPlayer(const string &playerName) {
    return players[playerName];
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::addTile(T* tile, int row, int col) {
    tiles[row][col] = tile;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::getCoordinate(const T* tile, int *row, int *col) const {
    bool found = false;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (tiles[r][c] == tile) {
                *row = r;
                *col = c;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        *row = -1;
        *col = -1;
    }
}

template <class T, class J, const int R, const int C>
vector<J> GameBoard<T, J, R, C>::getPlayers(const T* tile) const {
    return tile->getPlayers();
}

template <class T, class J, const int R, const int C>
const T* GameBoard<T, J, R, C>::getTile(int row, int col) const {
    return tiles[row][col];
}

template <class T, class J, const int R, const int C>
T* GameBoard<T, J, R, C>::getTile(const string &playerName) {
    T* tile = nullptr;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            J player = getPlayer(playerName);
            if (tiles[r][c]->isOnTile(player)) {
                tile = tiles[r][c];
            }
        }
    }
    return tile;
}

template <class T, class J, const int R, const int C>
T* GameBoard<T, J, R, C>::move(enum Move move, const string& playerName) {
    T* newTile;
    T* currentTile = getTile(playerName);
    J player = players[playerName];
    int xOffset = 0, yOffset = 0;
    int x = 0, y = 0;
    int *currentX = &x, *currentY = &y;
    
    getCoordinate(currentTile, currentX, currentY);
    
    if (move == Move::UP) {
        yOffset = 1;
    } else if (move == Move::DOWN) {
        yOffset = -1;
    } else if (move == Move::LEFT) {
        xOffset = -1;
    } else if (move == Move::RIGHT) {
        xOffset = 1;
    }
    
    int newX = *currentX + xOffset;
    int newY = *currentY + yOffset;
    
    if (newX >= 0 && newX <= C-1 && newY >= 0 && newY <= R-1) {
        currentTile->removePlayer(player);
        newTile->addPlayer(player);
    }
    
    return newTile;
}

template <class T, class J, const int R, const int C>
bool GameBoard<T, J, R, C>::win(const string &playerName) {
    return players[playerName].getRuby() >= 5;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::draw() const {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            const T* tile = getTile(r, c);
            cout << "[" << tile->getIdentifier() << "]";
        }
        cout << endl;
    }
}
