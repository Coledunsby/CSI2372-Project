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
    

    TileFactory *tf;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            bg.add(tf->next(), i, j);
        }
    }
    
//Translated Pseudo Code

if(isPaused){
             isPaused = false;
             }
else
    cin >> playerNumber; //??
    for
    (int i = 0; i < playerNumber; i++){
    cin >> playerName;
}
while (
    





//Given Code

template <cons int N>
bool takeTurn( BoardGame<Tile,Player,N,N>&bg, conststd::string&pName ) {
try {
    Move m;
    cin.exceptions(std::istream::failbit);
    cin>> m;
    const Tile t = bg.move( m, pName );
    Player p = bg.getPlayer( pName );
    if (p.canAct()) {
       bool makeAction;
       cin>>makeAction;
       if ( makeAction )
          std::vector<Player> opL = bg.getPlayers( t );
          if (p.getGold()>= opL.size()) {
             p.eat();
             for ( auto op : opL ) {
             p.pay( op, 1 );
             bg.setPlayer( op );
             }
          t.action( p );
          bg.setPlayer( p );
          }
          }
          }
       retrun true;
} catch ( std::istream::failure e ) {
  cout<< “Incorrect key pressed”; cin.clear(); }
} catch ( std::out_of_range e ) {
  cout<< e.what();
return false;
} 



   
    return 0;
}
