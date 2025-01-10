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

    void generateTileMap(const string& tilesetFileName);
    static vector<vector<int>> loadTileTxtMatrix(const string& filename);
    static vector<TileBlock> extractTileBlock(const sf::Image& image, int blockWidth, int blockHeight);
    vector<sf::Texture> listBaseTexture;
    const sf::Sprite& getEnvSprite() const;
    void drawMap(sf::RenderTarget&);

private:
    sf::Sprite envSprite;
    sf::Texture tilesetTexture;
    short tileWidth,tileHeight;
    bool isMapDrew;
};


