#include "GerenciadorJogo.hpp"

GerenciadorJogo::GerenciadorJogo(){
    valorPersonagens = {
        {TipoPersonagem::Tipo_Soldado, 900},
        {TipoPersonagem::Tipo_Coletor, 1500},
        {TipoPersonagem::Tipo_Aereo, 1200},
        {TipoPersonagem::Tipo_Cura, 3000},
        {TipoPersonagem::Tipo_Curto_Ataque, 1800},
        {TipoPersonagem::Tipo_Longo_Ataque, 2000},
        {TipoPersonagem::Tipo_Hibrido, 3500}
    };
}

unsigned short GerenciadorJogo::obterValorPersonagem(TipoPersonagem tipo){
    unsigned short valor = valorPersonagens[tipo];
    return valor;
}

