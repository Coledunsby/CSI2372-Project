//
//  main.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-10.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include <iostream>
#include "gameboard.h"
#include "tile.h"

#define MIN_PLAYERS 2
#define MAX_PLAYERS 5
#define ROWS 6
#define COLS 6

using namespace std;

template <const int N>
Tile* getMove(GameBoard<Tile, Player, N, N>& gameBoard, const string& pName) {
    Tile* newTile = nullptr;
    Move move = Move::UP;
    string moveString;
    bool moveValid = false;
    
    while (!moveValid) {
        bool inEnum = true;
        
        cout << "Where do you want to move? (up/down/left/right)" << endl;
        cin >> moveString;
        
        // Transform input string to uppercase
        transform(moveString.begin(), moveString.end(), moveString.begin(), ::toupper);
        
        if (moveString == "UP") {
            move = Move::UP;
        } else if (moveString == "DOWN") {
            move = Move::DOWN;
        } else if (moveString == "LEFT") {
            move = Move::LEFT;
        } else if (moveString == "RIGHT") {
            move = Move::RIGHT;
        } else {
            inEnum = false;
        }
        
        if (inEnum) {
            newTile = gameBoard.move(move, pName);
            if (newTile) {
                moveValid = true;
            }
        }
    }
    
    return newTile;
}

template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N>& gameBoard, const string& pName) {
    try {
        cin.exceptions(istream::failbit);
        Tile* t = getMove(gameBoard, pName);
        Player p = gameBoard.getPlayer(pName);
        if (p.canAct()) {
            bool makeAction;
            cout << t;
            cin >> makeAction;
            if (makeAction) {
                if (t->action(p)) {
                    p.eat();
                    for (Player player : gameBoard.getPlayers(t)) {
                        p.pay(player);
                    }
                    //gameBoard.setPlayer(op);
                }
            }
        }
        return true;
    } catch (istream::failure e) {
        cout << "Incorrect key pressed";
        cin.clear();
    } catch (out_of_range e) {
        cout << e.what();
    }
    return false;
}

int main(int argc, const char * argv[]) {

    bool paused = false;
    
    vector<Player> players;
    vector<string> pNames;
    GameBoard<Tile, Player, ROWS, COLS> *gb = nullptr;
    
    if (paused) {
        paused = false;
    } else {
        // Get number of players
        int numPlayers;
        do {
            cout << "How many players? (" << MIN_PLAYERS << "-" << MAX_PLAYERS << ")" << endl;
            cin >> numPlayers;
        } while (!(numPlayers >= MIN_PLAYERS && numPlayers <= MAX_PLAYERS));
        
        // Get player names
        for (int i = 0; i < numPlayers; i++) {
            cout << "Player " << i + 1 << " Name:" << endl;
            string playerName;
            cin >> playerName;
            Player player(playerName);
            pNames.push_back(playerName);
            players.push_back(player);
        }
        
        // Create gameboard with players
        GameBoard<Tile, Player, ROWS, COLS> gameBoard(players);
        gb = &gameBoard;
        
        // Add tiles
        TileFactory *tf = TileFactory::get(ROWS * COLS);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                gameBoard.addTile(tf->next(), i, j);
            }
        }
        
        gameBoard.draw(); // FOR DEBUG
    }
    
    for (auto pName : pNames) {
        do {
            cout << gb->getPlayer(pName);
        } while (!takeTurn(*gb, pName));
        if (gb->win(pName)) break;
    }
   
    return 0;
}
