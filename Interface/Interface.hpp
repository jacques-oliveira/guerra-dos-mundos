#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include "Botao.hpp"
#include "../Interface/PainelControle/BlocoItemPainel.hpp"
#include "../Personagem/TipoPersonagem.hpp"
#include "../Motor/GerenciadorJogo.hpp"

class Interface{
public:
    Interface();
    virtual ~Interface() = default;

    static Botao * criarBotao(float largura, float altura, float posx, float posy, const sf::Texture& texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,std::wstring nomeBotao, short tamanhoFonte = 0){
        Botao * botao;
        try{
            botao = new Botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado, nomeBotao,tamanhoFonte);
            botao->setPosition(posx, posy);
            return botao;
        }catch(std::exception& e){
            std::cerr<<"Falha ao criar botão"<<e.what()<<std::endl;
            return botao;
        }
    }

    static std::vector<Botao*> criarBotoesVertical(float largura, float altura, float posx, float posy, const sf::Texture&                                                                          texturaNormal, const sf::Texture& texturaSelecaoMouse, const sf::Texture& texturaSelecionado,
                                                    std::vector<std::wstring> nomeBotoes,
                                                    float espacoHorizontal = 0.f, float espacoVertical = 0.f, short tamanhoFonte = 0){

        std::vector<Botao*> vetorBotoes;
        try{
            float posicaoX = posx;

            for(int i = 0; i < nomeBotoes.size(); ++i){
                std::wstring nomeBotao = nomeBotoes[i];
                float posicaoY = posy + i * altura * espacoVertical;
                Botao * botao = new Botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado,
                            nomeBotao,tamanhoFonte);

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
                                                     float espacoHorizontal = 0.f, float espacoVertical = 0.f, short tamanhoFonte = 0){
        std::vector<Botao*> vetorBotoes;
        try{
            float posicaoY = posy;
            for(int i = 0; i < nomeBotoes.size(); ++i){
                float posicaoX = posx + i * (largura + espacoHorizontal);
                std::wstring nomeBotao = nomeBotoes[i];
                Botao * botao = new Botao(largura, altura, texturaNormal, texturaSelecaoMouse, texturaSelecionado,
                                        nomeBotao, tamanhoFonte);
                botao->atribuirPosicao(posicaoX, posicaoY);
                vetorBotoes.push_back(botao);
            }
            return vetorBotoes;
        }catch(std::exception& e){
            std::cerr<<"Falha ao criar botões na horizontal"<<e.what()<<std::endl;
            return vetorBotoes;
        }
    }

    static std::vector<BlocoItemPainel*> criarBlocosPainel(float posx, float posy, const sf::Texture& texturaBloco, unsigned short numeroBotoes, float espacoHorizontal){
        std::vector<BlocoItemPainel*> vetorBlocos;
        float distVertical = 8.f;
        float largura = texturaBloco.getSize().x;
        float posicaoY = posy + texturaBloco.getSize().y/2 + distVertical;
        for(unsigned short i = 0; i < numeroBotoes; ++i){
            float posicaoX = posx + i * (largura + espacoHorizontal);
            TipoPersonagem tipo = static_cast<TipoPersonagem>(i);
            GerenciadorJogo& gerenciador = GerenciadorJogo::obterInstancia();
            unsigned short valorItem = gerenciador.obterValorPersonagem(tipo);

            BlocoItemPainel * bloco = new BlocoItemPainel(valorItem);

            bloco->atribuirPosicao(posicaoX,posicaoY);
            vetorBlocos.push_back(bloco);
        }
        return vetorBlocos;
    }
};
#endif
