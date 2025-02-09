#ifndef MAIN_MENU_STATE_CPP
#define MAIN_MENU_STATE_CPP

#include "MainMenuState.hpp"
#include<stdexcept>
#include <iostream>

MainMenuState::MainMenuState(): selectedOption(0), continueGame(false), exitGame(false){

    initMenu();
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
            }else if(event.type == sf::Event::KeyPressed){
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
        window.draw(spriteTituloMenu);
        window.draw(subTitulo);
        for(const auto& option: options){
            window.draw(option);
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

void MainMenuState::initMenu(){
    try{
        larguraTela = 1024;
        alturaTela = 768;

        if(!font.loadFromFile("Assets/Fonts/TrulyMadlyDpad-a72o.ttf")){
            throw std::runtime_error("Erro ao carregar fonte");
        }

        if(!fontSubMenu.loadFromFile("Assets/Fonts/NotoSansMono-Thin.ttf")){
            throw std::runtime_error("Erro ao carregar fonte");
        }

        if(!texturaAmbienteMenu.loadFromFile("Assets/Textures/menu-background.png")){
            throw std::runtime_error("Erro ao carregar plano de fundo");
        }

        if(!texturaTituloMenu.loadFromFile("Assets/Textures/titulo-menu.png")){
            throw std::runtime_error("Erro ao carregar plano de fundo");
        }

        if(!texturaPainelMenu.loadFromFile("Assets/Textures/painel-menu.png")){
            throw std::runtime_error("Erro ao carregar plano de fundo");
        }

        spriteAmbienteMenu.setTexture(texturaAmbienteMenu);
        spriteTituloMenu.setTexture(texturaTituloMenu);
        spritePainelMenu.setTexture(texturaPainelMenu);
        // title.setFont(font);
        subTitulo.setFont(fontSubMenu);
        motivoTitulo.setFont(font);
        short tamanhoFonte = 70;
        sf::Color corFont = sf::Color::White;

        // title.setString("GUERRA DOS MUNDOS");
        // title.setCharacterSize(tamanhoFonte);
        // title.setFillColor(corFont);
        // sf::FloatRect titleRect =title.getGlobalBounds();
        // title.setOrigin(titleRect.left + titleRect.width/2.f, titleRect.top + titleRect.height*2);
        // title.setPosition(larguraTela/2.f, alturaTela/2.f);
        // title.setOutlineThickness(2.f);

        subTitulo.setString("EM BUSCA DO DESCONHECIDO");
        subTitulo.setCharacterSize(25);
        subTitulo.setFillColor(sf::Color::White);
        sf::FloatRect subTituloRect = subTitulo.getGlobalBounds();
        subTitulo.setOrigin(subTituloRect.left + subTituloRect.width/2, subTituloRect.top + subTituloRect.height* 2);
        subTitulo.setPosition(larguraTela/2.f, alturaTela/2.f + spriteTituloMenu.getPosition().y + subTituloRect.height*3);


        std::vector<std::string> optionsTexts={"Play","Exit"};

        for(size_t i = 0; i < optionsTexts.size(); ++i){
            sf::Text option(optionsTexts[i], font, 30);
            option.setFillColor(i== 0 ?sf::Color::Red:sf::Color::White);
            option.setPosition(200,200 + i * 50);
            options.push_back(option);
        }
        if(!musicaAmbiente.openFromFile("Assets/Audios/the-origin-menu.mp3")){
            throw std::runtime_error("Falha ao carregar musica ambiente");
        }
        musicaAmbiente.play();
        musicaAmbiente.setLoop(true);
    }catch(std::exception& e){
        std::cerr<<"Erro ao iniciar menu"<<e.what()<<std::endl;
    }
}

#endif
