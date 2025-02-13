#ifndef FABRICAJOGADOR_HPP
#define FABRICAJOGADOR_HPP

#include "../Player/Player.hpp"
#include "../Personagem/Soldado.hpp"
#include "../Personagem/Coletor.hpp"
#include "../Personagem/TipoPersonagem.hpp"
#include <unordered_map>
#include <functional>

class FabricaJogador{
public:
    using CriadorFuncao = std::function<Player*(float, float)>;
    static Player* criarJogador(float posx, float posy,TipoPersonagem tipo);

    template<typename T>
    static void registrar(TipoPersonagem tipo){
        registradores[tipo] = [=](float x, float y) -> Player* {
            return new T(x, y, tipo);
        };
    }
    static void registrarPersonagens(){
        FabricaJogador::registrar<Soldado>(Tipo_Soldado);
        FabricaJogador::registrar<Coletor>(Tipo_Coletor);
    }
private:
    bool possuiRecurso(TipoPersonagem tipo) const;
    void gastarRecurso(TipoPersonagem tipo);
    static std::unordered_map<TipoPersonagem, CriadorFuncao> registradores;
};
#endif
