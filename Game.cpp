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
#include <iostream>
#include <stdio.h>

Game::Game() {
    timeDelta = 0;
    frameCount = 0;
    targetFrameTime = 1.0/targetFPS;
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

bool Game::init() {
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0 ) {
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
    inputComponent = InputComponent();
    inputComponent.init();
    
    return success;
}

void Game::run() {

    tex2.setWindow(&gameWindow);
    tex.setWindow(&gameWindow);
    tex.loadFromFile("Sprites/Sprite5.png");
    
    
    quit = false;
    
    loopTimer.start();
    deltaTimer.start();

    int frameRate = 0;

    //While application is running
    while( !quit ) {
        
        inputUpdate();
        loopTimer.refresh();
        
        // gameUpdate loop
        while( loopTimer.getSeconds() < targetFrameTime ){
            
            timeDelta = deltaTimer.getSeconds();
            deltaTimer.refresh();

            gameUpdate(timeDelta);   
        }

        render();
        
        
        
        frameCount++;
        
        if (globalTimer.getSeconds() > 0) {
            frameRate = frameCount/globalTimer.getSeconds();
            std::cout << frameRate << std::endl;
        }
    }

    //Free resources and close SDL
    close();
}

unsigned long Game::getGLobalTime() { return globalTimer.getMillis();
}

void Game::inputUpdate() {
    SDL_Event e;
    
    if (inputComponent.updateInputs()) quit = true;
}

void Game::gameUpdate(double _d) {

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
