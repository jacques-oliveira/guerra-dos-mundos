
#include "Fase1.hpp"
#include <stdexcept>

Fase1::Fase1(const std::string& _levelName, sf::RenderWindow* refJanela) : Fase(_levelName){

    // if (!font.loadFromFile("Assets/Fonts/Good-Game.ttf")) {
    //     throw std::runtime_error("Erro ao carregar fonte Fase1");
    // }

    fontesEnergia.push_back(new FonteEnergia(300,1850,1500)) ;
    fontesEnergia.push_back(new FonteEnergia(3600,560,1500)) ;
    /*= new FonteEnergia(120,10,1500);*/
    initLevel(_levelName, refJanela);

    criarSoldados();

}

Fase1::~Fase1(){
    if(!players.empty()){
        for(auto& player : players){
            delete player;
            player = nullptr;
        }
        players.clear();
    }
    if(!fontesEnergia.empty()){
        for(auto& fonte : fontesEnergia){
            delete fonte;
            fonte = nullptr;
        }
    }
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

            selecaoPersonagens(event, _window);

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f destination = _window.mapPixelToCoords(sf::Mouse::getPosition(_window), view);
                for (auto& player : players) {
                    if (player->isPlayerSelected()) {
                        player->isMoving =true;
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

                sf::Vector2f currentCenter = view.getCenter();

                if(window != nullptr){
                    // float ratio = (float)window->getSize().y / (float)window->getSize().x;
                    // setViewSize(view,ratio);

                    moverViewMouse();
                }else{
                    cerr<<"Window não foi inicializado"<<endl;
                }
                clock.restart();
            }else{
                cerr<<"Player não foi inicializado"<<endl;
            }
        }

        for(auto& fe : fontesEnergia){
            fe->atualizar();
        }

    }catch(exception& e){
        cerr<<"Falha ao atualizar Fase "<<e.what()<<endl;
    }
}

void Fase1::render(sf::RenderWindow& window) {
    try{
        window.clear();
        window.setView(view);
        tileGen->drawMap(window);

        window.draw(spriteMapaFase1);
        for(auto& p : players){
            p->render(window);
        }
        for(auto& fe : fontesEnergia){
            fe->renderizar(window);
        }

        enemy->render(window);
        window.draw(selectionBox);
        window.setView(uiView);

        window.draw(spriteFundoNeon);
        window.draw(textoNeon);
        window.draw(valorNeon);
        barraMensagem.render(window);
        //spriteMiniMapa.setPosition({window.getSize().x - (spriteMiniMapa.getTexture()->getSize().x + 20.f),window.getSize().y-20.f});
        window.draw(spriteMiniMapa);
        window.display();

    }catch(exception& e){
        cerr<<"Falha ao renderizar estado"<<e.what()<<endl;
    }
}

void Fase1::initLevel(std::string _levelName, sf::RenderWindow* window){
    try{
        if(window != nullptr){
            float tamanhoJanelaX = window->getSize().x;
            float tamanhoJanelaY = window->getSize().y;
            view = sf::View(sf::FloatRect(0, 0, tamanhoJanelaX, tamanhoJanelaY));
            uiView = view;
            cout<<window->getSize().x<<endl;
            modoFullScreen(*window, view);
            //fatorEscala(*window,spriteFundoNeon);
            velocidadeView = 440.f;
            bordaMargem = 50.f;
            levelName = _levelName;
            levelCompleted = false;
            if(!textureMapaFase1.loadFromFile("Assets/Textures/mapa-fase1.png")){
                cerr<<"Erro ao carregar textura mapa fase 1"<<endl;
                return;
            }
            spriteMapaFase1.setTexture(textureMapaFase1);
            spriteMiniMapa.setPosition({ window->getSize().x -( texturaMiniMapa.getSize().x + 40.f)
                                        ,window->getSize().y -( texturaMiniMapa.getSize().y + 40.f)});
            fatorEscala(*window,spriteMiniMapa);
            barraMensagem.atribuirPosicao(tamanhoJanelaX/2 - 300.f, tamanhoJanelaY - 60.f, tamanhoJanelaX);
            enemy = new Enemy(Tipo_Soldado);
        }
    }catch(exception& e){
        cerr<<"Falha ao iniciar Fase1"<<e.what()<<endl;
    }
}

void Fase1::criarSoldados(){
    try{
        FabricaJogador::registrarPersonagens();
        Player* soldado = FabricaJogador::criarJogador<Soldado>(100,50,Tipo_Soldado);
        Player* soldado2 = FabricaJogador::criarJogador<Soldado>(280,80,Tipo_Soldado);
        Player* soldado3 = FabricaJogador::criarJogador<Coletor>(100,150,Tipo_Coletor);
        Player* soldadoAereo = FabricaJogador::criarJogador<Aereo>(140,90,Tipo_Aereo);
        players.push_back(soldado);
        players.push_back(soldado2);
        players.push_back(soldado3);
        players.push_back(soldadoAereo);

        Soldado* soldadoCast = dynamic_cast<Soldado*>(soldado);
        Coletor* coletorCast = dynamic_cast<Coletor*>(soldado3);
        Aereo* aereoCast = dynamic_cast<Aereo*>(soldadoAereo);

        if(soldadoCast){
            soldadoCast->gritoAtaque();
        }else{
            cerr<<"Falha ao fazer cast de Soldado"<<endl;
        }

        if(coletorCast){
            coletorCast->coletarRecurso();
        }else{
            cerr<<"Falha ao fazer cast de Coletor"<<endl;
        }

        if(aereoCast){
            cout<<"Cast aereo feito!"<<endl;
        }else{
            cerr<<"Falha ao fazer cast de Aereo"<<endl;
        }

    }catch(exception& e){
        cerr<<"Falha ao criar soldados Fase1"<<e.what()<<endl;
    }
}

void Fase1::selecaoPersonagens(sf::Event& event, sf::RenderWindow& _window){
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
}

void Fase1::moverViewMouse(){
    if(window->hasFocus()){

        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        sf::Vector2f moverView({0,0});

        if(mousePos.x < bordaMargem){
            moverView.x -= velocidadeView * clock.getElapsedTime().asSeconds();
        }
        if(mousePos.x > window->getSize().x - bordaMargem){
            moverView.x += velocidadeView * clock.getElapsedTime().asSeconds();
        }
        if(mousePos.y < bordaMargem){
            moverView.y -= velocidadeView * clock.getElapsedTime().asSeconds();
        }
        if(mousePos.y > window->getSize().y - bordaMargem){
            moverView.y += velocidadeView * clock.getElapsedTime().asSeconds();
        }

        sf::Vector2f newCenter = view.getCenter() + moverView;
        sf::Vector2f halfSize = view.getSize() / 2.0f;

        if (newCenter.x - halfSize.x < 0)
            newCenter.x = halfSize.x;
        if (newCenter.x + halfSize.x > 4096)
            newCenter.x = 4096- halfSize.x;
        if (newCenter.y - halfSize.y < 0)
            newCenter.y = halfSize.y;
        if (newCenter.y + halfSize.y > 3072)
            newCenter.y = 3072 - halfSize.y;

        view.setCenter(newCenter);
    }
    window->setView(view);
}

