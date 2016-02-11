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

#include "Window/Window.h"
#include "Window/Canvas.h"
#include "Player/Player.h"
#include "InputComponent.h"
#include "Level/LevelManager.h"

#include "Utilities/Timer.h"
#include "Graphics/Graphic.h"

#include "Level/LevelObjects/BasicPlatform.h"

class Game {
public:

    
    Game();
    Game(const Game& orig);
    ~Game();
    
    unsigned long getGLobalTime();

        //Starts up SDL and creates window
    bool init();
        
        // initialize Heap objects.
    void initHeap();
    
    void run();

    
    //Frees media and shuts down SDL
    void close();
   
    
    
private:
    
    BasicPlatform* platform;
    BasicPlatform* platform2;
    BasicPlatform* platform3;
    
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
    void display();

};

#endif /* GAME_H */

