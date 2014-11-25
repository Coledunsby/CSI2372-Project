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

int main(int argc, const char * argv[]) {
    
    Player player1, player2;
    
    std::vector<Player> players;
    players.push_back(player1);
    players.push_back(player2);
    
    GameBoard<Tile, Player, 6, 6> bg(players);
    bg.draw();
    
    /*
    TileFactory *tf;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            //bg.add(tf->next(), i, j);
        }
    }
     */
    
    return 0;
}
