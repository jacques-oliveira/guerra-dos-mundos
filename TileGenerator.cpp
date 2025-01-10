#include "TileGenerator.hpp"


TileGenerator::TileGenerator(){
    tileWidth = 64;
    tileHeight = 64;
}

TileGenerator::~TileGenerator(){
}

void TileGenerator::generateTileMap(const string& tilesetFileName){

    if (!tilesetTexture.loadFromFile(tilesetFileName)) {
        cerr << "Erro ao carregar a textura: " << tilesetFileName << endl;
        return;
    }

    sf::Image tilesetImage = tilesetTexture.copyToImage();

    vector<TileBlock> tileBlockVector = extractTileBlock(tilesetImage, tileWidth, tileHeight);


    for(auto& i : tileBlockVector){
        if(!i.isTransparent()){
            listBaseTexture.push_back(*i.getSprite().getTexture());
        }
    }

}

const sf::Sprite& TileGenerator::getEnvSprite() const{
    return envSprite;
}

void TileGenerator::drawMap(sf::RenderTarget& target){
    vector<vector<int>> txtMapFile = loadTileTxtMatrix("/home/jacques/Documents/game-development/guerra-dos-mundos/tilemap-fase1.txt");

    for(short i =0; i < txtMapFile.size(); ++i){
        for(short j = 0; j < txtMapFile[i].size(); ++j){
            sf::Sprite sprite;
            sprite.setTexture(listBaseTexture[txtMapFile[i][j]]);
            sprite.setPosition(j * tileWidth,i * tileHeight);
            target.draw(sprite);
        }
    }
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
        stringstream lineStream(line);
        string value;

        // Separando por vírgula, considerando que os números são separados por vírgulas
        while (getline(lineStream, value, ',')) {
            // Converte o valor de string para int e adiciona à linha
            try {
                row.push_back(stoi(value));
            } catch (const invalid_argument& e) {
                cerr << "Erro ao converter valor: " << value << endl;
                row.push_back(0);  // Coloca um valor padrão em caso de erro
            }
        }

        tileMap.push_back(row);
    }

    inputFile.close();
    return tileMap;
}
