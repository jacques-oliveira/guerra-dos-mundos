#include "TileGenerator.hpp"


TileGenerator::TileGenerator(){
}

TileGenerator::~TileGenerator(){
}

void TileGenerator::generateTileMap(const string& tilesetFileName, const string& outputFileName, int tileWidth, int tileHeight){
    sf::Texture tilesetTexture;
    if (!tilesetTexture.loadFromFile(tilesetFileName)) {
        std::cerr << "Erro ao carregar o tileset." << std::endl;
        return;
    }

    // Cria uma imagem para acessar os pixels do tileset
    sf::Image tilesetImage = tilesetTexture.copyToImage();

    // Calcula o número de tiles por linha e por coluna
    int tilesPerRow = tilesetTexture.getSize().x / tileWidth;
    int tilesPerColumn = tilesetTexture.getSize().y / tileHeight;

    // Cria o arquivo de saída
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
        return;
    }

    // Itera sobre os tiles para verificar quais são "vazios"
    for (int row = 0; row < tilesPerColumn; ++row) {
        for (int col = 0; col < tilesPerRow; ++col) {
            // Extrai os pixels do tile atual
            bool isEmpty = true;
            for (int y = 0; y < tileHeight; ++y) {
                for (int x = 0; x < tileWidth; ++x) {
                    // Coordenadas do pixel no tileset
                    int pixelX = col * tileWidth + x;
                    int pixelY = row * tileHeight + y;

                    // Verifica se o pixel não é transparente
                    sf::Color pixelColor = tilesetImage.getPixel(pixelX, pixelY);
                    if (pixelColor.a != 0) {  // Se o alpha não for 0, o tile não está vazio
                        isEmpty = false;
                        break;
                    }
                }
                if (!isEmpty) break;
            }

            // Escreve o ID do tile no arquivo (0 para vazio, índice do tile caso contrário)
            if (isEmpty) {
                outputFile << 0;
            } else {
                outputFile << (row * tilesPerRow + col + 1);  // Exemplo: índice começa em 1
            }

            // Adiciona uma vírgula, exceto no último tile da linha
            if (col < tilesPerRow - 1) {
                outputFile << ",";
            }
        }
        outputFile << std::endl;  // Nova linha para cada linha de tiles
    }

    outputFile.close();
    std::cout << "Arquivo " << outputFileName << " gerado com sucesso!" << std::endl;
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
