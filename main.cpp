/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include "Game.h"



int main( int argc, char* args[] ) {
    
    Game game;   
    if (!game.init()) {
        printf( "Failed to initialize!\n" );
    }
    else game.run();

    return 0;
}