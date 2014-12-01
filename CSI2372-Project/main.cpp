//
//  main.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-10.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include <iostream>
#include "gameboard.h"
#include "tilefactory.h"
#include "tile.h"
#include <fstream>

#define MIN_PLAYERS 2
#define MAX_PLAYERS 5
#define ROWS 6
#define COLS 6

using namespace std;
ifstream file("gameboard.txt");

template <const int N>
Tile* getMove(GameBoard<Tile, Player, N, N>& gameBoard, const string& pName) {
    Tile* newTile = nullptr;
    Move move = Move::UP;
    string moveString;
    bool moveValid = false;
    
    while (!moveValid) {
        bool inEnum = true;
        
        cout << "Where do you want to move? (up/down/left/right). If you would like to save the game, enter 'yes'." << endl;
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
        } else if (moveString == "yes") {
            save();
        } else {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inEnum = false;
        }
        
        if (inEnum) {
            newTile = gameBoard.move(move, pName);
            if (newTile) {
                moveValid = true;
            } else {
                cout << "You can't move there! You are at the edge of the board." << endl;
            }
        }
        
        cout << endl;
    }
    
    return newTile;
}

bool getAction() {
    bool action = false;
    bool actionValid = false;
    string actionString;
    
    while (!actionValid) {
        cout << "Do you want to perform this action? (yes/no)" << endl;
        cin >> actionString;
        
        // Transform input string to uppercase
        transform(actionString.begin(), actionString.end(), actionString.begin(), ::toupper);
        
        if (actionString == "YES") {
            action = true;
            actionValid = true;
        } else if (actionString == "NO") {
            action = false;
            actionValid = true;
        } else {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << endl;
    }
    
    cout << endl;

    return action;
}

template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N>& gameBoard, const string& pName) {
    try {
        cin.exceptions(istream::failbit);
        Tile* t = getMove(gameBoard, pName);
        Player p = gameBoard.getPlayer(pName);
        cout << t;
        if (p.canAct()) {
            if (t->hasAction() && getAction()) {
                if (t->action(p)) {
                    p.eat();
                    for (Player player : gameBoard.getPlayers(t)) {
                        if (!(player == p)) {
                            p.pay(player);
                            gameBoard.setPlayer(player);
                        }
                    }
                    gameBoard.setPlayer(p);
                    cout << "New stats:" << endl;
                    cout << p;
                    cout << endl;
                } else {
                    cout << "You don't have enough resources." << endl;
                    cout << endl;
                }
            }
        } else {
            cout << "You are unable to perform this action." << endl;
            cout << endl;
        }
        return true;
    } catch (istream::failure e) {
        cout << "Incorrect key pressed!" << endl;;
        cin.clear();
    } catch (out_of_range e) {
        cout << e.what();
    }
    return false;
}

void save(){
     paused == true;
     ofstream file("save.dat");
     ostream& operator<<(ostream, const GameBoard&);
}

int main(int argc, const char * argv[]) {

    bool paused = false;
    bool placedPlayers = false;
    bool winner = false;
    
    vector<Player> players;
    vector<string> pNames;
    GameBoard<Tile, Player, ROWS, COLS> *gb = nullptr;
    
    if (paused) {
        paused = false;
    } else {
        // Get number of players
        int numPlayers;
        String answer;
        do {
            cout << "Is there a game currently saved that you would like to play? (y or n)";
            cin >> answer;
            if (answer == "y"){
                       ifstream file("gmeboard.txt");
                       file >> gb;
                       file.close();
                       for (auto pName : pNames){
                           pNames.push_back(player.name);
                       }      
            }
            else 
            cout << "How many players? (" << MIN_PLAYERS << "-" << MAX_PLAYERS << ")" << endl;
            cin >> numPlayers;
            if (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS) {
                cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << endl;
        } while (!(numPlayers >= MIN_PLAYERS && numPlayers <= MAX_PLAYERS));
        
        // Get player names
        for (int i = 0; i < numPlayers; i++) {
            bool nameValid = false;
            while (!nameValid) {
                cout << "Player " << i + 1 << " Name:" << endl;
                string playerName;
                cin >> playerName;
                if (find(pNames.begin(), pNames.end(), playerName) != pNames.end()) {
                    cout << "Name taken!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    Player player(playerName);
                    pNames.push_back(playerName);
                    players.push_back(player);
                    nameValid = true;
                }
                cout << endl;
            }
        }
        
        // Create gameboard with players
        GameBoard<Tile, Player, ROWS, COLS> gameBoard(players);
        gb = &gameBoard;
        
        // Add tiles
        TileFactory *tf = TileFactory::get(ROWS * COLS);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                Tile* t = tf->next();
                if (t->getType() == "Restaurant" && !placedPlayers) {
                    t->addPlayers(players);
                    placedPlayers = true;
                }
                gameBoard.addTile(t, i, j);
            }
        }
        
        gameBoard.draw(); // FOR DEBUG
        
        Tile *t = gameBoard.getTile(pNames[0]);
        int r = 0;
        int c = 0;
        int *row = &r;
        int *col = &c;
        
        gameBoard.getCoordinate(t, row, col);

        cout << endl;
        cout << "Players starting at " << t->getType() << " (" << t->getIdentifier() << ")" << endl;
        cout << endl;
    }
    
    while (!winner) {
        for (auto pName : pNames) {
            do {
                cout << gb->getPlayer(pName) << endl;
            } while (!takeTurn(*gb, pName));
            
            if (gb->win(pName)) {
                winner = true;
                break;
            }
        }
    }
   
    return 0;
}
