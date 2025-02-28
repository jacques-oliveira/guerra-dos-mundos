#ifndef GERENCIADOR_JOGO_HPP
#define GERENCIADOR_JOGO_HPP

#include <iostream>
#include <map>
#include "../Personagem/TipoPersonagem.hpp"

class GerenciadorJogo{

public:
    static GerenciadorJogo& obterInstancia(){
        static GerenciadorJogo instancia;
        return instancia;
    }
    unsigned short obterValorPersonagem(TipoPersonagem tipo);
private:
    GerenciadorJogo();
    GerenciadorJogo(const GerenciadorJogo&) = delete;
    GerenciadorJogo& operator=(const GerenciadorJogo&) = delete;

    std::map<TipoPersonagem, unsigned short> valorPersonagens;
};
#endif
