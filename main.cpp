#include <iostream>
#include "Game.hpp"
#include "TileGenerator.hpp"

int main(int argc, char **argv) {

    Game game;
    game.run(60);

    TileGenerator tileGen;
    tileGen.generateTileMap("/home/jacques/Downloads/env-game.png","/home/jacques/Downloads/tileMapNumbers.txt",32,32);
    return 0;
}
