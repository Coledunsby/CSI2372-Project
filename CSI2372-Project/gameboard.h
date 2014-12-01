//
//  gameboard.h
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#ifndef __CSI2372_Project__gameboard__
#define __CSI2372_Project__gameboard__

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "tile.h"

using namespace std;

enum class Move {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

template <class T, class J, const int R, const int C>
class GameBoard {
    map<string, J> players;
    T* tiles[R][C];
    
public:
    GameBoard();
    GameBoard(vector<J> _players);
    J getPlayer(const string& playerName);
    void setPlayer(J player);
    void addTile(T* tile, int row, int col);
    void getCoordinate(const T* tile, int *row, int *col) const;
    vector<J> getPlayers(const T* tile) const;
    vector<string> getPlayerNames() const;
    T* getTile(int row, int col) const;
    T* getTile(const string& playerName);
    T* move(enum Move move, const string& playerName);
    bool win(const string& playerName);
    void draw() const;

    friend ostream& operator<<(ostream& os, GameBoard<T, J, R, C>& gameBoard) {
        
        // Tiles
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                Tile *tile = gameBoard.tiles[r][c];
                os << tile->getType() << "\t";
                os << tile->getIdentifier() << "\t";
            }
        }
        
        // Players
        os << gameBoard.players.size() << "\t";
        
        for (const auto& kv : gameBoard.players) {
            // Name
            const string pName = kv.first;
            os << pName << "\t";
            
            // Items
            Player p = kv.second;
            os << p.getGold() << "\t";
            os << p.getRuby() << "\t";
            os << p.getSpice() << "\t";
            os << p.getFabric() << "\t";
            os << p.getJewel() << "\t";
            os << p.getCart() << "\t";
            os << p.getFood() << "\t";
            
            // Tile
            Tile* tile = gameBoard.getTile(pName);
            int r = 0;
            int c = 0;
            int *row = &r;
            int *col = &c;
            gameBoard.getCoordinate(tile, row, col);
            os << *row << "\t";
            os << *col << "\t";
        }
        
        return os;
    }
    
    friend istream& operator>>(istream& is, GameBoard<T, J, R, C>& gameBoard) {
        
        // Tiles
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                string type;
                is >> type;
                Tile* tile;
                if (type == "Desert") {
                    tile = new Desert();
                } else if (type == "Restaurant") {
                    tile = new Restaurant();
                } else if (type == "SpiceMerchant") {
                    tile = new SpiceMerchant();
                } else if (type == "FabricManufacturer") {
                    tile = new FabricManufacturer();
                } else if (type == "Jeweler") {
                    tile = new Jeweler();
                } else if (type == "CartManufacturer") {
                    tile = new CartManufacturer();
                } else if (type == "SmallMarket") {
                    tile = new SmallMarket();
                } else if (type == "SpiceMarket") {
                    tile = new SpiceMarket();
                } else if (type == "JewelryMarket") {
                    tile = new JewelryMarket();
                } else if (type == "FabricMarket") {
                    tile = new FabricMarket();
                } else if (type == "BlackMarket") {
                    tile = new BlackMarket();
                } else if (type == "Casino") {
                    tile = new Casino();
                } else if (type == "GemMerchant") {
                    tile = new GemMerchant();
                } else if (type == "Palace") {
                    tile = new Palace();
                }
                
                int identifier;
                is >> identifier;
                
                tile->setIdentifier(identifier);
                
                gameBoard.addTile(tile, r, c);
            }
        }
        
        // Players
        int pCount;
        is >> pCount;
        
        for (int i = 0; i < pCount; i++) {
            // Name
            string pName;
            is >> pName;
            J player(pName);
            
            // Items
            int gold;
            is >> gold;
            player.setGold(gold);
            
            int ruby;
            is >> ruby;
            player.setRuby(ruby);
            
            int spice;
            is >> spice;
            player.setSpice(spice);
            
            int fabric;
            is >> fabric;
            player.setFabric(fabric);
            
            int jewel;
            is >> jewel;
            player.setJewel(jewel);
            
            int cart;
            is >> cart;
            player.setCart(cart);
            
            int food;
            is >> food;
            player.setFood(food);
            
            gameBoard.setPlayer(player);
            
            // Tile
            int r, c;
            is >> r;
            is >> c;
            Tile* tile = gameBoard.getTile(r, c);
            tile->addPlayer(player);
        }
        
        return is;
    }
};

#include "gameboard.cpp"

#endif /* defined(__CSI2372_Project__gameboard__) */
