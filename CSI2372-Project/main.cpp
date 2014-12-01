//
//  main.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-10.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "gameboard.h"
#include "tilefactory.h"
#include "tile.h"

#define MIN_PLAYERS 2
#define MAX_PLAYERS 5
#define ROWS 6
#define COLS 6
#define SAVE_FILE "gameboard.txt"

using namespace std;

// Helper function to get a boolean answer to a question
bool getBoolean(string question) {
    bool action = false;
    bool actionValid = false;
    string actionString;
    
    while (!actionValid) {
        cout << question << " (yes/no)" << endl;
        cin >> actionString;
        
        // Transform input string to uppercase
        transform(actionString.begin(), actionString.end(), actionString.begin(), ::toupper);
        
        // Check if answer is 'yes' or 'no'
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
    
    return action;
}

// Helper function to move a player based on text input
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
        
        // Check if value is valid (in enumeration Move)
        if (moveString == "UP") {
            move = Move::UP;
        } else if (moveString == "DOWN") {
            move = Move::DOWN;
        } else if (moveString == "LEFT") {
            move = Move::LEFT;
        } else if (moveString == "RIGHT") {
            move = Move::RIGHT;
        } else {
            cout << "Invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            inEnum = false;
        }
        
        // Try move the player
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

// Helper function to handle a player's turn
template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N>& gameBoard, const string& pName) {
    try {
        cin.exceptions(istream::failbit);
        Tile* t = getMove(gameBoard, pName);
        Player p = gameBoard.getPlayer(pName);
        cout << t->getType() << ": " << t->getAction() << endl;
        if (p.canAct() || t->getType() == "Restaurant") {   // If has food or tile type is Restaurant
            if (t->hasAction()) {                           // If the tile has an action associated with it
                if (t->canPerformAction(p)) {               // If the player has the necessary resources to perform the action
                    if (getBoolean("Do you want to perform this action?")) {
                        p.eat();
                        
                        // Pay other players on same tile
                        for (Player player : gameBoard.getPlayers(t)) {
                            if (!(player == p)) {
                                p.pay(player);
                                gameBoard.setPlayer(player);
                            }
                        }
                        
                        // Peform action
                        t->action(p);
                        
                        // Update gameboard player
                        gameBoard.setPlayer(p);
                        
                        // Print the new stats
                        cout << "New stats:" << endl;
                        cout << p;
                        cout << endl;
                    }
                } else {
                    cout << "You are unable to perform this action (not enough resources / cart is full)." << endl;
                    cout << endl;
                }
            } else {
                cout << endl;
            }
        } else {
            cout << "You are unable to perform this action (no food)." << endl;
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

int main(int argc, const char * argv[]) {

    bool placedPlayers = false;     // Whether players have already been placed on the gameboard (on a Restaurant tile)
    bool winner = false;            // Whether a player has won (game is over)
    bool quit = false;              // Whether the program should terminate (after save or error)
    
    vector<Player> players;
    vector<string> pNames;
    GameBoard<Tile, Player, ROWS, COLS> gb;
    
    ifstream input_file(SAVE_FILE);
    
    // If save file exists, check if user wants to load it
    if (input_file.good() && getBoolean("Saved file found. Do you want to continue saved game?")) {
        // Load game data
        input_file >> gb;
        input_file.close();
    } else {
        // Get number of players
        int numPlayers;
        do {
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
                    gb.setPlayer(player);
                    nameValid = true;
                }
                cout << endl;
            }
        }
        
        // Add tiles
        TileFactory *tf = TileFactory::get(ROWS * COLS);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                Tile* t = tf->next();
                if (t->getType() == "Restaurant" && !placedPlayers) {
                    t->addPlayers(players);
                    placedPlayers = true;
                }
                gb.addTile(t, i, j);
            }
        }
    }
    
    // Loop until there is a winner, or a player selects to save and quit
    while (!winner && !quit) {
        if (getBoolean("Do you want to save and exit?")) {
            // Save and exit
            ofstream output_file(SAVE_FILE);
            output_file << gb;
            output_file.close();
            quit = true;
        } else {
            for (string pName : gb.getPlayerNames()) {
                do {
                    cout << "---------------------------------------------------" << endl;
                    cout << pName << "'s Turn..." << endl;
                    cout << gb.getPlayer(pName) << endl;
                    
                    // Draw gameboard
                    gb.draw();
                    cout << endl;
                    
                    // Tell player which tile they are on
                    Tile *currentTile = gb.getTile(pName);
                    cout << "You are at tile " << currentTile->getIdentifier() << endl;
                    
                    // Get coordinates of current tile
                    int r = 0;
                    int c = 0;
                    int *row = &r;
                    int *col = &c;
                    gb.getCoordinate(currentTile, row, col);
                    
                    // Tell player about surrounding tiles
                    try {
                        Tile* up = gb.getTile(*row - 1, *col);
                        cout << "UP:    " << up->getType() << " (" << up->getIdentifier() << ")" << endl;
                    } catch (out_of_range e) {
                        cout << "UP:    None" << endl;
                    }
                    
                    try {
                        Tile* down = gb.getTile(*row + 1 , *col);
                        cout << "DOWN:  " << down->getType() << " (" << down->getIdentifier() << ")" << endl;
                    } catch (out_of_range e) {
                        cout << "DOWN:  None" << endl;
                    }
                    
                    try {
                        Tile* left = gb.getTile(*row, *col - 1);
                        cout << "LEFT:  " << left->getType() << " (" << left->getIdentifier() << ")" << endl;
                    } catch (out_of_range e) {
                        cout << "LEFT:  None" << endl;
                    }
                    
                    try {
                        Tile* right = gb.getTile(*row, *col + 1);
                        cout << "RIGHT: " << right->getType() << " (" << right->getIdentifier() << ")" << endl;
                    } catch (out_of_range e) {
                        cout << "RIGHT: None" << endl;
                    }
                    
                    cout << endl;
                } while (!takeTurn(gb, pName));
                
                if (gb.win(pName)) {
                    cout << pName << " wins!!!" << endl;
                    winner = true;
                    break;
                }
            }
        }
    }
   
    return 0;
}
