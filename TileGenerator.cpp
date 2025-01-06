#include "TileGenerator.hpp"


TileGenerator::TileGenerator() {
}

TileGenerator::~TileGenerator(){
}

void TileGenerator::generateTileMap(const string& tilesetFileName, short tileWidth, short tileHeight){

    if (!tilesetTexture.loadFromFile(tilesetFileName)) {
        cerr << "Erro ao carregar a textura: " << tilesetFileName << endl;
        return;
    }

    sf::Image tilesetImage = tilesetTexture.copyToImage();
    envSprite.setTexture(tilesetTexture);

    vector<TileBlock> tileBlockVector = extractTileBlock(tilesetImage, tileWidth, tileHeight);

    cout<<"Sprite loaded"<<endl;

}

const sf::Sprite& TileGenerator::getEnvSprite() const{
    return envSprite;
}


vector<TileBlock> TileGenerator::extractTileBlock(const sf::Image& image, int blockWidth, int blockHeight) {
    std::vector<TileBlock> blocks;

    // Percorre a imagem em blocos
    for (unsigned int y = 0; y < image.getSize().y; y += blockHeight) {
        for (unsigned int x = 0; x < image.getSize().x; x += blockWidth) {
            // Cria uma nova imagem para o bloco
            sf::Image blockImage;
            blockImage.create(blockWidth, blockHeight);

            // Copia os pixels do bloco atual
            blockImage.copy(image, 0, 0, sf::IntRect(x, y, blockWidth, blockHeight));

            // Adiciona o bloco ao vetor
            blocks.emplace_back(blockImage);
        }
    }

    return blocks;
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
