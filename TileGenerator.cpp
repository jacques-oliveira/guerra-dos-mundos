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

    vector<TileBlock> tileBlockVector = extractTileBlock(tilesetImage, tileWidth, tileHeight);


    for(auto& i : tileBlockVector){
        if(!i.isTransparent()){
            tileBaseList.push_back(i.getSprite());
        }
    }
    // sf::Texture& t = tileBaseList[5];
    // envSprite.setTexture(t);
}

const sf::Sprite& TileGenerator::getEnvSprite() const{
    return envSprite;
}

void TileGenerator::drawTiles(sf::RenderWindow& window, short tileWidth, short tileHeight){
    vector<vector<int>> tileMap = loadTileTxtMatrix("/home/jacques/Documents/game-development/guerra-dos-mundos/tilemap-fase1.txt");
    std::cout<<tileMap.size()<<std::endl;
    window.clear();
    for (size_t i = 0; i < tileMap.size(); ++i) {
        for (size_t j = 0; j < tileMap[i].size(); ++j) {
            int tileIndex = tileMap[i][j];
            if (tileIndex >= 0) {
                tileBaseList[tileIndex].setPosition(j * tileWidth, i * tileHeight);
                window.draw(tileBaseList[tileIndex]);
            }
        }
    }
    window.display();
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

vector<vector<int>> TileGenerator::loadTileTxtMatrix(const string& filename){
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
