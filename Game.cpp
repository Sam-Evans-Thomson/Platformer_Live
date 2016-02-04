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
#include "Player/Player.h"
#include "InputComponent.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

Game::Game() {
    timeDelta = 0;
    frameCount = 0;
    targetFrameTime = 1.0/targetFPS;
}

Game::Game(const Game& orig) {
    
}

Game::~Game() {
    close();
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
        
        initHeap();
        
        globalTimer.start();
    }

    inputComponent->init();

    return success;
}

void Game::initHeap() {
    inputComponent = new InputComponent();
    p = new Player(inputComponent);

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
        }
    }

    //Free resources and close SDL
    close();
}

unsigned long Game::getGLobalTime() { return globalTimer.getMillis();
}

void Game::inputUpdate() {
    SDL_Event e;
    
    if (inputComponent->updateInputs()) quit = true;
}

void Game::gameUpdate(double _d) {

}

void Game::render() {

    if (!gameWindow.isMinimized()) {
            
            for (int i = 0; i < 20; i++ ) {
                tex.renderToTexture(&tex2,
                        100*i,
                        60*i, 
                        NULL, 
                        0.0, 
                        NULL, 
                        SDL_FLIP_NONE);
            }
            
            // render all textures to gameWindow;
            tex2.render(0,
                        0, 
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

