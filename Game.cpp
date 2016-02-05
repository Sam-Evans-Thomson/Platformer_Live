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
#include "Window/Texture.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

extern Window gameWindow;
extern Canvas canvas;
extern Player player;
extern InputComponent inputComponent;

Game::Game() {
    timeDelta = 0;
    frameCount = 0;
    targetFrameTime = 1.0/targetFPS;
}

Game::Game(const Game& orig) {
    
}

Game::~Game() {
    delete &canvas;
    delete &player;
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

    inputComponent.init();

    return success;
}

void Game::initHeap() {
    player.init();
    canvas.init();
}

void Game::run() {

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
        display();
        
        
        frameCount++;
        
        if (globalTimer.getSeconds() > 0) {
            frameRate = frameCount/globalTimer.getSeconds();
        }
    }

    //Free resources and close SDL
    close();
}

unsigned long Game::getGLobalTime() { return globalTimer.getMillis(); }

void Game::inputUpdate() {
    SDL_Event e;
    
    if (inputComponent.updateInputs()) quit = true;
}

void Game::gameUpdate(double _d) {

}

void Game::render() {
    Texture tex;
    Texture tex2;
    Texture* blank = new Texture();
    tex.loadFromFile("Sprites/Running/basic4.png");
    tex2.loadFromFile("Sprites/Running/basic1.png");
    blank->createBlank(1920,1080);
    
    tex2.render(0,0,NULL,0,NULL,SDL_FLIP_NONE);
 
    delete blank;
    
    canvas.addTexture(&tex,100.0,100.0,0,1.0,0.0);
    
    //player.render(&canvas);
}

void Game::display() {
    canvas.render();
    gameWindow.render();
    canvas.clearAll();
}


void Game::close()
{
    gameWindow.close();

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

