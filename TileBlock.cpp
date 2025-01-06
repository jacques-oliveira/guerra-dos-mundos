#include "TileBlock.hpp"

TileBlock::TileBlock(const sf::Image& image) : image(image){

}

bool TileBlock::isTransparent() const{

    for (unsigned int y = 0; y < image.getSize().y; ++y) {
        for (unsigned int x = 0; x < image.getSize().x; ++x) {
            if (image.getPixel(x, y).a != 0) {
                return false; // Encontrou um pixel não transparente
            }
        }
    }
    return true;
}

