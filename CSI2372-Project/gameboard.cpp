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
J GameBoard<T, J, R, C>::getPlayer(const string &playerName) {
    return players[playerName];
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::setPlayer(J player) {
    players[player.getName()] = player;
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
T* GameBoard<T, J, R, C>::getTile(int row, int col) const {
    if (row >= 0 && row <= R-1 && col >= 0 && col <= C-1) {
        return tiles[row][col];
    } else {
        throw out_of_range("");
    }
}

template <class T, class J, const int R, const int C>
T* GameBoard<T, J, R, C>::getTile(const string &playerName) {
    T* tile = nullptr;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            J player = getPlayer(playerName);
            if (tiles[r][c]->isOnTile(player)) {
                tile = tiles[r][c];
                break;
            }
        }
    }
    return tile;
}

template <class T, class J, const int R, const int C>
T* GameBoard<T, J, R, C>::move(enum Move move, const string& playerName) {
    T* newTile = nullptr;
    T* currentTile = getTile(playerName);
    J player = players[playerName];
    int colOffset = 0, rowOffset = 0;
    int row = 0, col = 0;
    int *currentRow = &row, *currentCol = &col;
    
    getCoordinate(currentTile, currentRow, currentCol);
    
    if (move == Move::UP) {
        rowOffset = -1;
    } else if (move == Move::DOWN) {
        rowOffset = 1;
    } else if (move == Move::LEFT) {
        colOffset = -1;
    } else if (move == Move::RIGHT) {
        colOffset = 1;
    }
    
    int newRow = *currentRow + rowOffset;
    int newCol = *currentCol + colOffset;
    
    if (newRow >= 0 && newRow <= R-1 && newCol >= 0 && newCol <= C-1) {
        newTile = getTile(newRow, newCol);
        newTile->addPlayer(player);
        currentTile->removePlayer(player);
    }
    
    return newTile;
}

template <class T, class J, const int R, const int C>
bool GameBoard<T, J, R, C>::win(const string &playerName) {
    return getPlayer(playerName).getRuby() >= 5;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::draw() const {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            const T* tile = getTile(r, c);
            const int id = tile->getIdentifier();
            if (id < 10) {
                cout << "[" << "0" << id << "]";
            } else {
                cout << "[" << id << "]";
            }
        }
        cout << endl;
    }
}
