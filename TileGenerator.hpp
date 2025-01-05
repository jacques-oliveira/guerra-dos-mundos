#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class TileGenerator{

public:
    TileGenerator();
    ~TileGenerator();
    static void generateTileMap(const string& tilesetFileName, const string& outputFileName, int tileWidth, int tileHeight);
    static vector<vector<int>> loadTileMap(const string& filename);
    static void displayTileMap(const string& tilesetFilename, const vector<vector<int>>& tileMap, int tileWidth, int tileHeight);
};
