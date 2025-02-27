#include "PainelControle.hpp"

PainelControle::PainelControle(){
    inicializarPainel();
}

void PainelControle::inicializarPainel(){
    try{
        valorNeon = 35000;
        numeroDia = 1;

        if(!texturaFundoPainel.loadFromFile("Recursos/Textures/fundo_painel_controle.png")){
            std::cerr<<"Erro ao carregar textura fundo do painel"<<std::endl;
        }
        if(!texturaComandante.loadFromFile("Recursos/Textures/textura_comandante.png")){
            std::cerr<<"Erro ao carregar textura comandante no painel"<<std::endl;
        }
        if(!texturaNeonPainel.loadFromFile("Recursos/Textures/fundo_neon_painel.png")){
            std::cerr<<"Erro ao carregar textura neon painel"<<std::endl;
        }
        if(!texturaBotaoNormal.loadFromFile("Recursos/Textures/tetura_botao_painel_normal.png")){
            std::cerr<<"Erro ao carregar textura botao painel"<<std::endl;
        }
        if(!texturaBotaoSelecionado.loadFromFile("Recursos/Textures/tetura_botao_painel_selecionado.png")){
            std::cerr<<"Erro ao carregar textura botao painel"<<std::endl;
        }
        if(!texturaBlocoItem.loadFromFile("Recursos/Textures/bloco_item.png")){
            std::cerr<<"Erro ao carregar textura do bloco painel"<<std::endl;
        }
        spriteFundoPainel.setTexture(texturaFundoPainel);
        spriteComandante.setTexture(texturaComandante);
        spriteNeonPainel.setTexture(texturaNeonPainel);
    }catch(std::exception& e){
        std::cerr<<"Erro ao carregar textura do painel"<<e.what()<<std::endl;
    }
}

void PainelControle::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(spriteFundoPainel,states);
    target.draw(spriteComandante,states);
    target.draw(spriteNeonPainel,states);
    target.draw(textTituloNeon,states);
    target.draw(textValorNeon,states);

    for(Botao* botao : botoes){
        target.draw(*botao,states);
    }

    for(BlocoItemPainel * bloco : blocosItemPainel){
        target.draw(*bloco,states);
    }
}

void PainelControle::atribuirPosicao(float posx, float posy){
    float borda = 2.f;
    spriteFundoPainel.setOrigin(spriteFundoPainel.getLocalBounds().left, spriteFundoPainel.getLocalBounds().height/2);
    spriteFundoPainel.setPosition(posx, posy - spriteFundoPainel.getGlobalBounds().height/2 -borda);
    spriteComandante.setOrigin(spriteComandante.getLocalBounds().left, spriteComandante.getLocalBounds().height/2);
    spriteComandante.setPosition(spriteFundoPainel.getPosition().x + 60.f, spriteFundoPainel.getGlobalBounds().top + spriteComandante.getLocalBounds().height/2 + 36.f);
    spriteNeonPainel.setPosition(spriteComandante.getGlobalBounds().left - 16.f,
                                 spriteFundoPainel.getPosition().y + spriteFundoPainel.getGlobalBounds().height/2 - 45.f);

    textTituloNeon.setOrigin(textTituloNeon.getLocalBounds().left, textTituloNeon.getLocalBounds().height/2);
    textTituloNeon.setPosition(spriteNeonPainel.getGlobalBounds().left + 6,
                               spriteNeonPainel.getGlobalBounds().top + textTituloNeon.getGlobalBounds().height/3 );

    //textValorNeon.setOrigin(textValorNeon.getLocalBounds().left, textValorNeon.getLocalBounds().height/2);
    textValorNeon.setPosition(textTituloNeon.getGlobalBounds().left + textTituloNeon.getGlobalBounds().width + 6.f,
                              spriteNeonPainel.getPosition().y);

    float larguraBotao = texturaBotaoNormal.getSize().x;
    float alturaBotao = texturaBotaoNormal.getSize().y;
    float posicaoX = spriteComandante.getGlobalBounds().left + larguraBotao/2;
    float posicaoY = spriteComandante.getGlobalBounds().top + spriteComandante.getGlobalBounds().height + alturaBotao*0.75f;
    std::vector<std::wstring> nomeBotoes = {L"Combatente",L"Equipamento",L"Fábrica",L"Opções"};


    botoes = Interface::criarBotoesHorizontal(larguraBotao, alturaBotao,
                                              posicaoX, posicaoY,
                                              texturaBotaoNormal, texturaBotaoSelecionado,texturaBotaoSelecionado,
                                              nomeBotoes, 0.f,0.f,16);

    float posicaoBlocoX = botoes[0]->formaBotao.getGlobalBounds().left;
    float posicaoBlocoY = botoes[0]->formaBotao.getGlobalBounds().top + botoes[0]->formaBotao.getGlobalBounds().height;

    blocosItemPainel = Interface::criarBlocosPainel(posicaoBlocoX, posicaoBlocoY,
                                                    texturaBlocoItem, 8 , 13.f);
}

void PainelControle::renderizar(sf::RenderWindow& window){
    try{
        draw(window, sf::RenderStates::Default);
    }catch(std::exception& e){
        std::cerr<<"Falha ao renderizar painel de controle"<<e.what()<<std::endl;
    }
}

sf::Vector2f PainelControle::obterPosicaoPainel(){
    float distanciaPainel = 50.f;
    sf::Vector2f posicaoTotal(sf::Vector2f(spriteFundoPainel.getLocalBounds().width + spriteFundoPainel.getPosition().x + distanciaPainel, spriteFundoPainel.getPosition().y));
    return posicaoTotal;
}

void PainelControle::atribuirFonte(sf::Font& fonte){
    try{
        textValorNeon.setFont(fonte);
        textTituloNeon.setFont(fonte);
        textValorNeon.setFillColor(sf::Color::White);
        textTituloNeon.setFillColor(sf::Color::White);
        textValorNeon.setCharacterSize(24);
        textTituloNeon.setCharacterSize(24);
        textValorNeon.setString(std::to_string(valorNeon));
        textTituloNeon.setString("neon:");

    }catch(std::exception& e){
        std::cerr<<"Falha ao atriubuir Fonte a Painel de controle"<<e.what()<<std::endl;
    }
}
