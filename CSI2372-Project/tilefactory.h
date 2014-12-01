//
//  tilefactory.h
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-30.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#ifndef __CSI2372_Project__tilefactory__
#define __CSI2372_Project__tilefactory__

#include <stdio.h>
#include <vector>
#include "tile.h"

class TileFactory {
    vector<Tile*> tiles;
    int nTiles;
    int nType;
    
public:
    TileFactory(int _nTiles);
    static TileFactory* get(int _nTiles);
    Tile* next();
};

#endif /* defined(__CSI2372_Project__tilefactory__) */
