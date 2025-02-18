#include "FonteEnergia.hpp"

FonteEnergia::FonteEnergia(float posx, float posy, int energiaFonte){
    posicao = sf::Vector2f(posx, posy);
    this->energiaFonte = energiaFonte;
    iniciar();

}

void FonteEnergia::iniciar(){
    if(!texturaCristalNegro.loadFromFile("Assets/Textures/textura-cristal-negro.png")){
        std::cerr<<"Falha ao carregar textura cristal negro"<<std::endl;
    }

    animacoes.resize(1);
    animacoes[0].setSpriteSheet(texturaCristalNegro);
    carregarAnimacao(animacoes[0], 8, 0);

    spriteCristalNegro.setTexture(animacoes[0].getTexture());
    spriteCristalNegro.setTextureRect(animacoes[0].getCurrentFrame());
}

void FonteEnergia::carregarAnimacao(Animation& animacao, int quantidadeFrames, int linha)
{

        for(int i = 0; i < quantidadeFrames; ++i){
            animacao.addFrame(sf::IntRect(i * 256, linha * 256, 256,256));
        }
}

void FonteEnergia::atualizar(){
    animacoes[0].update();
    spriteCristalNegro.setTextureRect(animacoes[0].getCurrentFrame());
}

void FonteEnergia::renderizar(sf::RenderWindow& window){
    window.draw(spriteCristalNegro);
}





