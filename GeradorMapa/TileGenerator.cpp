#include "TileGenerator.hpp"


TileGenerator::TileGenerator(){
    tileWidth = 64;
    tileHeight = 64;
    txtMapFile = loadTileTxtMatrix("Assets/MapaBits/mapa-bits-fase1.txt");
}

TileGenerator::~TileGenerator(){
}

void TileGenerator::generateTileMap(const string& tilesetFileName){

    if (!tilesetTexture.loadFromFile(tilesetFileName)) {
        cerr << "Erro ao carregar a textura: " << tilesetFileName << endl;
        return;
    }

    sf::Image tilesetImage = tilesetTexture.copyToImage();

    vector<TileBlock> tileBlockVector = extractTileBlock(tilesetImage);

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

    for(short i =0; i < txtMapFile.size(); ++i){
        for(short j = 0; j < txtMapFile[i].size(); ++j){
            sf::Sprite sprite;
            sprite.setTexture(listBaseTexture[txtMapFile[i][j]]);
            sprite.setPosition(j * tileWidth,i * tileHeight);
            target.draw(sprite);
        }
    }
}

vector<TileBlock> TileGenerator::extractTileBlock(const sf::Image& image) {
    std::vector<TileBlock> blocks;
    sf::Image blockImage;
    blockImage.create(tileWidth, tileHeight);
    blocks.push_back(blockImage);
    for (unsigned int y = 0; y < image.getSize().y; y += tileHeight) {
        for (unsigned int x = 0; x < image.getSize().x; x += tileWidth) {

            sf::Image blockImage;
            blockImage.create(tileWidth, tileHeight);

            blockImage.copy(image, 0, 0, sf::IntRect(x, y, tileWidth, tileHeight));

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
    try{
        while (getline(inputFile, line)) {
            vector<int> row;

            string sig = "";
            string strNum = "";
            for(int i =0; i < line.size();  i++){
                string c(1,line[i]);
                if(c == "," || c == "" || c == " "){
                    if(strNum != ""){
                        int num = stoi(strNum);
                        row.push_back(num);
                    }
                    strNum = "";
                }else if(c != "-"){

                    if(sig == "-"){
                        c = sig + c;
                        sig = "";
                    }
                    strNum += c;
                }else{
                    sig += c;
                }
            }
            tileMap.push_back(row);
        }
        inputFile.close();
        return tileMap;
    }catch(const exception& e){
        cerr<<"Erro ao criar tile"<<e.what()<<endl;
    }
    return tileMap;
}
