#ifndef EXTRACTOR_HPP
#define EXTRACTOR_HPP

#include "../Player/Player.hpp"

class Extractor : public Player{
public:
    Extractor(float posx, float posy, CharacterType type);
    ~Extractor();

};
#endif
