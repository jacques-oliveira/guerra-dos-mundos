#ifndef MAIN_MENU_STATE_CPP
#define MAIN_MENU_STATE_CPP

#include "MainMenuState.hpp"
#include<stdexcept>
#include <iostream>

MainMenuState::MainMenuState(sf::RenderWindow* _window): selectedOption(0), continueGame(false), exitGame(false){
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
            for(auto* botao : botoes){
                botao->atualizar(window, event);
                if(botao->obterEventoBotao()){
                    if(botao->obterNomebotao() == "JOGAR"){
                        continueGame = true;
                    }else{
                        exitGame = true;
                    }
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
        window.setView(view);
        window.draw(spriteAmbienteMenu);
        window.draw(spritePainelMenu);


        for(Botao* botao : botoes){
            botao->renderizar(window);
        }
        window.display();

    }catch(std::exception& e){
        std::cerr<<"Erro ao renderizar menu"<<e.what()<<std::endl;
    }
}

void MainMenuState::updateOptionColors(){
}

bool MainMenuState::shouldContinue() const{
    return continueGame;
}

bool MainMenuState::shouldExit() const{
    return exitGame;
}

void MainMenuState::initMenu(sf::RenderWindow* _window){
    try{
        if(_window != nullptr){
            view = sf::View(sf::FloatRect(0, 0, _window->getSize().x, _window->getSize().y));
            std::cout<<_window->getSize().x<<std::endl;
            modoFullScreen(*_window, view);
        }
        carregarRecursos();

        larguraTela = _window->getSize().x;
        alturaTela = _window->getSize().y;

        spritePainelMenu.setTexture(texturaPainelMenu);
        spritePainelMenu.setOrigin(spritePainelMenu.getLocalBounds().left + spritePainelMenu.getLocalBounds().width/2,
                                    spritePainelMenu.getLocalBounds().top + spritePainelMenu.getLocalBounds().height/2);

        spritePainelMenu.setPosition(larguraTela/2, alturaTela/2 );
        spriteAmbienteMenu.setTexture(texturaAmbienteMenu);
        fatorEscala(*_window, spriteAmbienteMenu);

        //spriteAmbienteMenu.setScale(fatorEscala,fatorEscala);

        float larguraBotao = texturaBotaoNormal.getSize().x + 0.1f;
        float alturaBotao = texturaBotaoNormal.getSize().y + 0.1f;
        float espacoBotao = 20.f;

        float posicaoBotaox = larguraTela/2;
        float posicaoBotaoy = spritePainelMenu.getPosition().y/2 + (alturaTela -alturaBotao)/2;

        for(size_t i = 0; i < 2; ++i){
            posicaoBotaoy = spritePainelMenu.getPosition().y/2 + (alturaTela -alturaBotao)/2 +  i * ( alturaBotao + espacoBotao );
            switch(i){
                case 0:{
                    Botao * botao = new Botao(larguraBotao, alturaBotao, texturaBotaoNormal, texturaBotaoSelecionado, texturaBotaoSelecionado,"JOGAR");
                    botao->setPosition(posicaoBotaox, posicaoBotaoy);
                    botoes.push_back(botao);
                }
                    break;
                case 1:{
                    Botao * botao = new Botao(larguraBotao, alturaBotao, texturaBotaoNormal, texturaBotaoSelecionado, texturaBotaoSelecionado,"SAIR");
                    botao->setPosition(posicaoBotaox, posicaoBotaoy);
                    botoes.push_back(botao);
                }
                    break;
                default:
                    break;
            }
        }
        tocarMusicaAmbiente();
    }catch(std::exception& e){
        std::cerr<<"Erro ao iniciar menu"<<e.what()<<std::endl;
    }
}

MainMenuState::~MainMenuState(){
    if(botoes.size() > 0){
        for(auto * botao : botoes){
            delete botao;
            botao = nullptr;
        }
    }
}

void MainMenuState::carregarRecursos(){
    try{
        if(!font.loadFromFile("Recursos/Fonts/TrulyMadlyDpad-a72o.ttf")){
            throw std::runtime_error("Erro ao carregar fonte");
        }

        if(!texturaAmbienteMenu.loadFromFile("Recursos/Textures/menu-background.png")){
            throw std::runtime_error("Erro ao carregar plano de fundo");
        }

        if(!texturaPainelMenu.loadFromFile("Recursos/Textures/painel-menu.png")){
            throw std::runtime_error("Erro ao carregar plano de fundo");
        }

        if(!texturaBotaoNormal.loadFromFile("Recursos/Textures/textura_botao_normal_menu.png")){
            throw std::runtime_error("Erro ao carregar textura botão jogar");
        }

        if(!texturaBotaoSelecionado.loadFromFile("Recursos/Textures/textura_botao_selecionado_menu.png")){
            throw std::runtime_error("Erro ao carregar textura botão jogar");
        }

    }catch(std::exception& e){
        std::cerr<<"Erro ao carregar recursos menu"<<e.what()<<std::endl;
    }
}

void MainMenuState::tocarMusicaAmbiente(){
    try{
        if(!musicaAmbiente.openFromFile("Recursos/Audios/the-origin-menu.mp3")){
            throw std::runtime_error("Falha ao carregar musica ambiente");
        }
        musicaAmbiente.play();
        musicaAmbiente.setLoop(true);
    }catch(std::exception& e){
        std::cerr<<"Erro ao tocar som ambiente menu"<<e.what()<<std::endl;
    }
}

#endif
