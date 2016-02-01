/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: sam
 * 
 * Created on 29 January 2016, 2:38 PM
 */

#include "Game.h"

Game::Game() {
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

bool Game::init() {
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        if( !gameWindow.open() ) {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        
        globalTimer.start();
    }
    return success;
}

void Game::run() {

    tex2.setWindow(&gameWindow);
    tex.setWindow(&gameWindow);
    tex.loadFromFile("Sprites/Sprite5.png");
    
    quit = false;

    loopTimer.start();
    timeDelta = loopTimer.getMillis();
    
    
    //While application is running
    while( !quit ) {
        loopTimer.refresh();
        
        // gameUpdate loop
        do {
            inputUpdate();
            gameUpdate();
            
            timeDelta = loopTimer.getMillis();
            
        }   while( timeDelta*1000 < targetFPS );
        
        render();
        
    }

    //Free resources and close SDL
    close();
}

unsigned long Game::getGLobalTime() { return globalTimer.getMillis();
}

void Game::inputUpdate() {
    SDL_Event e;
    
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ) {
        
        if( e.type == SDL_QUIT ) {
            quit = true;
        }
    }
}

void Game::gameUpdate() {

}

void Game::render() {

    if (!gameWindow.isMinimized()) {
            gameWindow.clearScreen();
            tex.renderToTexture(&tex2,
                        80,
                        80, 
                        NULL, 
                        0.0, 
                        NULL, 
                        SDL_FLIP_NONE);
            
            tex.renderToTexture(&tex2,
                        gameWindow.getWidth() + 3,
                        gameWindow.getHeight() + 3, 
                        NULL, 
                        30, 
                        NULL, 
                        SDL_FLIP_NONE);
            
            
            // render all textures to gameWindow;
            tex2.render( gameWindow.getWidth(),
                        gameWindow.getHeight(), 
                        NULL, 
                        0.0, 
                        NULL, 
                        SDL_FLIP_NONE);
            //
            gameWindow.render();
        }
}

void Game::close()
{
    gameWindow.close();

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

