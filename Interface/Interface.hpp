#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "Botao.hpp"

class Interface{
public:
    Interface();
    virtual ~Interface() = default;

    static Botao * criarBotao(float largura, float altura, float posx, float posy, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,std::wstring nomeBotao){
        Botao * botao;
        try{
            botao = new Botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado, nomeBotao);
            botao->setPosition(posx, posy);
            return botao;
        }catch(std::exception& e){
            std::cerr<<"Falha ao criar botão"<<e.what()<<std::endl;
            return botao;
        }
    }

    static std::vector<Botao*> criarBotoesVertical(float largura, float altura, float posx, float posy, const sf::Texture&                                                                          texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,
                                                    std::vector<std::wstring> nomeBotoes,
                                                    float espacoHorizontal = 0.f, float espacoVertical = 0.f){

        std::vector<Botao*> vetorBotoes;
        try{
            float posicaoX = posx;

            for(int i = 0; i < nomeBotoes.size(); ++i){
                std::wstring nomeBotao = nomeBotoes[i];
                float posicaoY = posy + i * altura * espacoVertical;
                Botao * botao = new Botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado,
                            nomeBotao);

                botao->atribuirPosicao(posicaoX, posicaoY);
                vetorBotoes.push_back(botao);
            }
            return vetorBotoes;
        }catch(std::exception& e){
            std::cerr<<"Falha ao criar botões na vertical"<<e.what()<<std::endl;
            return vetorBotoes;
        }
    }

    static std::vector<Botao*> criarBotoesHorizontal(float largura, float altura, float posx, float posy, const sf::Texture&                                                        texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,
                                                     std::vector<std::wstring> nomeBotoes,
                                                     float espacoHorizontal = 0.f, float espacoVertical = 0.f){
        std::vector<Botao*> vetorBotoes;
        try{
            for(int i = 0; i < nomeBotoes.size(); ++i){
                float posicaoX = posx + i * largura * espacoHorizontal;
                float posicaoY = posy;
                std::wstring nomeBotao = nomeBotoes[i];
                Botao * botao = new Botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado,
                                        nomeBotao);
                botao->atribuirPosicao(posicaoX, posicaoY);
                vetorBotoes.push_back(botao);
            }
            return vetorBotoes;
        }catch(std::exception& e){
            std::cerr<<"Falha ao criar botões na horizontal"<<e.what()<<std::endl;
            return vetorBotoes;
        }
    }
};
#endif
