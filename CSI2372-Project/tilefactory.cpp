//
//  tilefactory.cpp
//  CSI2372-Project
//
//  Created by Cole Dunsby on 2014-11-30.
//  Copyright (c) 2014 Cole Dunsby. All rights reserved.
//

#include "tilefactory.h"

TileFactory::TileFactory(int _nTiles) {
    nTiles = _nTiles;
    nType = floor(nTiles / 14);
    index = -1;
    
    for (int i = 0; i < nType; i++) {
        Restaurant* restaurantTile = new Restaurant;
        SpiceMerchant* spiceMerchantTile = new SpiceMerchant;
        FabricManufacturer* fabricManufacturerTile = new FabricManufacturer;
        Jeweler* jewelerTile = new Jeweler;
        CartManufacturer* cartManufacturerTile = new CartManufacturer;
        SmallMarket* smallMarketTile = new SmallMarket;
        SpiceMarket* spiceMarketTile = new SpiceMarket;
        JewelryMarket* jewelryMarketTile = new JewelryMarket;
        FabricMarket* fabricMarketTile = new FabricMarket;
        BlackMarket* blackMarketTile = new BlackMarket;
        Casino* casinoTile = new Casino;
        GemMerchant* gemMerchantTile = new GemMerchant;
        Palace* palaceTile = new Palace;
        
        tiles.push_back(restaurantTile);
        tiles.push_back(spiceMerchantTile);
        tiles.push_back(fabricManufacturerTile);
        tiles.push_back(jewelerTile);
        tiles.push_back(cartManufacturerTile);
        tiles.push_back(smallMarketTile);
        tiles.push_back(spiceMarketTile);
        tiles.push_back(jewelryMarketTile);
        tiles.push_back(fabricMarketTile);
        tiles.push_back(blackMarketTile);
        tiles.push_back(casinoTile);
        tiles.push_back(gemMerchantTile);
        tiles.push_back(palaceTile);
    }
    
    while (tiles.size() < nTiles) {
        Desert* desertTile = new Desert;
        tiles.push_back(desertTile);
    }

    srand(unsigned(time(0)));
    random_shuffle(tiles.begin(), tiles.end());
}

TileFactory* TileFactory::get(int _nTiles) {
    static TileFactory tf(_nTiles);
    return &tf;
}

Tile* TileFactory::next() {
    index++;
    return tiles[index];
}
