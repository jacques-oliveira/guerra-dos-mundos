#ifndef MAIN_MENU_STATE_CPP
#define MAIN_MENU_STATE_CPP

#include "MainMenuState.hpp"
#include<stdexcept>

MainMenuState::MainMenuState(): selectedOption(0), continueGame(false), exitGame(false){
    if(!font.loadFromFile("Assets/Fonts/Good-Game.ttf")){
        throw std::runtime_error("Erro ao carregar fonte");
    }

    title.setFont(font);
    title.setString("Game Menu");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(200,100);

    std::vector<std::string> optionsTexts={"Play","Exit"};
    for(size_t i = 0; i < optionsTexts.size(); ++i){
        sf::Text option(optionsTexts[i], font, 30);
        option.setFillColor(i== 0 ?sf::Color::Red:sf::Color::White);
        option.setPosition(200,200 + i * 50);
        options.push_back(option);
    }
}

void MainMenuState::processEvents(sf::RenderWindow& window, bool * isRunning){
    sf::Event event;
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
}

void MainMenuState::update(sf::Time deltaTime){
}

void MainMenuState::render(sf::RenderWindow& window){
    window.clear();
    window.draw(title);
    for(const auto& option: options){
        window.draw(option);
    }
    window.display();
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

#endif
