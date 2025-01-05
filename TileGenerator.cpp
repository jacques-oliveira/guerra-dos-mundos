#include "TileGenerator.hpp"


TileGenerator::TileGenerator(){
}

TileGenerator::~TileGenerator(){
}

void TileGenerator::generateTileMap(const string& tilesetFileName, const string& outputFileName, int tileWidth, int tileHeight){

    sf::Texture tilesetTexture;
    if (!tilesetTexture.loadFromFile(tilesetFileName)) {
        cerr << "Erro ao carregar o tileset." << endl;
        return;
    }

    int tilesPerRow = tilesetTexture.getSize().x / tileWidth;
    int tilesPerColumn = tilesetTexture.getSize().y / tileHeight;

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita." << endl;
        return;
    }

    int tileNumber = 0;
    for (int row = 0; row < tilesPerColumn; ++row) {
        for (int col = 0; col < tilesPerRow; ++col) {
            outputFile << tileNumber << " ";
            tileNumber++;
        }
        outputFile << endl;
    }

    outputFile.close();
    cout << "Arquivo " << outputFileName << " gerado com sucesso!" << endl;
}

vector<vector<int>> TileGenerator::loadTileMap(const string& filename){
    vector<vector<int>> tileMap;
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return tileMap;
    }

    string line;
    while (getline(inputFile, line)) {
        vector<int> row;
        istringstream lineStream(line);
        int tile;
        while (lineStream >> tile) {
            row.push_back(tile);
        }
        tileMap.push_back(row);
    }

    inputFile.close();
    return tileMap;
}

void TileGenerator::displayTileMap(const string& tilesetFilename, const vector<vector<int>>& tileMap, int tileWidth, int tileHeight){
    sf::RenderWindow window(sf::VideoMode(800, 600), "TileMap Viewer");

    sf::Texture tilesetTexture;
    if (!tilesetTexture.loadFromFile(tilesetFilename)) {
        cerr << "Erro ao carregar o tileset." << endl;
        return;
    }

    sf::Sprite tileSprite(tilesetTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (size_t row = 0; row < tileMap.size(); ++row) {
            for (size_t col = 0; col < tileMap[row].size(); ++col) {
                int tileNumber = tileMap[row][col];

                int tilesPerRow = tilesetTexture.getSize().x / tileWidth;
                int tu = tileNumber % tilesPerRow;
                int tv = tileNumber / tilesPerRow;

                tileSprite.setTextureRect(sf::IntRect(tu * tileWidth, tv * tileHeight, tileWidth, tileHeight));
                tileSprite.setPosition(col * tileWidth, row * tileHeight);

                window.draw(tileSprite);
            }
        }

        window.display();
    }
}
