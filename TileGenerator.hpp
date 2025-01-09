#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "TileBlock.hpp"

using namespace std;

class TileGenerator{

public:
    TileGenerator();
    ~TileGenerator();

    void generateTileMap(const string& tilesetFileName, short tileWidth, short tileHeight);
    static vector<vector<int>> loadTileTxtMatrix(const string& filename);
    static vector<TileBlock> extractTileBlock(const sf::Image& image, int blockWidth, int blockHeight);
    vector<sf::Sprite> tileBaseList;
    const sf::Sprite& getEnvSprite() const;
    void drawTiles(sf::RenderWindow&,short, short);

private:
    sf::Sprite envSprite;
    sf::Texture tilesetTexture;

};


