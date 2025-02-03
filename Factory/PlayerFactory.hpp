#ifndef PLAYERFACTORY_HPP
#define PLAYERFACTORY_HPP

#include "../Player/Player.hpp"
#include <unordered_map>

class PlayerFactory{
public:
    static Player* createPlayer(CharacterType type);

private:
    bool hasEnoughResources(CharacterType type) const;
    void spendResources(CharacterType type);
};
#endif
