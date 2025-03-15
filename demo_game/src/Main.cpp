





#include <iostream>
#include "Game.h"



int main(int argc, char* argv[]) {
    
    
    Game game;
    game.initialize();

    while (game.running())
    {
        game.run();
    }

    game.shutDown();

    return 0;
}
