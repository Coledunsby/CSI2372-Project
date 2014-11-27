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

GameBoard<Tile, Player, ROWS, COLS> gameBoard;

Move getMove() {
    Move move = Move::UP;
    string moveString;
    bool moveValid = false;
    
    while (!moveValid) {
        cout << "Where do you want to move? (up/down/left/right)" << endl;
        cin >> moveString;
        
        // Transform input string to uppercase
        transform(moveString.begin(), moveString.end(), moveString.begin(), ::toupper);
        
        moveValid = true;
        
        if (moveString == "UP") {
            move = Move::UP;
        } else if (moveString == "DOWN") {
            move = Move::DOWN;
        } else if (moveString == "LEFT") {
            move = Move::LEFT;
        } else if (moveString == "RIGHT") {
            move = Move::RIGHT;
        } else {
            moveValid = false;
        }
    }
    
    return move;
}

template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N>& gameBoard, const string& pName) {
    try {
        cin.exceptions(istream::failbit);
        Move m = getMove();
        Tile t = gameBoard.move(m, pName);
        Player p = gameBoard.getPlayer(pName);
        if (p.canAct()) {
            bool makeAction;
            cin >> makeAction;
            if (makeAction) {
                vector<Player> opL = gameBoard.getPlayers(t);
                if (p.getGold() >= opL.size()) {
                    p.eat();
                    for (auto op : opL) {
                        p.pay(op);
                        gameBoard.setPlayer(op);
                    }
                    t.action(p);
                    gameBoard.setPlayer(p);
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

bool moveIsValid(Player& player, Move move) {
    return true;
}

void setupGame() {
    
    // Get number of players
    int numPlayers;
    do {
        cout << "How many players? (" << MIN_PLAYERS << "-" << MAX_PLAYERS << ")" << endl;
        cin >> numPlayers;
    } while (!(numPlayers >= MIN_PLAYERS && numPlayers <= MAX_PLAYERS));
    
    // Add tiles
    TileFactory *tf = TileFactory::get(ROWS * COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard.addTile(tf->next(), i, j);
        }
    }
    
    // Get player names
    for (int i = 0; i < numPlayers; i++) {
        cout << "Player " << i + 1 << " Name:" << endl;
        string playerName;
        cin >> playerName;
        Player player(playerName);
        gameBoard.addPlayer(player, playerName);
    }
}

int main(int argc, const char * argv[]) {

    bool paused = false;
    bool hasWon = false;
    
    if (paused) {
        paused = false;
    } else {
        setupGame();
    }
    
    while (!hasWon) {
        
        // Check for pause
        
        for (auto pName : gameBoard.getpla) {
            
            cout << player;
            
            // Move logic
            
            if (player.canAct()) {
                // Display tile action
                
            }
            
            cout << player;
            
            if (player.getRuby() >= 5) {
                hasWon = true;
            }
        }
    }
    
    
    /*
    for (int i = 0; i < players.size(); i++) {
        do {
            cout << players[i].getName();
        } while (!takeTurn(gameBoard, players[i].getName()));
        
        //if (bg.win(players[i]) break;
    }*/
    
    //Translated Pseudo Code
    /*
    bool isPaused = false;
    int choseAction = 0;

    if (isPaused) {
        isPaused = false;
    } else {
        cin >> numberOfPlayers; //??
        for (int i = 0; i < numberOfPlayers; i++) {
            cin >> player[i].setName();
        }
        bool hasWon = false;
             
        while (!hasWon) {
            if (isPaused) {
                   isPaused = false;
            }
            for (int i = 1; i < numberOfPlayers; i++){
                cout << "Player " << i << "You have " <<player[i].getGold() << " gold, " << player[i].getRuby() << " rubys, " << player[i].getSpice() << " spice, " << player[i].getFabric() << " fabric, " << player[i].getFabric() << " jewels, " << player[i].getCart() << " cart capactiy and " <<player[i].getFood() << " food." << endl;
                while (!moveIsValid(player[i])) {
                   cin << m
                }
                gameboard.move(Move, player[i]);
                if (player[i].canAct()) {
                    gameboard.getTile(player[i]);
                    cout<< "Type 1 for yes or 2 for no" << endl;
                    cin << choseAction;
                    if (choseAction == 1 && tile.action(player[i])) {
                        if(tile is occupied) {
                            player[i].pay(gameboard.getPlayer());
                        }
                    }
                                          
                    cout << "Player " << i << "You have " <<player[i].getGold() << " gold, " <<player[i].getRuby() << " rubys, " <<player[i].getSpice() << " spice, " <<player[i].getFabric() << " fabric, " <<player[i].getFabric() << " jewels, " <<player[i].getCart() << " cart capactiy and " <<player[i].getFood() << " food." << endl;
                    
                    if (player[i].getRuby() == 5) {
                               hasWon = true;
                    }
                }
            }
        }
    }
     */
   
    return 0;
}
