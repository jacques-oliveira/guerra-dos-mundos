
#include "Fase1.hpp"
#include <stdexcept>

Fase1::Fase1(const std::string& _levelName) : Fase(_levelName){

    if (!font.loadFromFile("Assets/Fonts/Good-Game.ttf")) {
        throw std::runtime_error("Erro ao carregar fonte");
    }

    Player* soldado = FabricaJogador::criarJogador(100,50,SoldierType);
    Player* soldado2 = FabricaJogador::criarJogador(280,80,SoldierType);
    Player* soldado3 = FabricaJogador::criarJogador(100,150,SoldierType);
    players.push_back(soldado);
    players.push_back(soldado2);
    players.push_back(soldado3);
    dynamic_cast<Soldado*>(soldado)->gritoAtaque();
    initLevel(_levelName);
}

Fase1::~Fase1(){
}

void Fase1::processEvents(sf::RenderWindow& _window, bool * isRunning) {
    try{
        sf::Event event;
        window = &_window;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                exitGame = true;
                if(shouldExit()){
                    *isRunning = false;
                    window->close();
                }

            }

            if(event.type == sf::Event::MouseButtonPressed){

                sf::Vector2f start = _window.mapPixelToCoords(sf::Mouse::getPosition(_window),view);
                startSelection(start);

            }else if(sf::Event::MouseMoved){
                if(isSelectingPlayer){
                    sf::Vector2f destination = _window.mapPixelToCoords(sf::Mouse::getPosition(_window),view);
                    updateSelection(destination);

                    for(auto& player : players){
                        if(player->isInside(selectionBox.getGlobalBounds())){
                            player->setSelected(true);
                            cout<<"Selecionado "<<player->isPlayerSelected()<<endl;
                        }
                    }

                }
            }
            if(event.type == sf::Event::MouseButtonReleased){
                endSelection();
            }
            if(event.mouseButton.button == sf::Mouse::Right){
                for (auto& player : players) {
                    player->unselectPlayer(true);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f destination = _window.mapPixelToCoords(sf::Mouse::getPosition(_window), view);
                for (auto& player : players) {
                    if (player->isPlayerSelected()) {
                        moveSelectedPlayers(destination);
                    }
                }
            }

        }

    }catch(exception&){
        cerr<<"Erro ao tratar processo Fase1"<<endl;
    }
}

void Fase1::update(sf::Time deltaTime) {
    try{
        for(auto& player : players){
            if(player != nullptr){
                player->update(deltaTime);
                player->resolveCollision(*enemy->collider);
                sf::Vector2f playerPosition = player->getPlayerSprite().getPosition();
                sf::Vector2f targetCenter(playerPosition.x +100, playerPosition.y + 100);
                sf::Vector2f currentCenter = view.getCenter();

                sf::Vector2f smoothedCenter = currentCenter + (targetCenter - currentCenter) * 0.05f;
                view.setCenter(smoothedCenter);
                view.move(10,5);
                if(window != nullptr){
                    float ratio = (float)window->getSize().y / (float)window->getSize().x;
                    setViewSize(ratio);
                    window->setView(view);
                }else{
                    cerr<<"Window não foi inicializado"<<endl;
                }
            }else{
                cerr<<"Player não foi inicializado"<<endl;
            }
        }

    }catch(exception& e){
        cerr<<"Falha ao atualizar Fase "<<e.what()<<endl;
    }
}

void Fase1::render(sf::RenderWindow& window) {
    try{
        window.clear();
        tileGen->drawMap(window);
        for(auto& p : players){
            p->render(window);
        }
        enemy->render(window);
        window.draw(selectionBox);
        //player->render(window);
        window.setView(uiView);

        window.draw(levelText);
        window.display();

    }catch(exception&){
        cerr<<"Falha ao renderizar estado"<<endl;
    }
}

void Fase1::initLevel(std::string _levelName){
    levelName = _levelName;
    levelCompleted = false;

    levelText.setFont(font);
    levelText.setString("Playing " + levelName);
    levelText.setCharacterSize(30);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(10, 10);
    //player = new Soldado(100,100,SoldierType);
    enemy = new Enemy(SoldierType);
}
