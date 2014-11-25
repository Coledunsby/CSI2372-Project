//
//  tile.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-24.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "tile.h"

/* ------------------------------------------------------------------
 Tile
 ----------------------------------------------------------------- */



/* ------------------------------------------------------------------
 TileFactory
 ----------------------------------------------------------------- */

TileFactory::TileFactory(int _nTiles) {
    
}

/*
TileFactory* TileFactory::get(int _nTiles) {
    static TileFactory tf(_nTiles);
    return &tf;
}
 */

Tile* TileFactory::next() {
    return nullptr;
}