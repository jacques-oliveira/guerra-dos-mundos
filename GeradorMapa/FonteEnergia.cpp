#include "FonteEnergia.hpp"

FonteEnergia::FonteEnergia(float posx, float posy){
    posicao = sf::Vector2f(posx, posy);

}

void FonteEnergia::iniciar(){
    if(!texturaCristalNegro.loadFromFile("Assets/Textures/textura-cristal-negro.png")){
        std::cerr<<"Falha ao carregar textura cristal negro"<<std::endl;
    }
    spriteCristalNegro.setPosition(posicao);
    spriteCristalNegro.setTexture(texturaCristalNegro);
}


