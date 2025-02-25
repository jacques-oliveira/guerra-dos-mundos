#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "Botao.hpp"

class Interface{
public:
    Interface();
    virtual ~Interface() = default;

    static Botao criarBotao(float largura, float altura, float posx, float posy, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,std::string nomeBotao){

        Botao botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado, nomeBotao);
        botao.setPosition(posx, posy);
        return botao;
    }

    static std::vector<Botao> criarBotoesHorizontal(float largura, float altura, float posx, float posy, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,std::vector<std::string> nomeBotoes, float espacoHorizontal = 0){

        std::vector<Botao> vetorBotoes;
        for(auto i= 0; i < nomeBotoes.size(); ++i){
            float posicaoX = posx + i * largura + espacoHorizontal;
            float posicaoY = posy;
            Botao botao(largura, altura,texturaNormal, texturaSelecaoMouse, texturaSelecionado,nomeBotoes[i]);
            botao.setPosition(posx, posy);
            vetorBotoes.push_back(botao);
        }
        return vetorBotoes;
    }
};
#endif
