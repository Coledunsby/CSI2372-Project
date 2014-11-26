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

using namespace std;

template <const int N>
bool takeTurn(GameBoard<Tile, Player, N, N>& bg, const std::string& pName) {
    try {
        Move m;
        std::cin.exceptions(std::istream::failbit);
        //std::cin >> m;
        const Tile t = bg.move(m, pName);
        Player p = bg.getPlayer(pName);
        if (p.canAct()) {
            bool makeAction;
            std::cin >> makeAction;
            if (makeAction) {
                std::vector<Player> opL = bg.getPlayers(t);
                if (p.getGold() >= opL.size()) {
                    p.eat();
                    for (auto op : opL) {
                        //p.pay(op, 1);
                        bg.setPlayer(op);
                    }
                    //t.action(p);
                    bg.setPlayer(p);
                }
            }
        }
        return true;
    } catch (std::istream::failure e) {
        std::cout << "Incorrect key pressed";
        std::cin.clear();
    } catch (std::out_of_range e) {
        std::cout << e.what();
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    Player player1("A"), player2("B");
    
    std::vector<Player> players;
    players.push_back(player1);
    players.push_back(player2);
    
    GameBoard<Tile, Player, 6, 6> bg(players);
    bg.draw();
    
    TileFactory *tf = TileFactory::get(6*6);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            bg.add(tf->next(), i, j);
        }
    }
    
    for (int i = 0; i < players.size(); i++) {
        do {
            std::cout << players[i].getName();
        } while (!takeTurn(bg, players[i].getName()));
        
        //if (bg.win(players[i]) break;
    }
    
    //Translated Pseudo Code

    if (isPaused) {
        isPaused = false;
    }
    else {
        cin >> numberOfPlayers; //??
        for (int i = 0; i < numberOfPlayers; i++) {
            cin >> pName;
        }
        while (bg.win(pName)) {
            if (isPaused) {
                   isPaused = false;
            }
            for (int i = 0; i < numberOfPlayers; i++){
                cout << "Player " << i+1 << "You have " <<player[i].getGold() << " gold, " << player[i].getRuby() << " rubys, " << player[i].getSpice() << " spice, " << player[i].getFabric() << " fabric, " << player[i].getFabric() << " jewels, " << player[i].getCart() << " cart capactiy and " <<player[i].getFood() << " food." << endl;
                while (/*move is not valid*/) {
                   //input move
                }
                gameboard.move(/*move*/, player[i]);
                if (player[i].canAct()) {
                    gameboard.getTile(player[i]);
                    if (/*player chooses action*/ && tile.action(player[i])) {
                        if(/*tile is occupied*/) {
                            player[i].pay(gameboard.getPlayer()/*?*/);
                        }
                    }
                                          
                    cout << "Player " << i+1 << "You have " <<player[i].getGold() << " gold, " <<player[i].getRuby() << " rubys, " <<player[i].getSpice() << " spice, " <<player[i].getFabric() << " fabric, " <<player[i].getFabric() << " jewels, " <<player[i].getCart() << " cart capactiy and " <<player[i].getFood() << " food." << endl;
                    
                    if (player[i].getRuby() == 5) {
                               //has won
<<<<<<< HEAD
                               }
                               }          
                                          
      }
      





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

public bool isPaused(){
       //
       }


=======
                    }
                }
            }
        }
    }
>>>>>>> 355e9b0653ee24a2073f062fc8ab432cab675311
   
    return 0;
}
