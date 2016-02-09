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
extern LevelManager levelManager;

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
    delete &levelManager;
    delete platform;
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
    
    ///////////////////Testing////////////////////////
    levelManager.init();
    
    platform = new BasicPlatform(3840, 2940, 1, 1700, 100.0);
    platform->setGraphicPath("Sprites/ground");
    platform->init(0);
    platform->init(1);
    platform->setGraphicDimensions(0,-3.0,0.0,0.0,GRAPHIC_CLIP);
    
    platform2 = new BasicPlatform(1600, 600.0, 1, 600, 200.0);
    platform2->setGraphicPath("Sprites/ground");
    platform2->init(0);
    platform2->init(1);
    platform2->setGraphicDimensions(0,-3.0,0.0,0.0,GRAPHIC_CLIP);
    
    levelManager.addPlatform(platform);
    levelManager.addPlatform(platform2);

    bgd.loadFromFile("Sprites/background0.png");
    fgd.loadFromFile("Sprites/vine.png");
    //////////////////////////////////////////////
    
    
    quit = false;
    
    loopTimer.start();
    deltaTimer.start();

    int frameRate = 0;

    //While application is running
    while( !quit ) {
        
        
        loopTimer.refresh();
        
        inputUpdate();
        timeDelta = deltaTimer.getSeconds();
        deltaTimer.refresh();

        gameUpdate(timeDelta);   

        render();
        display();
        
        
        frameCount++;
        
        if (globalTimer.getSeconds() > 0) {
            frameRate = frameCount/globalTimer.getSeconds();
            //std::cout << frameRate << std::endl;
        }
        
        while( loopTimer.getSeconds() < targetFrameTime ){}
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
    player.update(_d);
}

void Game::render() {
    
        
    
    canvas.addBackgroundTexture(&bgd, 3840, 2160,NULL, 1.0, 0.0);
    canvas.addBackgroundTexture(&bgd, DEFAULT_W, 0.0,NULL, 1.0, 0.0);
    
    
    
    canvas.addForegroundTexture(&fgd, 3840+400, 2160, NULL, 2.0, 0.0);
    canvas.addForegroundTexture(&fgd, 4440, 2060, NULL, 1.8, 0.0);
    
    
    levelManager.render();
    player.render();
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

