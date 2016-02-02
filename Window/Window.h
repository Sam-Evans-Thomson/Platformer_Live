/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Window.h
 * Author: sam
 *
 * Created on 31 January 2016, 11:56 AM
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

struct ScreenDimensions {
    int w;
    int h;
};
    
    const double DEFAULT_W = 1920.0;
    const double DEFAULT_H = 1080.0;
    const double DEFAULT_RATIO = 1.77777777777;
    
    static const ScreenDimensions DIM_1920_1080 = {1920, 1080};
    static const ScreenDimensions DIM_1680_1050 = {1680, 1050};
    static const ScreenDimensions DIM_1600_900 =  {1600, 900 };
    static const ScreenDimensions DIM_1440_900 =  {1440, 900 };
    static const ScreenDimensions DIM_1366_768 =  {1366, 768 };
    static const ScreenDimensions DIM_1280_1024 = {1280, 1024};
    static const ScreenDimensions DIM_1280_800 =  {1280, 800 };
    static const ScreenDimensions DIM_1024_768 =  {1024, 768 };
    static const ScreenDimensions testDIM =  {400, 800 };
    static const ScreenDimensions testDIM2 =  {1800, 400 };

class Window {
public:
    
    
    Window();
    Window(const Window& orig);
    virtual ~Window();

    bool open();
    void close();
    void render();
    void clearScreen();
    void applyScreenDim(ScreenDimensions scDim);
    
    int getWidth();
    int getHeight();
    SDL_Renderer* getRenderer();
    SDL_Rect* getRenderArea();
    
    SDL_Renderer* createRenderer();
    void handleEvent(SDL_Event &event);
    
    bool hasMouseFocus();
    bool hasKeyboardFocus();
    bool isMinimized();
    
 
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect renderArea;
    const SDL_Rect screenRect = {0,0,1920,1080};
    
    double scale;
    
    int windowW;
    int windowH;
    
    int getScreenWidth();
    int getScreenHeight();
    
    bool mouseFocus;
    bool keyboardFocus;
    bool fullScreen;
    bool minimized;
    
    ScreenDimensions* currDim;

};

#endif /* WINDOW_H */

