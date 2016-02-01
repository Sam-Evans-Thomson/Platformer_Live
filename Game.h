/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: sam
 *
 * Created on 29 January 2016, 2:38 PM
 */

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Window/Window.h"
#include "Window/Texture.h"
#include "Utilities/Timer.h"
#include "InputComponent.h"



class Game {
public:
    
    Window gameWindow;
    
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    unsigned long getGLobalTime();

        //Starts up SDL and creates window
    bool init();
    
    void run();

    
    //Frees media and shuts down SDL
    void close();
    

private:
    Timer globalTimer;
    Timer loopTimer;  
    Timer deltaTimer;
    
    const int targetFPS = 60;
    double targetFrameTime;
    
    unsigned long frameCount;
    
    bool quit;
    
    double timeDelta;
    
    void inputUpdate();
    void gameUpdate(double _d);
    void render();
    
    InputComponent inputComponent;
    
    
    Texture tex;
    Texture tex2;
};

#endif /* GAME_H */

