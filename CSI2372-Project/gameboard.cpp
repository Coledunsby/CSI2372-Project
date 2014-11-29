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
void GameBoard<T, J, R, C>::addPlayer(J &player) {
    players[player.getName()] = player;
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
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (tiles[r][c] == tile) {
                row = &r;
                col = &c;
                break;
            }
        }
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
            for (J player : tiles[r][c]->getPlayers()) {
                if (player == players[playerName]) {
                    return tiles[r][c];
                }
            }
        }
    }
    return tile;
}

template <class T, class J, const int R, const int C>
T* GameBoard<T, J, R, C>::move(enum Move move, const string& playerName) {
    T* temp;
    return temp;
    
    /*
    int rNum = 0;
    int rowofplayer = 0;
    int colofplayer = 0;
    
    const Player* thisPlayer;
    
    for (<vector<Player>::const_iterator i = players.begin(); i != players.end(); ++i) {
        int cNum = 0;
        for (<vector<Player>::const_iterator i2 = i->begin(); i2 != i->end(); ++i) {
            for (vector<Player>::const_iterator i3 = i2->begin(); i3 != i2->end(); ++i3) {
                if (i3->nameOfPlayer == playerName) {
                    thisPlayer = &*i3;
                    
                    if (playerRow != 0) {
                        players[rowofplayer - 1][colofplayer].push_back(*new Player(*thisPlayer));
                        players[rowofplayer][colofplayer].erase(i3);
                        return tiles[rowofplayer - 1][colofplayer];
                    } //print cant move there
                    
                    else if (players[0].begin() + colofplayer != players[0].end() - 1) {
                        players[rowofplayer][colofplayer + 1].push_back(*new Player(*thisPlayer));
                        players[rowofplayer][colofplayer].erase(i3);
                        return tiles[rowofplayer][colofplayer + 1];
                    } //print cant move there
                    
                    else if (playerCol != 0) {
                        players[rowofplayer][colofplayer - 1].push_back(*new Player(*thisPlayer));
                        players[rowofplayer][colofplayer].erase(i3);
                        return tiles[playerRow][colofplayer - 1];
                    } //print cant move there
                    
                    else if (players.begin() + colofplayer != players.end() - 1) {
                        players[rowofplayer + 1][colofplayer].push_back(*new Player(*thisPlayer));
                        players[rowofplayer][colofplayer].erase(i3);
                        return tiles[playerRow + 1][colofplayer];
                    } //print cant move there
                    
                    
                    return tiles[rowofplayer][colofplayer];
                }
                
            }
        }
        colNum++;
    }
    rowNum++;
     */
}

template <class T, class J, const int R, const int C>
bool GameBoard<T, J, R, C>::win(const string &playerName) {
    return players[playerName].getRuby() >= 5;
}

template <class T, class J, const int R, const int C>
void GameBoard<T, J, R, C>::draw() const {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cout << "[" << tiles[r][c]->getType() << "]";
        }
        cout << endl;
    }
}
