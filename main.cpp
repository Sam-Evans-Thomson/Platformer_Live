/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include "Game.h"

Game game; 
Window gameWindow;
Canvas canvas;
Player player;
InputComponent inputComponent;
LevelManager levelManager;
ResourceManager resourceManager;
 

int main( int argc, char* args[] ) {
    
    
    if (!game.init()) {
        printf( "Failed to initialize!\n" );
    }
    else game.run();

    return 0;
    
}