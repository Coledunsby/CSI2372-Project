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
    nType = floor(nTiles / 14);     // Number of each type of tile
    
    // Add nType of each tile
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
    
    // Fill the remaining spaces with Desert tiles
    while (tiles.size() < nTiles) {
        Desert* desertTile = new Desert;
        tiles.push_back(desertTile);
    }
}

// Initialize an instance of TileFactory
TileFactory* TileFactory::get(int _nTiles) {
    static TileFactory tf(_nTiles);
    return &tf;
}

// Choose a random element to add to the gameboard next
Tile* TileFactory::next() {
    srand(unsigned(time(NULL)));
    int randIndex = rand() % tiles.size();
    
    Tile* tile = tiles[randIndex];
    
    tiles.erase(tiles.begin() + randIndex);
    
    return tile;
}
