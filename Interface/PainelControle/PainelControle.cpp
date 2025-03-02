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
        if(!texturaBotaoOperacaoNormal.loadFromFile("Recursos/Textures/textura_botao_operacao_normal.png")){
            std::cerr<<"Erro ao carregar textura do botão operação do painel"<<std::endl;
        }
        if(!texturaBotaoOperacaoSelecionado.loadFromFile("Recursos/Textures/textura_botao_operacao_selecionado.png")){
            std::cerr<<"Erro ao carregar textura do botão operação do painel"<<std::endl;
        }
        spriteFundoPainel.setTexture(texturaFundoPainel);
        spriteComandante.setTexture(texturaComandante);
        spriteNeonPainel.setTexture(texturaNeonPainel);
        spriteNeonPainel.setOrigin(spriteNeonPainel.getLocalBounds().left, spriteNeonPainel.getLocalBounds().height/2);
        areaAnulaMoverView.setSize(sf::Vector2f(spriteFundoPainel.getGlobalBounds().width*0.4f,50.f));
        areaAnulaMoverView.setOrigin(areaAnulaMoverView.getLocalBounds().left + areaAnulaMoverView.getLocalBounds().width/2,
                                     areaAnulaMoverView.getLocalBounds().height/2);
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
    target.draw(relogioPlaneta,states);

    for(Botao* botao : botoes){
        target.draw(*botao,states);
    }

    for(BlocoItemPainel * bloco : blocosItemPainel){
        target.draw(*bloco,states);
    }

    for(Botao * botao : botoesOperacao){
        target.draw(*botao,states);
    }
}

void PainelControle::atribuirPosicao(float posx, float posy){
    float borda = 24.f;
    spriteFundoPainel.setOrigin(spriteFundoPainel.getLocalBounds().left, spriteFundoPainel.getLocalBounds().height/2);
    spriteFundoPainel.setPosition(posx + borda, posy - spriteFundoPainel.getGlobalBounds().height/2 - borda);
    spriteComandante.setOrigin(spriteComandante.getLocalBounds().left, spriteComandante.getLocalBounds().height/2);
    spriteComandante.setPosition(spriteFundoPainel.getPosition().x + 60.f, spriteFundoPainel.getGlobalBounds().top + spriteComandante.getLocalBounds().height/2 + 36.f);
    spriteNeonPainel.setPosition(spriteComandante.getGlobalBounds().left - 16.f,
                                 spriteFundoPainel.getGlobalBounds().top + spriteFundoPainel.getGlobalBounds().height - spriteNeonPainel.getGlobalBounds().height- 5.f);

    textTituloNeon.setOrigin(textTituloNeon.getLocalBounds().left, textTituloNeon.getLocalBounds().height/2);
    textTituloNeon.setPosition(spriteNeonPainel.getGlobalBounds().left + 6,
                               spriteNeonPainel.getGlobalBounds().top + textTituloNeon.getGlobalBounds().height/3 );

    textValorNeon.setPosition(textTituloNeon.getGlobalBounds().left + textTituloNeon.getGlobalBounds().width + 6.f,
                              textTituloNeon.getPosition().y + textTituloNeon.getGlobalBounds().height/3);

    float posAnulaMoveViewX = spriteFundoPainel.getPosition().x + spriteFundoPainel.getGlobalBounds().width/2;
    float posAnulaMoveViewY = spriteNeonPainel.getPosition().y;

    areaAnulaMoverView.setPosition(spriteFundoPainel.getPosition().x + spriteFundoPainel.getGlobalBounds().width/2, posAnulaMoveViewY + spriteNeonPainel.getGlobalBounds().height/2);
}

void PainelControle::criandoItemsPainel(){
    try{
        float larguraBotao = texturaBotaoNormal.getSize().x;
        float alturaBotao = texturaBotaoNormal.getSize().y;
        float posicaoX = spriteComandante.getGlobalBounds().left + larguraBotao/2;
        float posicaoY = spriteComandante.getGlobalBounds().top + spriteComandante.getGlobalBounds().height + alturaBotao*0.75f;
        std::vector<std::wstring> nomeBotoes = {L"Combatente",L"Equipamento",L"Fábrica",L"Opções"};


        botoes = Interface::criarBotoesHorizontal(posicaoX, posicaoY,
                                                texturaBotaoNormal, texturaBotaoSelecionado,texturaBotaoSelecionado,
                                                nomeBotoes, 0.f,0.f,16);

        float posicaoBlocoX = botoes[0]->formaBotao.getGlobalBounds().left;
        float posicaoBlocoY = botoes[0]->formaBotao.getGlobalBounds().top + botoes[0]->formaBotao.getGlobalBounds().height;

        blocosItemPainel = Interface::criarBlocosPainel(posicaoBlocoX, posicaoBlocoY,
                                                        texturaBlocoItem, 8 , 13.f);

        float posicaoXRelogioPlaneta = botoes[botoes.size() -1]->formaBotao.getPosition().x +
        botoes[botoes.size() -1]->formaBotao.getGlobalBounds().width/2;

        sf::Vector2f dimensaoSpriteTempo = relogioPlaneta.dimensaoSpriteTempo();

        relogioPlaneta.atribuirPosicao(posicaoXRelogioPlaneta + dimensaoSpriteTempo.x/2,
                                    spriteComandante.getPosition().y + dimensaoSpriteTempo.y/2 +10.f);

        float posicaoXBotaoAplicar = spriteFundoPainel.getGlobalBounds().width/2;
        float posicaoYBotaoAplicar = spriteNeonPainel.getPosition().y + spriteNeonPainel.getLocalBounds().height*0.3f;

        std::vector<std::wstring> nomeBotoesOperacao = {L"Aplicar",L"Cancelar"};

        botoesOperacao = Interface::criarBotoesHorizontal(posicaoXBotaoAplicar, posicaoYBotaoAplicar,
                                            texturaBotaoOperacaoNormal, texturaBotaoOperacaoSelecionado, texturaBotaoOperacaoSelecionado,
                                            nomeBotoesOperacao, 20.f, 0.f,20);
    }catch(std::exception& e){
        std::cerr<<"Falha ao criar items do painel de controle"<<e.what()<<std::endl;
    }
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
        textValorNeon.setOrigin(textValorNeon.getLocalBounds().left, textValorNeon.getLocalBounds().height/2);
        textTituloNeon.setString("neon:");

    }catch(std::exception& e){
        std::cerr<<"Falha ao atriubuir Fonte a Painel de controle"<<e.what()<<std::endl;
    }
}
