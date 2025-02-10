#ifndef MAIN_MENU_STATE_CPP
#define MAIN_MENU_STATE_CPP

#include "MainMenuState.hpp"
#include<stdexcept>
#include <iostream>

MainMenuState::MainMenuState(sf::RenderWindow& _window): selectedOption(0), continueGame(false), exitGame(false){

    initMenu(_window);
}

void MainMenuState::processEvents(sf::RenderWindow& window, bool * isRunning){
    sf::Event event;
    try{
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed){
                exitGame=true;
                if(shouldExit()){
                    *isRunning = false;
                    window.close();
                }
            }/*else if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up){
                    selectedOption= (selectedOption - 1 + options.size()) % options.size();
                    updateOptionColors();
                }else if(event.key.code == sf::Keyboard::Down){
                    selectedOption= (selectedOption + 1) % options.size();
                    updateOptionColors();
                }else if(event.key.code == sf::Keyboard::Enter){
                    if(selectedOption == 0){
                        continueGame = true;
                    }else if(selectedOption ==1){
                        exitGame =true;
                        window.close();
                    }
                }
            }*/
            for(auto& botao : botoes){
                botao.atualizar(window, event);
                if(botao.obterEventoBotao()){
                    continueGame = true;
                }
            }


        }
    }catch(std::exception& e){
        std::cerr<<"Erro ao processar Menu"<<e.what()<<std::endl;
    }
}

void MainMenuState::update(sf::Time deltaTime){
}

void MainMenuState::render(sf::RenderWindow& window){
    try{
        window.clear();
        window.draw(spriteAmbienteMenu);
        window.draw(spritePainelMenu);

        // for(const auto& option: options){
        //     window.draw(option);
        // }

        for(Botao& botao : botoes){
            botao.renderizar(window);
        }
        window.display();

    }catch(std::exception& e){
        std::cerr<<"Erro ao renderizar menu"<<e.what()<<std::endl;
    }
}

void MainMenuState::updateOptionColors(){
    for(size_t i = 0; i < options.size();++i){
        options[i].setFillColor(i == selectedOption ? sf::Color::Red: sf::Color::White);
    }
}

bool MainMenuState::shouldContinue() const{
    return continueGame;
}

bool MainMenuState::shouldExit() const{
    return exitGame;
}

void MainMenuState::initMenu(sf::RenderWindow& _window){
    try{

        carregarRecursos();

        larguraTela = _window.getSize().x;
        alturaTela = _window.getSize().y;

        spritePainelMenu.setTexture(texturaPainelMenu);
        spritePainelMenu.setOrigin(spritePainelMenu.getLocalBounds().left + spritePainelMenu.getLocalBounds().width/2,
                                    spritePainelMenu.getLocalBounds().top + spritePainelMenu.getLocalBounds().height/2);

        spritePainelMenu.setPosition(larguraTela/2, alturaTela/2 );
        spriteAmbienteMenu.setTexture(texturaAmbienteMenu);

        float larguraBotao = texturaBotaoJogarNormal.getSize().x + 0.1f;
        float alturaBotao = texturaBotaoJogarNormal.getSize().y + 0.1f;
        float espacoBotao = 20.f;

        float posicaoBotaox = larguraTela/2;
        float posicaoBotaoy = spritePainelMenu.getPosition().y/2 + (alturaTela -alturaBotao)/2;

        for(size_t i = 0; i < 2; ++i){
            posicaoBotaoy = spritePainelMenu.getPosition().y/2 + (alturaTela -alturaBotao)/2 +  i * ( alturaBotao + espacoBotao );
            switch(i){
                case 0:{
                    Botao botao(larguraBotao, alturaBotao, texturaBotaoJogarNormal, texturaBotaoJogarSelecionado, texturaBotaoJogarSelecionado);
                    botao.setPosition(posicaoBotaox, posicaoBotaoy);
                    botoes.push_back(botao);
                }
                    break;
                case 1:{
                    Botao botao(larguraBotao, alturaBotao, texturaBotaoSairNormal, texturaBotaoSairSelecionado, texturaBotaoSairSelecionado);
                    botao.setPosition(posicaoBotaox, posicaoBotaoy);
                    botoes.push_back(botao);
                }
                    break;
                default:
                    break;
            }
        }

        std::vector<std::string> optionsTexts={"Play","Exit"};

        // for(size_t i = 0; i < optionsTexts.size(); ++i){
        //     sf::Text option(optionsTexts[i], font, 30);
        //     option.setFillColor(i== 0 ?sf::Color::Red:sf::Color::White);
        //     option.setPosition(200,200 + i * 50);
        //     options.push_back(option);
        // }
        if(!musicaAmbiente.openFromFile("Assets/Audios/the-origin-menu.mp3")){
            throw std::runtime_error("Falha ao carregar musica ambiente");
        }
        musicaAmbiente.play();
        musicaAmbiente.setLoop(true);
    }catch(std::exception& e){
        std::cerr<<"Erro ao iniciar menu"<<e.what()<<std::endl;
    }
}

void MainMenuState::carregarRecursos(){
    if(!font.loadFromFile("Assets/Fonts/TrulyMadlyDpad-a72o.ttf")){
        throw std::runtime_error("Erro ao carregar fonte");
    }

    if(!texturaAmbienteMenu.loadFromFile("Assets/Textures/menu-background.png")){
        throw std::runtime_error("Erro ao carregar plano de fundo");
    }

    if(!texturaPainelMenu.loadFromFile("Assets/Textures/painel-menu.png")){
        throw std::runtime_error("Erro ao carregar plano de fundo");
    }

    if(!texturaBotaoJogarNormal.loadFromFile("Assets/Textures/botao-jogar-textura-normal.png")){
        throw std::runtime_error("Erro ao carregar textura botão jogar");
    }

    if(!texturaBotaoJogarSelecionado.loadFromFile("Assets/Textures/botao-jogar-textura-selecionada.png")){
        throw std::runtime_error("Erro ao carregar textura botão jogar");
    }

    if(!texturaBotaoSairNormal.loadFromFile("Assets/Textures/botao-sair-textura-normal.png")){
        throw std::runtime_error("Erro ao carregar textura botão sair");
    }

    if(!texturaBotaoSairSelecionado.loadFromFile("Assets/Textures/botao-sair-textura-selecionada.png")){
        throw std::runtime_error("Erro ao carregar textura botão sair");
    }
}

#endif
